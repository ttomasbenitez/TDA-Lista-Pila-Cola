#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2mm.h"

void Lista_Se_Crea_y_Se_Inicializa_Correctamente(){
  lista_t* lista = lista_crear();
  
  pa2m_afirmar((lista->nodo_inicio) == NULL, "Al crear lista, nodo inicio es NULL");
  pa2m_afirmar((lista->cantidad) == 0, "Al crear lista, cantidad inicial es 0");
  pa2m_afirmar((lista->nodo_fin) == NULL, "Al crear lista, nodo fin es NULL");
  
  lista_destruir(lista);
}

void Puedo_Insertar_y_Quitar_Elementos(){
  lista_t* lista = lista_crear();
  char a='a', b='b', c='c', d='d', e='e', f='f';


  //    --------------------LISTA ESTÁ VACÍA--------------------

  int vacia = lista_vacia(lista);
  pa2m_afirmar(vacia != 0, "No agrego nada, lista está vacía");
  

  //    --------------------INSERTAR ELEMENTO en la ÚLTIMA POSICIÓN--------------------
  //    --------------------LISTA YA NO ESTÁ VACÍA--------------------
  lista_insertar(lista, &a);
  vacia = lista_vacia(lista);
  
  pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "Se insertó un elemento correctamente");
  pa2m_afirmar(vacia == 0, "Lista ya NO está vacía");

  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  
  pa2m_afirmar((lista->nodo_inicio->siguiente->elemento) == &b, "Se insertaron 2 elementos correctamente");
  pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->elemento) == &c, "Se insertaron 3 elementos correctamente");
  pa2m_afirmar((lista->nodo_fin->elemento) == &c, "El último elemento es el correcto");
  


  //    --------------------INSERTAR ELEMENTO en POSICIÓN--------------------
  lista_insertar_en_posicion(lista, &d, 50);
  pa2m_afirmar((lista->nodo_fin->elemento) == &d, "Agregar elemento en posición que no existe, agrega elemento en la última posición");

  lista_insertar_en_posicion(lista, &e, 0);
  pa2m_afirmar((lista->nodo_inicio->elemento) == &e, "Agregar elemento en posición cero, agrega elemento en la primera posición");
  pa2m_afirmar((lista->nodo_inicio->siguiente->elemento) == &a, "Al agregar elemento en posición cero, se desplazan correctamente los demás elementos");

  lista_insertar_en_posicion(lista, &f, 2);
  pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->elemento) == &f, "Agregar elemento en posición dos, agrega elemento en la posición dos");
  pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->siguiente->elemento) == &b, "Al agregar elemento en posición dos, se desplazan correctamente los demás elementos");


  //    --------------------QUITAR ÚLTIMO ELEMENTO--------------------
  char* elemento_quitado = lista_quitar(lista);
  
  pa2m_afirmar((*elemento_quitado) == d, "Se quitó y devolvió correctamente el último elemento");
  pa2m_afirmar((lista->nodo_fin->elemento) == &c, "El nuevo último elemento es correcto");



  //    --------------------QUITAR ELEMENTO de POSICIÓN--------------------
  elemento_quitado = lista_quitar_de_posicion(lista, 50);
  
  pa2m_afirmar((*elemento_quitado) == c, "Eliminar elemento de posición que no existe, elimina el elemento en la última posición");
  pa2m_afirmar((lista->nodo_fin->elemento) == &b, "El nuevo elemento en la última posición es correcto");

  
  elemento_quitado = lista_quitar_de_posicion(lista, 0);
  
  pa2m_afirmar((elemento_quitado) == &e, "Eliminar elemento en posición cero, elimina el elemento en la primera posición");
  pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "El nuevo elemento en la primera posición es correcto");
  

  elemento_quitado = lista_quitar_de_posicion(lista, 2);
  
  pa2m_afirmar((elemento_quitado) == &b, "Eliminar elemento en posición dos, elimina el elemento en la posición dos");
  pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente) == NULL, "Posición dos era el último elemento");
  pa2m_afirmar((lista->nodo_fin->elemento) == &f, "El nuevo último elemento es correcto y está en la posición uno");
  
  lista_destruir(lista);
}

void Puedo_Saber_el_Tamanio_de_Lista_y_Buscar_Elementos(){
  lista_t* lista = lista_crear();
  char a='a', b='b', c='c', d='d', e='e', f='f';
  
  //    --------------------TAMAÑO de la LISTA--------------------


  size_t tamanio = lista_tamanio(lista);
  pa2m_afirmar((lista->cantidad) == tamanio, "Si lista está vacía, tamaño es 0");

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);
  lista_insertar(lista, &e);
  lista_insertar(lista, &f);

  tamanio = lista_tamanio(lista);
  pa2m_afirmar((lista->cantidad) == tamanio, "Si inserto 6 elementos, tamaño es 6");

  lista_quitar(lista);
  lista_quitar_de_posicion(lista, 2);

  tamanio = lista_tamanio(lista);
  pa2m_afirmar((lista->cantidad) == tamanio, "Si quito 2 elementos, tamaño ahora es 4");

  //    --------------------BUSCAR ELEMENTOS en los BORDES de la LISTA--------------------


  char* primer_elemento = lista_primero(lista);
  pa2m_afirmar((lista->nodo_inicio->elemento) == primer_elemento, "Al buscar el primer elemento, lo devuelve correctamente");

  char* ultimo_elemento = lista_ultimo(lista);
  pa2m_afirmar((lista->nodo_fin->elemento) == ultimo_elemento, "Al buscar el último elemento, lo devuelve correctamente");


  //    --------------------BUSCAR ELEMENTOS en POSICIONES ALEATORIAS--------------------

  char* elemento_en_posicion = lista_elemento_en_posicion(lista, 0);
  pa2m_afirmar((lista->nodo_inicio->elemento) == elemento_en_posicion, "Busco elemento en posición cero, devuelve el primer elemento");

  elemento_en_posicion = lista_elemento_en_posicion(lista, 2);
  pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->elemento) == elemento_en_posicion, "Busco elemento en posición dos, devuelve el tercer elemento");

  elemento_en_posicion = lista_elemento_en_posicion(lista, 50);
  pa2m_afirmar(NULL == elemento_en_posicion, "Busco elemento en posición inexistente, devuelve NULL");


  lista_destruir(lista);
}

void Iterador_Externo_Itera_Correctamente(){
  lista_t* lista = lista_crear();
  char a='a', b='b', c='c', d='d', e='e', f='f';
  
  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);
  lista_insertar(lista, &e);
  lista_insertar(lista, &f);

  printf("Si iterador empieza en el primer elemento:\n");

  char* elemento_actual;
  int iteraciones = 0; 
  lista_iterador_t* iterador = NULL;
  for(iterador = lista_iterador_crear(lista); lista_iterador_tiene_siguiente(iterador); lista_iterador_avanzar(iterador)){
    if(iteraciones == 0){
      elemento_actual = lista_iterador_elemento_actual(iterador);
      pa2m_afirmar((lista->nodo_inicio->elemento) == elemento_actual, "El elemento en la posición inicial del iterador, es el primer elemento de la lista");
    }
    else if(iteraciones == 2){
      elemento_actual = lista_iterador_elemento_actual(iterador);
      pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->elemento) == elemento_actual, "El elemento del iterador en la segunda iteración, es el tercer elemento de la lista");
    }
    else if(iteraciones == (lista->cantidad - 1)){
      int vacio = lista_iterador_avanzar(iterador);
      pa2m_afirmar((vacio == 0), "Avanzar el iterador devuelve false si estoy en el último elemento");
    }

    iteraciones++;
  }

  elemento_actual = lista_iterador_elemento_actual(iterador);
  pa2m_afirmar(NULL == elemento_actual, "Iterador no tiene siguiente, termina de iterar, y su elemento actual es NULL");


  pa2m_afirmar(iteraciones == (lista->cantidad), "Iterador itera tantas veces como elementos haya");

  lista_iterador_destruir(iterador);
  lista_destruir(lista);
}

void Cola_Se_Crea_y_Puedo_Encolar_y_Desencolar_Elementos_Correctamente_y_Buscar_Elementos_en_el_Frente(){
  cola_t* cola = cola_crear();
  lista_t* cola_aux = (lista_t*)cola;
  char a='a', b='b', c='c';


  pa2m_afirmar((cola_aux->nodo_inicio) == NULL, "Nodo inicio es NULL");
  pa2m_afirmar((cola_aux->nodo_fin) == NULL, "Nodo fin es NULL");

  cola_encolar(cola, &a);
  cola_encolar(cola, &b);
  cola_encolar(cola, &c);
  
  pa2m_afirmar((cola_aux->nodo_inicio->elemento) == &a, "Se agrega 1 elemento correctamente");
  pa2m_afirmar(((cola_aux->nodo_inicio->siguiente->elemento) == &b) && ((cola_aux->nodo_fin->elemento) == &c), "Se encolaron 3 elementos");
  

  char* elemento = cola_frente(cola);
  pa2m_afirmar((*elemento) == a, "Puedo buscar el primer elemento de la cola");

  elemento = cola_desencolar(cola);
  pa2m_afirmar((cola_aux->nodo_inicio->elemento) == &b, "Se desencoló un elemento correctamente");
  pa2m_afirmar(elemento == &a, "El elemento desencolado es correcto");

  cola_desencolar(cola);
  pa2m_afirmar((cola_aux->nodo_inicio->elemento) == &c, "Se desencolaron dos elementos correctamente");

  cola_desencolar(cola);
  pa2m_afirmar((cola_aux->nodo_inicio) == NULL, "Se desencolaron todos los elementos correctamente");

  cola_destruir(cola);
}

void Puedo_Devolver_Elemento_en_Posicion_de_Cola(){
  cola_t* cola = cola_crear();
  char a='a';

  int vacia = cola_vacia(cola);
  pa2m_afirmar((vacia) != 0, "No agrego elementos, cola está vacía");

  char* elemento = cola_frente(cola);
  pa2m_afirmar((elemento) == NULL, "No hay elementos, no hay nada para devolver del frente");

  cola_encolar(cola, &a);

  vacia = cola_vacia(cola);
  pa2m_afirmar((vacia) == 0, "Agrego elementos, cola NO está vacía");
  
  elemento = cola_frente(cola);
  pa2m_afirmar((*elemento) == a, "Devuelve correctamente el primer elemento");

  cola_destruir(cola);
}

void Pila_Se_Crea_y_Se_Inicializa_Correctamente(){
  pila_t* pila = pila_crear();
  lista_t* pila_aux = (lista_t*) pila;

  pa2m_afirmar((pila_aux->nodo_inicio) == NULL, "Nodo inicio es NULL");
  pa2m_afirmar((pila_aux->nodo_fin) == NULL, "Nodo fin es NULL");

  pila_destruir(pila);
}

void Puedo_Apilar_y_Desapilar_Elementos_Correctamente(){
  pila_t* pila = pila_crear();
  lista_t* pila_aux = (lista_t*)pila;
  char a='a', b='b', c='c';

  pila_apilar(pila, &a);
  pa2m_afirmar((pila_aux->nodo_inicio->elemento) == &a, "Se apila 1 elemento correctamente");
  
  pila_apilar(pila, &b);
  pila_apilar(pila, &c);
  pa2m_afirmar(((pila_aux->nodo_inicio->siguiente->elemento) == &b) && ((pila_aux->nodo_fin->elemento) == &c), "Se apilaron 3 elementos");
  
  char* elemento_desapilado = pila_desapilar(pila);
  pa2m_afirmar((*elemento_desapilado) == c, "Si desapilo un elemento, me devuelve el que era el último elemento de la pila");


  pila_destruir(pila);
}

bool recorrer_lista(void* elemento, void* contador){
  return (elemento && contador);
}

void Probar_Iterador_Interno(){
  lista_t* lista = lista_crear();
  int a='a', b='b', c='c', d='d', e='e', f='f';
  
  int contador=0;
  size_t elementos_recorridos = 0;
  elementos_recorridos = lista_con_cada_elemento(lista, recorrer_lista, (void*)&contador);
  

  pa2m_afirmar(elementos_recorridos == 0, "Si lista está vacía, los elementos recorridos son 0");

  lista_insertar(lista, &a);
  lista_insertar(lista, &b);
  lista_insertar(lista, &c);
  lista_insertar(lista, &d);
  lista_insertar(lista, &e);
  lista_insertar(lista, &f);
  
  contador=0;
  elementos_recorridos = 0;
  elementos_recorridos = lista_con_cada_elemento(lista, recorrer_lista, (void*)&contador);
  pa2m_afirmar(elementos_recorridos == lista->cantidad, "Se recorren correctamente todos los elementos de la lista");

  lista_destruir(lista);
}

int main() {
  pa2m_nuevo_grupo("PRUEBAS DE LISTA");
  Lista_Se_Crea_y_Se_Inicializa_Correctamente();
  Puedo_Insertar_y_Quitar_Elementos();
  Puedo_Saber_el_Tamanio_de_Lista_y_Buscar_Elementos();

  pa2m_nuevo_grupo("PRUEBAS DE COLA");
  Cola_Se_Crea_y_Puedo_Encolar_y_Desencolar_Elementos_Correctamente_y_Buscar_Elementos_en_el_Frente();

  pa2m_nuevo_grupo("PRUEBAS DE PILA");
  Pila_Se_Crea_y_Se_Inicializa_Correctamente();
  Puedo_Apilar_y_Desapilar_Elementos_Correctamente();

  pa2m_nuevo_grupo("PRUEBAS DE ITERADOR EXTERNO");
  Iterador_Externo_Itera_Correctamente();
  
  pa2m_nuevo_grupo("PRUEBAS DE ITERADOR INTERNO");
  Probar_Iterador_Interno();

  return pa2m_mostrar_reporte();
}
