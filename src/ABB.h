/*
 * ABB.h
 *
 *  Created on: Feb 4, 2021
 *      Author: nazaquintero
 */

#ifndef SRC_ABB_H_
#define SRC_ABB_H_

#include "./NodoAbb.h"
#include <iostream>

template<class K, class T>
class ABB {
private:
	// Atributos
	NodoABB<K, T> *raiz;

	// Métodos
	NodoABB<K, T>* insertar(NodoABB<K, T> *nodo, K clave, T data);
	void imprimir_in_order(NodoABB<K, T> *nodo);
	NodoABB<K, T>* buscar(NodoABB<K, T> *nodo, K clave);
	K obtener_min(NodoABB<K, T> *nodo);
	K obtener_max(NodoABB<K, T> *nodo);
	K sucesor(NodoABB<K, T> *nodo);
	K predecesor(NodoABB<K, T> *nodo);
	NodoABB<K, T>* borrar(NodoABB<K, T> *nodo, K clave);
	void borrar_todo(NodoABB<K, T> *nodo);

public:
	// Metodos

	// Crea un ABB vacio.
	ABB();

	// Agrega un nuevo nodo al ABB actual. Si el ABB esta_vacio
	// el nodo insertado será la raíz.
	void insertar(K clave, T data);

	// Imprime la informacion guardada en el ABB.
	// Ordenada de menor a mayor
	void imprimir_in_order();

	// Busca una clave dada en el ABB Finds a given value in the ABB.
	// Si la clave existe devuelve TRUE
	bool buscar(K clave);

	// Busca el valor minimo de clave existente en el ABB.
	K obtener_min();

	// Busca el valor maximo de clave existente en el ABB.
	K obtener_max();

	// Encuentra el sucesor de una clave dada.
	K sucesor(K clave);

	// Encuentra el predecesor de una clave dada.
	K predecesor(K clave);

	// Remueve la data correspondiente a una clave del ABB.
	void borrar(K clave);

	// Devuelve la raiz del ABB.
	NodoABB<K, T>* get_raiz();

	//Devuelve TRUE si el ABB esta vacio.
	bool esta_vacio();

	// Borra todos los nodos del ABB.
	void borrar_todo();
	~ABB<K, T>();

};

template<class K, class T>
ABB<K, T>::ABB() {
	this->raiz = NULL;
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::insertar(NodoABB<K, T> *nodo, K clave, T data) {

	if (nodo == NULL) {
		nodo = new NodoABB<K, T>(clave, data);
	}

	else if (clave > nodo->get_clave()) {
		nodo->set_derecho(insertar(nodo->get_derecho(), clave, data), nodo);
	}

	else {
		nodo->set_izquierdo(insertar(nodo->get_izquierdo(), clave, data), nodo);
	}
	return nodo;
}

template<class K, class T>
void ABB<K, T>::insertar(K clave, T data) {
	this->raiz = insertar(this->raiz, clave, data);
}

template<class K, class T>
void ABB<K, T>::imprimir_in_order(NodoABB<K, T> *nodo) {
	if (nodo != NULL) {
		imprimir_in_order(nodo->get_izquierdo());
		std::cout << nodo->get_clave() << " vida: " << nodo->get_data() << "|";
		imprimir_in_order(nodo->get_derecho());
	}
}

template<class K, class T>
void ABB<K, T>::imprimir_in_order() {
	this->imprimir_in_order(this->raiz);
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::buscar(NodoABB<K, T> *nodo, K clave) {
	if (nodo == NULL || nodo->get_clave() == clave)
		return nodo;

	if (clave > nodo->get_clave())
		return buscar(nodo->get_derecho(), clave);

	return buscar(nodo->get_izquierdo(), clave);
}

template<class K, class T>
bool ABB<K, T>::buscar(K clave) {
	NodoABB<K, T> *result = buscar(this->raiz, clave);

	return result != NULL;
}

template<class K, class T>
K ABB<K, T>::obtener_min(NodoABB<K, T> *nodo) {
	if (nodo == NULL)
		return -1;
	else if (nodo->get_izquierdo() == NULL)
		return nodo->get_clave();
	else
		return obtener_min(nodo->get_izquierdo());
}

template<class K, class T>
K ABB<K, T>::obtener_min() {
	return obtener_min(this->raiz);
}

template<class K, class T>
K ABB<K, T>::obtener_max(NodoABB<K, T> *nodo) {
	if (nodo == NULL)
		return -1;
	else if (nodo->get_derecho() == NULL)
		return nodo->get_clave();
	else
		return obtener_max(nodo->get_derecho());
}

template<class K, class T>
K ABB<K, T>::obtener_max() {
	return obtener_max(this->raiz);
}

template<class K, class T>
K ABB<K, T>::sucesor(NodoABB<K, T> *nodo) {
	if (nodo->get_derecho() != NULL) {
		return obtener_min(nodo->get_derecho());
	}
	NodoABB<K, T> *sucesor = NULL;
	NodoABB<K, T> *ancestro = this->raiz;
	while (ancestro != nodo) {
		if (nodo->get_clave() < ancestro->get_clave()) {
			sucesor = ancestro;
			ancestro = ancestro->get_izquierdo();
		} else
			ancestro = ancestro->get_derecho();
	}
	return sucesor->get_clave();
}

template<class K, class T>
K ABB<K, T>::sucesor(K clave) {
	NodoABB<K, T> *nodo = this->buscar(this->raiz, clave);
	// Devuelve la clave. Si no encuentra la clave o en el sucesor, devuelve -1
	if (nodo == NULL)
		return -1;
	else
		return sucesor(nodo);
}

template<class K, class T>
K ABB<K, T>::predecesor(NodoABB<K, T> *nodo) {
	if (nodo->get_izquierdo() != NULL) {
		return obtener_max(nodo->get_izquierdo());
	}

	NodoABB<K, T> *sucesor = NULL;
	NodoABB<K, T> *ancestro = this->raiz;
	while (ancestro != nodo) {
		if (nodo->get_clave() > ancestro->get_clave()) {
			sucesor = ancestro;
			ancestro = ancestro->get_derecho();
		} else
			ancestro = ancestro->get_izquierdo();
	}
	return sucesor->get_clave();
}

template<class K, class T>
K ABB<K, T>::predecesor(K clave) {
	NodoABB<K, T> *nodo = this->buscar(this->raiz, clave);

	if (nodo == NULL)
		return -1;
	else
		return predecesor(nodo);
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::borrar(NodoABB<K, T> *nodo, K clave) {
	// El nodo no se encuentra en el ABB
	if (nodo == NULL)
		return NULL;

	if (nodo->get_clave() == clave) {
		if (nodo->esHoja())
			delete nodo;
		else if (nodo->tiene_solo_hijo_derecho()) {
			nodo->get_derecho()->set_padre(nodo->get_padre());

			NodoABB<K, T> *aux = nodo;
			nodo = nodo->get_derecho();
			delete aux;
		} else if (nodo->tiene_solo_hijo_izquierdo()) {
			nodo->get_izquierdo()->set_padre(nodo->get_padre());

			NodoABB<K, T> *aux = nodo;
			nodo = nodo->get_izquierdo();
			delete aux;
		}

		// El nodo tiene dos hijos (izquierdo y derecho)
		else {

			K sucesor_clave = this->sucesor(clave);

			// Reemplaza la clave del nodo por la de su sucesor
			nodo->set_clave(sucesor_clave);

			// Elimina la antigua clave del sucesor
			nodo->set_derecho(borrar(nodo->get_derecho(), sucesor_clave));
		}
	}

	else if (nodo->get_clave() < clave)
		nodo->set_derecho(borrar(nodo->get_derecho(), clave));

	else
		nodo->set_izquierdo(borrar(nodo->get_izquierdo(), clave));

	return nodo;
}

template<class K, class T>
void ABB<K, T>::borrar(K clave) {
	this->raiz = borrar(this->raiz, clave);
}

template<class K, class T>
NodoABB<K, T>* ABB<K, T>::get_raiz() {
	return this->raiz;
}

template<class K, class T>
bool ABB<K, T>::esta_vacio() {
	return this->raiz == NULL;
}

template<class K, class T>
void ABB<K, T>::borrar_todo(NodoABB<K, T> *nodo) {
	if (nodo == NULL)
		return;
	this->borrar_todo(nodo->get_izquierdo());
	this->borrar_todo(nodo->get_derecho());
	delete nodo;
}

template<class K, class T>
void ABB<K, T>::borrar_todo() {
	this->borrar_todo(this->raiz);
}

template<class K, class T>
ABB<K, T>::~ABB<K, T>() {
	this->borrar_todo();
}

#endif /* SRC_ABB_H_ */
