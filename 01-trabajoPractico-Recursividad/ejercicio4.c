#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

float division(int m, int n){
    static int d = -1;   
    static int inicial = 1;

    if (inicial != 0){
        do{
            printf("Ingresa un numero del 1 al 10 para indicar la cantidad de decimales que quiere");
            scanf("%d", &d);

            if (d < 1 || d > 10){
                printf("Error: debe estar entre 1 y 10\n");
            }

        } while (d < 1 || d > 10);

        inicial = 0;
    }

    if (m < n){
        if (m == 0 || d == 0){
            inicial = 1;   
            return 0;
        }
        d--;
        return division(m * 10, n) / 10.0;
    }

    return 1 + division(m - n, n);
}

int main() {
    int m, n;
    float resultado;
	
    printf("Ingrese el dividendo (m): ");
    if (scanf("%d", &m) != 1) {
        printf("Error: tiene que ingresar un numero\n");
        return 1;
    }

    printf("Ingrese el divisor (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Error: tiene ingresar un numero\n");
        return 1;
    }

    if (n == 0){
        printf("Error: no se puede dividir por cero\n");
        return 1;
    }

    resultado = division(m, n);

    printf("Resultado: %f\n", resultado);

    return 0;
}
