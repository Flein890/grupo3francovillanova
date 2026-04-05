#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

float division(int m, int n, int d){
	 if (m < n ){
        if((m== 0) || (d==0)){
            return 0;
        }

       return (m*10,n,d-1)/10.0;
    }
   

   

    
    return 1+ division(m-n,n,d);
}

int main() {
    int m, n;
    float resultado;

    printf("Ingrese el dividendo (m): ");
    scanf("%d", &m);

    printf("Ingrese el divisor (n): ");
    scanf("%d", &n);

    if(n == 0){
        printf("Error: no se puede dividir por cero\n");
        return 1;
    }

    resultado = division(m, n);

    printf("Resultado: %.4f\n", resultado);

    return 0;
}
