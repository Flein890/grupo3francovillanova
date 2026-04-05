#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void auxr(char cadena[], char aux[], int i,int j,int tamaño){
	int faltan;
	if (cadena[i] == '\0' ){
		aux[j]= '\0';
		return;
	}

	
		aux[j] = cadena[i];
		faltan = tamaño-i-1;

		if ((faltan > 0) && (faltan % 3 == 0)){
			aux[j+1] ='.';
			auxr (cadena, aux,  i+1, j+2, tamaño);
		}else
		{
			auxr (cadena, aux,  i+1, j+1, tamaño);
		}


	}

int main() {
    char cadena[50];
    char aux[100];

      printf("Ingrese cadena (maximo 49 caracteres): ");
    scanf("%49s", cadena);

    if (strlen(cadena) == 49) {
        printf("Error: Sobrepaso el numero permitido de caracteres\n");
    }

    if (strlen(cadena) == 0) {
        printf("error: cadena vacia\n");
        return 1;
    }

    if (strlen(cadena) >= sizeof(cadena)) {
        printf("Error: cadena demasiado larga\n");
        return 1;
    }

    auxr(cadena, aux, 0, 0, strlen(cadena));

    printf("Resultado: %s\n", aux);

    return 0;
}
