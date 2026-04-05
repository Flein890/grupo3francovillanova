#include "tp_1_recursividad.h"
#include <stdbool.h>
#include <string.h>

float division(int m, int n){
	int d=4;
	 if (m < n ){
        if((m== 0) || (d==0)){
            return 0;
        }

       return (m*10,n,d-1)/10.0;
    }
   

   

    
    return 1+ division(m-n,n);
}
