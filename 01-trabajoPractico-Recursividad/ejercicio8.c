	#include <stdio.h>
	#include <stdlib.h>
	#include "tp_1_recursividad.h"
	#define max_elementos 20 //defino un maximo en el que la funcion va a trabajar
	#define max_resultados (1<<max_elementos) // defino un maximo de resultados (2^n resultados)

	//Prototipos de funciones
	int ** subconjuntosQueSumanN(int conjunto[],int n);
	int ** Aux_subconjuntosQueSumanN(int conjunto[],int n, int suma, int indice, int **resultados, int subconjunto_act[],int tamano_sub_conjunto,int *cant_resultados);

	//Funcion principal
	int ** subconjuntosQueSumanN(int conjunto[],int n){
		int suma=0;
		int subconjunto_act[max_elementos]={0};
		int tamano_sub_conjunto=0;	
		int **resultados= malloc (max_resultados*sizeof(int *)); //Declaro resultados y reservo x numero de memoria para max numero de punteros 
		for (int i = 0; i < max_resultados; i++){
		resultados[i] = NULL; //inicializo todo puntero en NULL
	}
		int cant_resultados=0;
		Aux_subconjuntosQueSumanN(conjunto,n,suma,max_elementos-1 ,resultados,subconjunto_act,tamano_sub_conjunto,&cant_resultados);
		return resultados;
	}
	// funcion recursiva auxiliar
	int ** Aux_subconjuntosQueSumanN(int conjunto[],int n, int suma, int indice, int **resultados, int subconjunto_act[],int tamano_sub_conjunto,int *cant_resultados){
		if (indice<0){
			return resultados; //corte de rama y backtrack al llegar al indice negativo 
		}
		if (conjunto[indice]==0){
			return Aux_subconjuntosQueSumanN(conjunto,n,suma,indice-1,resultados,subconjunto_act,tamano_sub_conjunto,cant_resultados); // si dicho elemento del conjunto es 0 lo ignora y sigue normalmente con la recursion
			} 
		if (suma==n){
			resultados[*cant_resultados]= malloc((tamano_sub_conjunto + 1)* sizeof(int)); //Reservo memoria para el tamaño del vector tamano_sub_conjunto + un extra (un -1 que va a dictar cuando dejar de imprimir en el MAIN)
			for (int i=0; i<tamano_sub_conjunto; i++){
				resultados[*cant_resultados][i]=subconjunto_act[i];
			}
		resultados[*cant_resultados][tamano_sub_conjunto]= -1;
		(*cant_resultados)++;
		return resultados;	
		}
		if (suma>n){
			return resultados; //Corte y backtrack si suma supera N
		}
		if (suma<n){
			subconjunto_act[tamano_sub_conjunto]=conjunto[indice];
			Aux_subconjuntosQueSumanN(conjunto,n,suma+subconjunto_act[tamano_sub_conjunto],indice-1,resultados,subconjunto_act,tamano_sub_conjunto+1, cant_resultados); //Rama recursiva incluyendo el numero actual
			Aux_subconjuntosQueSumanN(conjunto,n,suma,indice-1,resultados,subconjunto_act,tamano_sub_conjunto, cant_resultados); //Rama recursiva excluyendo el numero actual
		}
		return resultados;
	}


	int main(){
		int input=0;
		int i=0;
		int conjunto[max_elementos]={0};
		printf ("A continuacion ingrese cada valor del conjunto de elementos (-1 deja de agregar)\n");
		while (input!=-1 && i<max_elementos){
			printf("Valor N%d\n",i);
			while (scanf ("%d",&input)!=1){
				printf ("Input invalido, debe ingresar un numero entero\n");
				printf ("Ingrese un numero entero\n");
				while (getchar() != '\n');
			}
			conjunto[i]=input;
			if (input==-1){
				conjunto[i]=0;
			}
			i++;
		}
		int n=0;
		printf ("Ingrese el numero N que desea que sumen los subconjuntos\n");
		scanf ("%d",&n);
		int **resultados= subconjuntosQueSumanN(conjunto, n);
		for (int i=0; i<max_resultados;i++){
			if (resultados[i]!=NULL){
			printf ("{ ");
			for (int j=0; j<max_elementos && resultados[i][j]!=-1;j++){
						printf("%d ",resultados[i][j]);
				}
			printf ("}\n");
			}
		}
		return 0;
}
			
