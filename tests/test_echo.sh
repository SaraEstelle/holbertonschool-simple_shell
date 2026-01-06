#!/bin/bash
# Test du builtin echo et commandes simples

SHELL="$1"

if [ -z "$SHELL" ]; then
    echo "Usage: $0 <simple_shell_binary>"
    exit 1
fi

echo "Test 1: echo simple"
echo "echo Hello World" | $SHELL

echo "Test 2: echo avec non-interactif"
echo "echo Test Non-Interactif" | $SHELL
