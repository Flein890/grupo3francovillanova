//Ejercicio 8
/*8.	Definir una función recursiva que dado un conjunto devuelva una lista con los subconjuntos del mismo 
tales que la suma de los elementos de cada subconjunto sumen una cantidad dada.  
Por ejemplo:   Dado el conjunto A = {10, 3, 1, 7, 4, 2}. La lista de los conjuntos que sumen 7 sería: 
R = [{3, 4}, {1, 4, 2}, {7}]*/

// int ** subconjuntosQueSumanN(int conjunto[], int n);
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output);

/*NOTA: Para facilitar la resolución pueden optar por el primer prototipo según el cual la función devuelve un 
arreglo de apuntadores a arreglos de enteros (los subconjuntos), o por el segundo que establece que el tipo 
devuelto es una cadena con el conjunto de subconjuntos, con el formato que consta en la consigna.
Comentar la firma que no se utilice.*/

#include "tp_1_recursividad.h"
#include <stdlib.h>
#include <stdio.h>




int * cargaConjunto (int);
int main (void){
    int tamanio;
    int * miConjunto = cargaConjunto(tamanio);
}

int * cargaConjunto (int n){
 
    printf("Ingresar tamaño del conjunto: \n");
    int esValido = scanf("%d",&n);
   

    while(!esValido){
        printf("VALOR INGRESADO NO VALIDO. Ingresar tamaño del conjunto: \n");
        while(getchar() == '\n');
        esValido = scanf("%d",&n);
    }
    int * conjunto = malloc(sizeof(int) * n);

    int val;
    for(int i = 0;i<n;i++){
        printf("Ingresar numero %d a cargar en el conjunto:",i+1);
        scanf("%d",&val);
        conjunto[i] = val;
    }
    // printf("\n\n");
    // for(int i = 0;i<n;i++){
    //     printf("i->  %d , valor -> %d\n",i,conjunto[i]);
        
    // }
return conjunto;
}

void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output){

};