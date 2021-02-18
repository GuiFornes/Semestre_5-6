#!/bin/bash

path_file=$1
path_file=$(echo $path_file | sed 's/\//\ /g')
path_complete="."
for i in $path_file
do
    path_complete=$path_complete/$i
    if [ -e $path_complete ]
    then
	if [ $path_complete ! -d ]
	then
	    echo "le nom $i existe déjà et n'est pas un dossier"
	    exit 1	    
	fi
    else
	command mkdir $path_complete
    fi
done
exit 0


