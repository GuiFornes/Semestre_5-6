#!/bin/bash

sum=0
i=1

while [ $# -gt 0 ]
do
    let "a = $1"
    let "b = $sum"
    let "sum += $a"
    echo -e "$b + $a = $sum\n"
    shift
    let "i+=1"
done
