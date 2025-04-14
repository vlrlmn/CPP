#!/bin/bash

BINARY=./PmergeMe
SEP="============================================================"

echo -e "\033[1;31m[INVALID INPUT TESTS]\033[0m"
echo $SEP

# Negative number
echo -e "\033[1;36mTest: Negative number\033[0m"
$BINARY 1 2 -3 4
echo $SEP

# Non-integer value
echo -e "\033[1;36mTest: Non-integer (letter)\033[0m"
$BINARY 1 a 3
echo $SEP

# Empty input
echo -e "\033[1;36mTest: No arguments\033[0m"
$BINARY
echo $SEP

# Too large number
echo -e "\033[1;36mTest: Out of int range\033[0m"
$BINARY 1 2147483648 2
echo $SEP

echo -e "\n\033[1;32m[VALID INPUT TESTS]\033[0m"
echo $SEP

# One element
echo -e "\033[1;36mTest: One element\033[0m"
$BINARY 42
echo $SEP

# Already sorted
echo -e "\033[1;36mTest: Already sorted\033[0m"
$BINARY 1 2 3 4 5
echo $SEP

# Reverse sorted
echo -e "\033[1;36mTest: Reverse sorted\033[0m"
$BINARY 5 4 3 2 1
echo $SEP

# Mixed with duplicates
echo -e "\033[1;36mTest: Mixed with duplicates\033[0m"
$BINARY 3 1 4 8 9 4 8 1 4 1
echo $SEP

# All the same value
echo -e "\033[1;36mTest: All same values\033[0m"
$BINARY 7 7 7 7 7
echo $SEP

# Even number of elements
echo -e "\033[1;36mTest: Even number of elements\033[0m"
$BINARY 4 2 6 8
echo $SEP

# Odd number of elements
echo -e "\033[1;36mTest: Odd number of elements\033[0m"
$BINARY 3 1 4 8 9
echo $SEP

# Test with 100 random values (only if jot installed)
if command -v jot &> /dev/null; then
    echo -e "\033[1;36mTest: 100 random values (jot)\033[0m"
    $BINARY $(jot -r 100 1 100)
    echo $SEP
else
    echo -e "\033[1;31mSkipping large test: 'jot' not found\033[0m"
fi


# Large test with random values (only if jot installed)
if command -v jot &> /dev/null; then
    echo -e "\033[1;36mTest: 3000 random values (jot)\033[0m"
    $BINARY $(jot -r 3000 1 100000)
    echo $SEP
else
    echo -e "\033[1;31mSkipping large test: 'jot' not found\033[0m"
fi
