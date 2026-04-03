#include "../Headers/Headers.h"

int main() {
  
}
  
bool palindromo(char *cad,int inicio,int fin){}
	    int n = strlen(cadena);
    if (n<=1){
        return true;
    }

    if (cadena[0] != cadena[n-1]) {
        return false;
    }

    char sub[100];

    for (int i = 0; i < n-2;i++){
        sub [i] =cadena[i+1];
    }
    sub[n-2]= '\0';

    return palindromo(sub);
}
