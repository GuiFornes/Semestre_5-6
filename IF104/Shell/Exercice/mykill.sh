#!/bin/bash

if [ -z $1 ]
then
    echo "Usage : kill the process in parameter"
else
    kill -9 `pidof $1`
fi

