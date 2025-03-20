#!/bin/bash

EXEC="./converter"


TEST_CASES=(
    "0"
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "+inff"
    "-inff"
    "42"
    "-42"
    "a"
    "z"
    "!"
    "127"
    "-128"
    "2147483647"
    "-2147483648"
    "0.0"
    "-0.0"
    "3.14"
    "-3.14"
    "42.0f"
    "-42.0f"
    "12345678901234567890"
    "-99999999999999999999999"
    "42.0f.0"
    "6f"
    "f42"
    "d42"
    "-44444444444444444444444444444.444444444444444444444444"
    "nanffff"
    "+iiinf"
    "-infffff"
    "inf!"
    "!inf"
    "NAN"
    "+INF"
    "+iNF"
    "+332423"
)

echo " Running tests..."
for TEST in "${TEST_CASES[@]}"; do
    echo "----------------------------------"
    echo " [ Testing: ./converter \"$TEST\" ] "
    $EXEC "$TEST"
    echo
done
echo "[DONE]"
