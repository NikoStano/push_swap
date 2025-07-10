#!/bin/bash

N=20				# nombre de tests
SUM=0
for i in $(seq 1 $N); do
  SEQ=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  C=$(./push_swap $SEQ | wc -l)
  SUM=$((SUM + C))
done
printf "Moyenne sur %d tests : %.2f ops\n" $N "$(echo "$SUM/$N" | bc -l)"
