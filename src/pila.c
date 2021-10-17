#include "pila.h"
#include "lista.h"

#define ERROR 0

/**
 * POST:
 * Reserva memoria para una pila_t y lo inicializa en 0. Devuelve un puntero a la 
 * dirección de memoria, o NULL en caso de error.
 */
pila_t* pila_crear(){
    return ((pila_t*)lista_crear());
}

/**
 * POST:
 * Apila un elemento en la pila.
 * Devuelve la pila o NULL en caso de error.
 */
pila_t* pila_apilar(pila_t* pila, void* elemento){
    if(!pila) return NULL;

    return ( (pila_t*)lista_insertar((lista_t*)pila, elemento) );
}



/**
 * POST:
 * Desapila un elemento de la pila y lo devuelve.
 * Devuelve NULL en caso de error.
 */
void* pila_desapilar(pila_t* pila){
    if(!pila) return NULL;

    return (lista_quitar_de_posicion((lista_t*)pila, pila_tamanio(pila)));
}

/**
 * POST:
 * Devuelve el elemento en el tope de la pila o NULL en caso de que no exista.
 */
void* pila_tope(pila_t* pila){
    if(!pila) return NULL;

    return (lista_ultimo((lista_t*)pila));
}

/**
 * POST:
 * Devuelve la cantidad de elementos de la pila o ERROR si no existe.
 */
size_t pila_tamanio(pila_t* pila){
    if(!pila) return ERROR;

    return (lista_tamanio((lista_t*)pila));
}

/**
 * POST:
 * Devuelve true si la pila tiene 0 elementos.
 */
bool pila_vacia(pila_t* pila){
    if(!pila_tamanio(pila)) return true;

    return false;
}


/**
 * POST:
 * Libera la memoria reservada por la pila, si esta existe.
 */
void pila_destruir(pila_t* pila){
    lista_destruir((lista_t*)pila);
}
