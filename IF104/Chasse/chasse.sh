#!/bin/bash
#
# @filename chasse.sh
# @date mer. 13 janv. 2021 10:03:23 CET
# @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
#

base=CarnetsDeVoyage

filtrage(){
	for x in `ls $base`
	do
		if [[ $x == 19[7-9]?[-_][A-Z]* ]];then
			echo $x
		fi
	done
}


identify_rep(){
	max=0
	rep=rien
	for x in $@
	do
		if [ -d $base/$x ];then
			echo $x
			du -s $base/$x|awk '{print $1}'
			if [ $(du -s $base/$x|awk '{print $1}') -gt $max ];then
				rep=$x
				max=$(($( du -s $base/$x|awk '{print $1}' )))
			fi
				 
		fi
	done
	echo $rep
	echo $max
}

identify_rep $( filtrage )
