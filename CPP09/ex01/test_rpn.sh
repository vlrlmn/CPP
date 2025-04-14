#!/bin/bash

BINARY=./RPN

echo -e "\n\033[1;32m[VALID INPUT TESTS]\033[0m"
echo "=============="

# input => expected
tests_valid=(
  '8 9 * 9 - 9 - 9 - 4 - 1 +|42'
  '7 7 * 7 -|42'
  '1 2 * 2 / 2 * 2 4 - +|0'
  '3 4 +|7'
  '9 2 -|7'
  '3 4 5 * +|23'
  '2 3 + 4 *|20'
  '5 1 2 + 4 * + 3 -|14'
  '4 2 /|2'
  '2 3 1 * + 9 -|-4'
  '1 2 2 1 + + -|-4'
)

for case in "${tests_valid[@]}"; do
  input="${case%%|*}"
  expected="${case##*|}"
  actual=$($BINARY "$input")
  printf "Input: %-25s Expected: %-5s Got: %s\n" "\"$input\"" "$expected" "$actual"
done

echo ""
echo -e "\033[1;31m[INVALID INPUT TESTS]\033[0m"
echo "================"

tests_invalid=(
  ""
  "1 2 + 4"
  "8 2 5 / / +"
  "(1 + 1)"
  "82 2 *"
  "5 +"
  "2 3 ^"
  "a b +"
  "4 0 /"
  "1 2"
)

for input in "${tests_invalid[@]}"; do
  output=$($BINARY "$input" 2>&1)
  printf "Input: %-20s Output: %s\n" "\"$input\"" "$output"
done
