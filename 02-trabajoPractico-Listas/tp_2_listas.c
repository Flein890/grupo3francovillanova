#include "tp_2_listas.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libs/validaciones/headers/tp_validaciones.h"

/*
    Modificado por ultima vez 30/04 - Federico
*/ 

//-----------------------------------------------------------------
//----------------------------Ejercicio 2--------------------------
//-----------------------------------------------------------------

Lista verElementosRepetidos(Lista l1, Lista l2)
{
    Lista rest = l_crear();
    Iterador i_l1 = iterador(l1);

    while (hay_siguiente(i_l1)) 
    {
        TipoElemento te = siguiente(i_l1);
        if(l_buscar(l2, te->clave) != NULL)
        {
            l_agregar(rest, te);
        }
    }
    free(i_l1);
    return rest;
}

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2)
{
    Lista rest = l_crear();
    Iterador i_l1 = iterador(l1);

    while (hay_siguiente(i_l1)) 
    {
        TipoElemento te = siguiente(i_l1);
        if(l_buscar(l2, te->clave) == NULL)
        {
            l_agregar(rest, te);
        }
    }
    free(i_l1);
    return rest;
}

float promedio(Lista l1)
{
    Iterador i_l1 = iterador(l1);
    int acum = 0;
    int max = l_longitud(l1);
    while(hay_siguiente(i_l1))
    {
        TipoElemento te = siguiente(i_l1);
        acum += te->clave;
    }
    float rest = (float)acum/max;
    free(i_l1);
    return rest;
}

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2)
{
    Iterador i_l1 = iterador(l1);
    Iterador i_l2 = iterador(l2);
    ResultadoValorMinimo rest;
    int pos = 1;

    if(!l_es_vacia(l1)){rest.valor = l_recuperar(l1,1)->clave; rest.pos = 1;}
    if(!l_es_vacia(l2)){rest.valor_2 = l_recuperar(l2, 1)->clave; rest.pos_2 = 1;}

    while(hay_siguiente(i_l1))
    {   
        TipoElemento te = siguiente(i_l1);
        if((te->clave) < rest.valor)
        {
            rest.valor = te->clave;
            rest.pos = pos;
        }
        pos++;
    }

    pos = 1;
    while(hay_siguiente(i_l2))
    {   
        TipoElemento te2 = siguiente(i_l2);
        if((te2->clave) < rest.valor_2)
        {
            rest.valor_2 = te2->clave;
            rest.pos_2 = pos;
        }
        pos++;
    }
    free(i_l1);
    free(i_l2);
    return rest;
}

//-----------------------------------------------------------------
//----------------------------Ejercicio 3--------------------------
//-----------------------------------------------------------------

ResultadosMul multiplo(Lista l1, Lista l2){
    int resto = 0;
    int escalar = 0;
    ResultadosMul resultado;
    TipoElemento te1 = te_crear(0);
    TipoElemento te2 = te_crear(0);
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    te1 = siguiente(ite1);
    te2 = siguiente(ite2);

    int auxEscalar = te2->clave / te1->clave;
    resultado.esMultiplo = true;
    resultado.escalar = true;

    while(hay_siguiente(ite1) && hay_siguiente(ite2)){
        resto = te2->clave % te1->clave;
        if(resto != 0){
            resultado.esMultiplo = false;
            resultado.escalar = false;
            resultado.numEscalar = 0;
            break;
        }
        escalar = te2->clave / te1->clave;
        if(escalar != auxEscalar && resultado.escalar == true){
            resultado.escalar = false;
            resultado.numEscalar = 0;
        }
        te1 = siguiente(ite1);
        te2 = siguiente(ite2);
    }

    resto = te2->clave % te1->clave; // Ejecuto de nuevo para el ultimo elemento
    if(resto != 0){
        resultado.esMultiplo = false;
        resultado.escalar = false;
        resultado.numEscalar = 0;
    }

    if(resultado.escalar == true){
        resultado.numEscalar = escalar;
    }

    return resultado;
}

//-----------------------------------------------------------------
//----------------------------Ejercicio 4--------------------------
//-----------------------------------------------------------------

int CompararListas(Lista l1, Lista L2)
{
    int mayorl1 = 0, 
    iguales = 0, 
    mayorl2 = 0;
    Iterador i_l1 = iterador(l1);
    Iterador i_l2 = iterador(L2);
    while(hay_siguiente(i_l1) && hay_siguiente(i_l2))
    {
        TipoElemento te1 = siguiente(i_l1);
        TipoElemento te2 = siguiente(i_l2);
        if(te1->clave > te2->clave) mayorl1++;
        else if(te2->clave > te1->clave)mayorl2++;
        else iguales++;
    }
    free(i_l1);
    free(i_l2);
    if(mayorl1 > mayorl2) return 1;
    else if(mayorl2 > mayorl1) return 2;
    else return 0;
}

//-----------------------------------------------------------------
//----------------------------Ejercicio 5--------------------------
//-----------------------------------------------------------------
    void hacerPolinomio(Lista list)
    {
        int input;
        int c;
        int grado;
        double valor;
        bool sigue;
        bool cargado;

        do
        {
            printf("\033[2J\033[H");
            if(cargado) printf("\n[ERROR]: Atencion, ya existe un coeficiente con ese grado (%d), ingrese otro. [ERROR]\n", grado);
            printf("\n[>>]: Por favor, ingrese un grado para un coeficiente.\n");
            cargado = false;
            sigue = IngresarEntero(SIGNO_POSITIVO, true, &grado);
            if((l_buscar(list, grado) != NULL)){cargado = true;}
            if(sigue && cargado == false)
            {
                printf("\n\n[>>]: Por favor, ingrese un coeficiente para el grado %d.\n", grado);
                IngresarDecimal(SIGNO_NO_IMPORTA, false, &valor);
                TipoElemento te = te_crear_con_valor(grado, malloc(sizeof(float)));
                *((float*)te->valor) = (float)valor;
                if(!l_agregar(list, te)) printf("[ERROR] No se pudo ingresar el elemento. [ERROR]\n");
            }
        } while (sigue && !l_es_llena(list));
        

    }
		float evaluarPoliomio(Lista list, float x){
			float resultado=0;
			int grado;
			float coeficiente;
			Iterador it= iterador(list);
			while (hay_siguiente(it)){
				TipoElemento elemento= siguiente(it);
				grado= elemento->clave;
				coeficiente= *(float*) elemento->valor;
				resultado+= coeficiente * (pow(x,grado)); //Coeficiente * (x**grado)
			}
			return resultado;
		}
		
		Lista calcularRango(Lista list, double x, double y, double sumando){
			int indice=0;
			Lista resultado= l_crear();
			if (sumando <=0){
					return resultado; // Evito bucle infinito (I+0=I, por lo tanto i nunca llega a i<=y)
					}
			for (double i=x;i<=y; i+=sumando){
				float val= evaluarPoliomio(list,i);
				float *p= malloc(sizeof(float));
				*p=val;
				TipoElemento elemento= te_crear_con_valor(indice,p);
				l_agregar(resultado,elemento);	
				indice++;
			}
			return resultado;
		}

//-----------------------------------------------------------------
//----------------------------Ejercicio 6--------------------------
//-----------------------------------------------------------------


bool esSublista(Lista l1,Lista l2){
    TipoElemento X;
    TipoElemento buscar;
    Iterador i = iterador(l2);
    
    if(l_longitud(l2) > l_longitud(l1)){
        return false;
    }
    
    while(hay_siguiente(i))
    {
        
        X = siguiente(i);
        buscar = l_buscar(l1,X->clave);
        
       if(buscar == NULL)
       {
           
           return false;
           
       }
        
    }
    
    return true;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
