#!/bin/bash

sum_size()
{
    sum=0
    ls -l $1 | awk '{ print &5 }'
    for x in $@
    do
	sum = $((sum+x))
    done
    echo taille totale: $somme
}
