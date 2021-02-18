#!/bin/sh/env bash
#
# @filename monfichier.sh
# @date lun. 19 oct. 2020 17:09:39 CEST
# @author Prenom Nom <prenom.nom@enseirb-matmeca.fr>
# @brief ...
#

CMD=$( basename $0 )
nbminparams=1

usage()
{
	echo "Usage: $CMD ..."
}

if [ $# -lt $nbminparams ]
then
	usage
	exit 1
fi
