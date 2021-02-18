#!/bin/bash
chemin=(echo $PATH | tr ':' ' '))
for i in $(ls /bin)
do
    if [ -e $x/$1 -a -x $x/$1 ]
    then
	echo "$x/$1"
	exit 0
    fi
done
echo elle n\'existe pas
exit 1
