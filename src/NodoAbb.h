/*
 * NodoAbb.h
 *
 *  Created on: Feb 4, 2021
 *      Author: nazaquintero
 */

#ifndef SRC_NODOABB_H_
#define SRC_NODOABB_H_

template<class K, class T>
class NodoABB {
private:
	K clave;
	T data;
	NodoABB<K, T> *izquierdo; //Hijo izquierdo.
	NodoABB<K, T> *derecho; //Hijo derecho.
	NodoABB<K, T> *padre;

public:
	NodoABB(K clave, T data);
	T get_data();
	void set_data(K clave);
	K get_clave();
	void set_clave(K clave);
	void set_derecho(NodoABB<K, T> *derecho, NodoABB<K, T> *padre);
	void set_izquierdo(NodoABB<K, T> *izquierdo, NodoABB<K, T> *padre);
	void set_izquierdo(NodoABB<K, T> *izquierdo);
	void set_derecho(NodoABB<K, T> *derecho);
	void set_padre(NodoABB<K, T> *padre);
	NodoABB<K, T>* get_derecho();
	NodoABB<K, T>* get_izquierdo();
	NodoABB<K, T>* get_padre();
	bool esHoja();
	bool tiene_solo_hijo_derecho();
	bool tiene_solo_hijo_izquierdo();
};

template<class K, class T>
NodoABB<K, T>::NodoABB(K clave, T data) {
    this->clave = clave;
	this->data = data;
	this->izquierdo = NULL;
	this->derecho = NULL;
	this->padre = NULL;
}

template<class K, class T>
T NodoABB<K, T>::get_data() {
	return this->data;
}

template<class K, class T>
void NodoABB<K, T>::set_data(K clave) {
	this->data = data;
}

template<class K, class T>
K NodoABB<K, T>::get_clave() {
	return this->clave;
}

template<class K, class T>
void NodoABB<K, T>::set_clave(K clave) {
	this->clave = clave;
}

template<class K, class T>
void NodoABB<K, T>::set_derecho(NodoABB<K, T> *derecho, NodoABB<K, T> *padre) {
	this->derecho = derecho;
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::set_derecho(NodoABB<K, T> *derecho) {
	this->derecho = derecho;
}

template<class K, class T>
void NodoABB<K, T>::set_izquierdo(NodoABB<K, T> *izquierdo,
		NodoABB<K, T> *padre) {
	this->izquierdo = izquierdo;
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::set_padre(NodoABB<K, T> *padre) {
	this->padre = padre;
}

template<class K, class T>
void NodoABB<K, T>::set_izquierdo(NodoABB<K, T> *izquierdo) {
	this->izquierdo = izquierdo;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::get_derecho() {
	return this->derecho;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::get_izquierdo() {
	return this->izquierdo;
}

template<class K, class T>
NodoABB<K, T>* NodoABB<K, T>::get_padre() {
	return this->padre;
}

template<class K, class T>
bool NodoABB<K, T>::esHoja() {
	return (this->get_izquierdo() == NULL && this->get_derecho() == NULL);
}

template<class K, class T>
bool NodoABB<K, T>::tiene_solo_hijo_derecho() {
	return (this->get_izquierdo() == NULL && this->get_derecho() != NULL);
}

template<class K, class T>
bool NodoABB<K, T>::tiene_solo_hijo_izquierdo() {
	return (this->get_izquierdo() != NULL && this->get_derecho() == NULL);
}

#endif /* SRC_NODOABB_H_ */
