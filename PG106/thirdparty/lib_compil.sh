#!/usr/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage : need 'dynamique' or 'statique' in param"
fi

export LD_LIBRARY_PATH='1'

if [ $1 == "dynamique" ]
then
    gcc -fpic -shared -o libhashdyn.so hash.c
    gcc hash_test.c -L. libhashdyn.so -o hash -g -O0
fi

if [ $1 == "statique" ]
then
    gcc -c hash.c -g
    ar rcs libhashstat.a hash.o hash.h
    gcc hash_test.c libhashstat.a -o hash -g -O0
fi
