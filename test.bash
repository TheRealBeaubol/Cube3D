#!/bin/bash

# Définition des couleurs
GREEN="\033[1;32m"
CYAN="\033[1;36m"
RED="\033[1;31m"
NC="\033[0m" # No Color

# Dossier contenant les maps
MAP_DIR="invalid_maps"
# Fichier de log
LOG_FILE="valgrind_output.log"

# On vide le fichier de log existant (si nécessaire)
> "$LOG_FILE"

# Options pour Valgrind
VALGRIND_OPTIONS="--leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --suppressions=lib/MacroLibX/valgrind.supp"

# Compteur de map
count=1

# Boucle sur chaque fichier .map dans le dossier invalid_maps
for map in "$MAP_DIR"/*; do
    MAP_NAME=$(basename "$map")

    # Affichage dans le terminal
    echo -e "${CYAN}--$ ${MAP_NAME} $----------------------------------------${NC}"
    
    # Ajout de la séparation et du nom de la map dans le fichier log
    echo -e "--$ ${MAP_NAME} $----------------------------------------" >> "$LOG_FILE"
    
    TEMP_FILE=$(mktemp)
    valgrind $VALGRIND_OPTIONS ./cub3D "$map" > "$TEMP_FILE" 2>&1

    # Filtrage des informations importantes et les ajouter au fichier log
    # Erreurs du programme
    grep -E "Error" "$TEMP_FILE" | sed 's/\x1b\[1;31m//g' >> "$LOG_FILE" 

    # Descripteurs de fichiers ouverts
    grep -E "==[0-9]+==" "$TEMP_FILE" >> "$LOG_FILE"

    # 
    # Suppression du fichier temporaire
    rm "$TEMP_FILE"
    
    # Vérification du succès ou de l'échec de l'exécution
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Success: ${MAP_NAME}${NC}"
    else
        echo -e "${RED}Error: ${MAP_NAME}${NC}"
    fi
    
    # Incrémentation du compteur
    ((count++))
done

# Message de fin
echo -e "${CYAN}Test terminé. Voir les résultats dans ${LOG_FILE}.${NC}"
