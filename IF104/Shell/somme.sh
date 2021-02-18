function somme
{
    S=0
    for i in $*
    do
        S=$(( $S+ $i ))
    done
    echo $S
}
somme
	     
