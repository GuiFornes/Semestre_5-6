#!/bin/bash

Mkdir()
{
    path=$1
    for i in $path
    do
	if [ -e $i ]
	then
	    cd $i
	else
	    mkdir $i
	    cd $i
	fi
    done
    pwd
}

