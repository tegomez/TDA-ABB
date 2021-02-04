/*
 * NodoAbb.h
 *
 *  Created on: Feb 4, 2021
 *      Author: nazaquintero
 */

#ifndef SRC_NODOABB_H_
#define SRC_NODOABB_H_

template <class T>
class NodoABB
{
private:
    T data;
    NodoABB<T>* izquierdo; //Left children
    NodoABB<T>* derecho; //Right children
    NodoABB<T>* padre;

public:
    NodoABB(T data);
    T get_data();
    void set_data(T data);
    void set_derecho(NodoABB<T>* derecho, NodoABB<T>* padre);
    void set_izquierdo(NodoABB<T>* izquierdo, NodoABB<T>* padre);
    void set_izquierdo(NodoABB<T>* izquierdo);
    void set_derecho(NodoABB<T>* derecho);
    void set_padre(NodoABB<T>* padre);
    NodoABB<T>* get_derecho();
    NodoABB<T>* get_izquierdo();
    NodoABB<T>* get_padre();
    bool esHoja();
    bool tiene_solo_hijo_derecho();
    bool tiene_solo_hijo_izquierdo();
};

template <class T>
NodoABB<T>::NodoABB(T data)
{
    this->data = data;
    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
}

template <class T>
T NodoABB<T>::get_data()
{
    return this->data;
}

template <class T>
void NodoABB<T>::set_derecho(NodoABB<T>* derecho, NodoABB<T>* padre){
    this->derecho = derecho;
    this->padre = padre;
}

template <class T>
void NodoABB<T>::set_derecho(NodoABB<T>* derecho){
    this->derecho = derecho;
}

template <class T>
void NodoABB<T>::set_izquierdo(NodoABB<T>* izquierdo, NodoABB<T>* padre){
    this->izquierdo = izquierdo;
    this->padre = padre;
}

template <class T>
void NodoABB<T>::set_padre(NodoABB<T> *padre) {
    this->padre = padre;
}

template <class T>
void NodoABB<T>::set_data(T data) {
    this->data = data;
}


template <class T>
void NodoABB<T>::set_izquierdo(NodoABB<T>* izquierdo){
    this->izquierdo = izquierdo;
}

template <class T>
NodoABB<T>* NodoABB<T>::get_derecho()
{
    return this->derecho;
}

template <class T>
NodoABB<T>* NodoABB<T>::get_izquierdo()
{
    return this->izquierdo;
}

template <class T>
NodoABB<T>* NodoABB<T>::get_padre()
{
    return this->padre;
}

template <class T>
bool NodoABB<T>::esHoja() {
    return (this->get_izquierdo() == NULL && this->get_derecho() == NULL);
}

template <class T>
bool NodoABB<T>::tiene_solo_hijo_derecho() {
    return (this->get_izquierdo() == NULL && this->get_derecho() != NULL);
}

template <class T>
bool NodoABB<T>::tiene_solo_hijo_izquierdo() {
    return (this->get_izquierdo() != NULL && this->get_derecho() == NULL);
}



#endif /* SRC_NODOABB_H_ */
