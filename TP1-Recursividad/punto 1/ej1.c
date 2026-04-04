#include "../Headers/Headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool cadenaValida(char *cad);
void cadenaMinusculas(char *cad);

int main()
{
    char cadena[30];
    bool esValido;

    do{
        printf("Ingresa una palabra para saber si es un palindromo: ");
        
        fgets(cadena,sizeof(cadena),stdin);
        cadena[strcspn(cadena,"\n")] = '\0';  //Elimino el salto de linea

        esValido=cadenaValida(cadena);  //Validacion de datos

        if(esValido){   
            printf("Se ingresaron caracteres invalidos, ingrese otra palabra:\n");
        }
    } 
    while(esValido);
    
    cadenaMinusculas(cadena);  
    

    bool pali=palindromo(cadena);

    printf("%s",pali ? "Verdadero. La palabra es palindormo." : "Falso. La palabra NO es palindromo.");
        
    
return 0;
}

void cadenaMinusculas(char *cad)
{
    int len = strlen(cad);

    for (int i = 0; i < len; i++) {
        if (cad[i] >= 'A' && cad[i] <= 'Z') {
            cad[i] = cad[i] + 32;
        }
    }
}

bool cadenaValida(char *cad)
{
    for (int i = 0; i < strlen(cad); i++){
        if (isalpha(cad[i])){
            return false;
        }
    }
    return true;
}

  
bool esPalindromoRec(char *cad,int inicio,int fin){
	   
    if (inicio >= fin){
        return true;
    }

    if (cad[inicio] != cad[fin]) {
        return false;
    }

    return esPalindromoRec(cad,inicio+1,fin-1);
}

bool palindromo(char *cad) {
    int len = strlen(cad);
    return esPalindromoRec(cad, 0, len - 1);
}