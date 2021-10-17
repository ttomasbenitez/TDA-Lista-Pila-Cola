#include "cola.h"
#include "lista.h"

#define ERROR 0

/**
 * POST:
 * Reserva memoria para una cola_t y lo inicializa en 0. Devuelve un puntero a la 
 * dirección de memoria, o NULL en caso de error.
 */
cola_t* cola_crear(){
    return ((cola_t*)lista_crear());
}

/**
 * POST:
 * Encola un elemento en la cola.
 * Devuelve la cola o NULL en caso de error.
 */
cola_t* cola_encolar(cola_t* cola, void* elemento){
    if(!cola) return NULL;
    
    return ( (cola_t*)lista_insertar((lista_t*)cola, elemento) );
}

/**
 * POST:
 * Desencola un elemento de la cola y lo devuelve.
 * Devuelve NULL en caso de error.
 */
void* cola_desencolar(cola_t* cola){
    if(!cola) return NULL;

    size_t inicio_cola = 0;
    return (lista_quitar_de_posicion((lista_t*)cola, inicio_cola));
}

/**
 * POST:
 * Devuelve el elemento en el frente de la cola o NULL en caso de que no exista.
 */
void* cola_frente(cola_t* cola){
    if(!cola) return NULL;

    return (lista_primero((lista_t*)cola));
}

/**
 * POST:
 * Devuelve la cantidad de elementos de la cola o ERROR si no existe.
 */
size_t cola_tamanio(cola_t* cola){
    if(!cola) return ERROR;

    return (lista_tamanio((lista_t*)cola));
}


/**
 * POST:
 * Devuelve true si la cola tiene 0 elementos.
 */
bool cola_vacia(cola_t* cola){
    if(!cola_tamanio(cola)) return true;

    return false;
}

/**
 * POST:
 * Libera la memoria reservada por la cola, si esta existe.
 */
void cola_destruir(cola_t* cola){
    lista_destruir((lista_t*)cola);
}
