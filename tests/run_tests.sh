#!/bin/bash
# Script principal pour lancer tous les tests

SHELL_BINARY="../simple_shell"  # chemin vers le binaire compilé

if [ ! -f $SHELL_BINARY ]; then
    echo "Erreur : simple_shell non compilé. Compile d'abord avec src/*.c"
    exit 1
fi

echo "===== Test Echo ====="
bash test_echo.sh $SHELL_BINARY

echo "===== Test LS ====="
bash test_ls.sh $SHELL_BINARY

echo "Tous les tests terminés."
