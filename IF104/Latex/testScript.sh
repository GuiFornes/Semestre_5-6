#!/usr/bin/bash
lscolor()
{
    for x in $@
    do
	if [ -x $x ]
	then
	    echo -ne "\e[92m"
	    echo $x
	    echo -ne "\e[0m"
	fi
    done
    for x in $@
    do
	if [ -d $x ]
	then
	    echo -ne "\e[94m"
	    echo $x
	    echo -ne "\e[0m"
	fi
    done
}     
	
