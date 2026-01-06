#!/bin/bash
# Test de la commande externe ls

SHELL="$1"

if [ -z "$SHELL" ]; then
    echo "Usage: $0 <simple_shell_binary>"
    exit 1
fi

echo "Test 1: ls dans le répertoire courant"
echo "ls" | $SHELL

echo "Test 2: ls non-existent"
echo "ls /no_such_directory" | $SHELL
