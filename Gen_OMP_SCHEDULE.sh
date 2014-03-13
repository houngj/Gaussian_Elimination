#!/bin/bash

#$1 is the type of scheduling, $2 is the one dimentional size of the problem, $3 is the number of threads.
export OMP_SCHEDULE="$1, `expr $2 / $3`"
