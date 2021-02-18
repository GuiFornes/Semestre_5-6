#!/bin/bash
#
# @filename skeleton.sh
# @date $d
# @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
#
d=`date`
CMD=$( basename $0 )
nbminparams=2

usage()
{
	echo "Usage: $CMD needs 2 params, the name of file, and the type. exemple : $CMD test tex"
}

if [ $# -lt $nbminparams ]
then
	usage
	exit 1
fi

filename=$1
typefile=$2
case $typefile in
    "tex")
        echo "%%
%% @filename $filename.$typefile
%% @date $d
%% @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
%%
\documentclass[a4paper, draft]{article}

\usepackage[utf8]{inputenc}
\usepackage[french]{babel} 

% Figures
\usepackage{graphicx}
\graphicspath{{./img/}}

% Math
\usepackage{amsmath, amssymb}
\newtheorem{defi}{Définition}

% Algortihmes
\usepackage[vlined,lined,linesnumbered,boxed,french]{algorithm2e}
\DeclareMathOperator*{\argmin}{argmin}
\DeclareMathOperator{\myfunc}{myfunc}
\DeclareMathOperator*{\sign}{sign}
\DeclareMathOperator*{\imwh}{width}
\DeclareMathOperator*{\imht}{height}

% Extra
\usepackage[left=3cm,right=3cm,top=2cm,bottom=2cm]{geometry}
\usepackage{url}

\begin{document}


\end{document}" >$filename.$typefile
        ;;
    "sh")
        echo '#!/bin/sh/env bash
#
# @filename '"$filename.$typefile"'
# @date '"$d"'
# @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
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
fi' >$filename.$typefile
        ;;
    "c")
        echo "/**
 *
 * @filename $filename.c
 * @date 2019-10-18 15:13
 * @author Guillaume Fornes <guillaume.fornes@enseirb-matmeca.fr>
 *
 */
#include <stdlib.h>
#include <stdio.h>

#define _NB_MIN_PARAMS_ 1

void print_usage( char *argv[] ) {
	fprintf( stderr, "Usage: %s ....\n", argv[0] );
	return;
}

int main( int argc, char *argv[] )
{
	if ( argc < _NB_MIN_PARAMS_ ) {
		print_usage( argv );
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}" >$filename.$typefile
        ;;
    *)
        echo UNKNOWN TYPE
        exit 1
        ;;
esac

emacs $filename.$typefile &
    
