#!/bin/sh
#-S -c -g -Wa,-a,-ad
gcc $1 $2 $3 $4 $5 `pwd`/../src/sorting.c `pwd`/../src/quicksort.c `pwd`/../src/heapsort.c `pwd`/../src/selectionsort.c `pwd`/../src/utilities.c `pwd`/../src/mergesort.c
