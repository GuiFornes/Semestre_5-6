#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int set_bit(int n, int bit_index, int value)
{
    int c = 1;
    if(bit_index = 0)
      c = 0;
    else {
      for(int i = 1 ; i <= bit_index ; i++){
	c *= 10;
      }
    }
    if(value==1){
      n = n | c;
      return n;
    }
    n = n ^ c;
    return n;
}

int main(int argc, char * argv[])
{
  if(argc!=4){
    printf("Usage : il faut 3 entier en argument");
    return 0;
  }
  int n = atoi(argv[1]);
  int bit_index = atoi(argv[2]);
  int value = atoi(argv[3]);
  printf("%d\n", n);
  set_bit(n, bit_index, value);
  printf("%d\n", n);
  return 0;
}
	



  
/*
 *  Écrire une fonction set_bit, permettant de faire passer à 0 ou 1 un bit indiqué au sein d'un nombre
 *
 *  PROTOTYPE : int set_bit(int n, int bit_index, int value)
 *
 *  PARAMETRES : - n : un entier
 *               - bit_index : un entier compris entre 0 et 8 * sizeof(int) - 1
 *               - value : un entier qui vaut 0 ou 1
 *
 *  SORTIE : Un nombre correspondant au fait de donner la valeur value au bit de n situé à l'indice bit_index
 *          (L'indice 0 correspond au bit de poids faible, l'indice 8 * sizeof(int) - 1 au bit du poids fort)
 *
 *  EXEMPLE : set_bit(2, 0, 1) renvoie 3 car 2 se lit en binaire '10' et 3 se lit '11' (le premier bit de 2 est passé à 1)
 *            set_bit(2, 0, 0) renvoie 2 car ça ne change pas le premier bit de 2 déjà égal à zéro
 *            set_bit(2, 1, 0) renvoie 0 car cela met à zero le deuxième bit de 2
 *            set_bit(2, 2, 1) renvoie 6 car 6 se lit en binaire '110' (le troisième bit de 2 est passé à 1)
 */


/*
 * Écrire un main qui récupère 3 entiers (n, bit_index, et value) de la ligne de commande,
 * et qui affiche la valeur de n en décimal et en hexadecimal,
 * puis qui affiche le résultat de l'appel de set_bit en décimal et en hexadecimal
 */


/*
 * BONUS
 *
 * On aurait aimé que la fonction set_bit puisse modifier l'entier qui lui est passé en paramètre,
 * et renvoyer une erreur en cas de mauvais argument. Écrire une fonction change_bit qui permette
 * de faire cela. Modifiez le main pour qu'elle soit aussi appelée.
 *
 * VOUS POUVEZ FAIRE COME VOULEZ, mais voici une proposition de réponse qui peut vous faire utiliser
 * ce qu'on a vu recemment (pointeur, enum et switch):
 *
 *   - Créer une enum bit_value composée de BIT_OFF (valant 0) et BIT_ON (valant 1)
 *   - Créer une enum error_code composée de CODE_SUCCESS (valant 0) et CODE_FAILURE (valant 1)
 *
 *   - Faire la fonction change_bit:
 *
 *         PROTOTYPE : enum error_code change_bit(int * n_ptr, unsigned int bit_index, enum bit_value value)
 *
 *         PARAMETRES: - n_ptr : un pointeur (différent de NULL) vers l'entier à modifier
 *                     - bit_index : un entier (non signé donc toujours positif) compris entre 0 et 8 * sizeof(int) - 1
 *                     - value : un entier de type enum qui vaut BIT_OFF ou BIT_ON
 *
 *         SORTIE: CODE_FAILURE si un des arguments est invalide (dans ce cas l'entier pointé par n_ptr n'est pas modifié),
 *                 CODE_SUCCESS en cas de succès
 */
