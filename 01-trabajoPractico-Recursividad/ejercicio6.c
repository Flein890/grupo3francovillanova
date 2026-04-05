#include "tp_1_recursividad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ondaDigital(char seniales[]);
void convertir(char *cadena, char seniales[]); 
void cadenaMinusculas(char *cad);
bool cadenaValida(char *cad);

int main (void){

    int tamanio;
    printf("Ingrese el tamanio de la onda a cargar (int):  \n");
    int valido = scanf("%d", &tamanio);

    while (valido != 1 || tamanio <= 0) {
        printf("TAMANIO INVALIDO: Ingrese un entero > 0: ");

        while (getchar() != '\n'); // limpiar buffer
        valido = scanf("%d", &tamanio);
    }

    fflush(stdin);

    char * seniales = (char *)malloc((sizeof(char) * tamanio )+ 1 );
    printf("ingrese una onda de seniales (h/l): \n");
    fgets(seniales,(sizeof(char) * tamanio) +1,stdin);
    fflush(stdin);

    bool cadenaValid = cadenaValida(seniales);

    while(!cadenaValid){
        printf("ingrese una onda de seniales valida (h/l): \n");
        fgets(seniales,sizeof(char) * tamanio,stdin);
        fflush(stdin);
        cadenaValid = cadenaValida(seniales);
    }

    printf("%s\n",seniales);
    char * micad = ondaDigital(seniales);
    printf("%s\n",micad);
   

    return 0;
}

char * ondaDigital(char seniales[]){
    
    int tam = (strlen(seniales) + 1);
    char * res =(char*) malloc((2*tam)+1);

    
    convertir(res,seniales);
    
    return res;

};

void convertir(char *cadena, char seniales[]){
    //si tengo una L = _   si tengo una H = -     construccion recursiva -> funcion convertir
    
    if(*seniales == '\0'){ //caso base
        *cadena = '\0';
        return;
    }
   
    if(*seniales == 'h'){

       *cadena = '-';              //ambos condicionales son equivalentes en su interior
                                     // solo que el segundo usa un puntero auxiliar
    } else if(*seniales == 'l'){   //el primero no lo usa porque en la recursion ya estoy apuntando al sig
        char * p = cadena;
        *p = '_';
        p++;
    }

    if(*seniales != *(seniales+1) && *(seniales+1) != '\0'){
        cadena++;   
        *cadena = '|';
    
   }

    return convertir(cadena+1,seniales+1);

}; 
   

bool cadenaValida(char *cad){
    bool esValido = 1; //true
    cadenaMinusculas(cad);
    int tam = strlen(cad);
    for(int i= 0;i<tam;i++){
        if(cad[i] != 'l' && cad[i] != 'h'){
            esValido = false;
        }
    }
return esValido;

}

void cadenaMinusculas(char *cad){
    int tam = strlen(cad);
    for(int i = 0;i<tam;i++){
        if(cad[i] >= 'A' && cad[i] <= 'Z'){
        cad[i] = i[cad] + 32;// *(cad + i) 
        }
    }
};