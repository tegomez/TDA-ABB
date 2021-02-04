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

template <class K, class T>
class ABB
{
private:
    // attributes
    NodoABB<K, T>* raiz;

    // methods
    NodoABB<K, T>* insertar(NodoABB<K, T>* nodo, T data);
    void imprimir_in_order(NodoABB<K, T> * nodo);
    NodoABB<K, T>* buscar(NodoABB<K, T>* nodo, T data);
    T obtener_min(NodoABB<K, T>* nodo);
    T obtener_max(NodoABB<K, T>* nodo);
    T sucesor(NodoABB<K, T>* nodo);
    T predecesor(NodoABB<K, T>* nodo);
    NodoABB<K, T>* borrar(NodoABB<K, T>* nodo, T data);
    void borrar_todo(NodoABB<K, T>* nodo);

public:
    //methods

    // Creates an esta_vacio tree
    ABB();

     // Adds a new nodo to the actual ABB. If its the tree is esta_vacio
     // the nodo insertared will be the raiz
    void insertar(T data);

    // Prints all the data stored in the ABB, sorted from the
    // smallest value to the greatest value.
    void imprimir_in_order();

    // Finds a given value in the ABB. If the key exists it returns
    // TRUE, otherwise it returns FALSE.
    bool buscar(T data);

    // Finds the minimum value that exist in the ABB.
    T obtener_min();

    // Finds the maximum value that exist in the ABB.
    T obtener_max();

    // Finds the sucesor of a given data value.
    T sucesor(T data);

    // Finds the predecesor of a given data value.
    T predecesor(T data);

    // Removes a given data from the ABB
    void borrar(T data);

    NodoABB<K, T>* get_raiz();
    bool esta_vacio();

    // Deletes all the nodos in the ABB
    void borrar_todo();
    ~ABB<K, T>();

};

template <class K, class T>
ABB<K, T>::ABB() {
    this->raiz = NULL;
}

template <class K, class T>
NodoABB<K, T>* ABB<K, T>::insertar(NodoABB<K, T>* nodo, T data) {

    if (nodo == NULL) {
        nodo = new NodoABB<K, T>(data);
    }

    else if (data > nodo->get_data()) {
        nodo->set_derecho(insertar(nodo->get_derecho(), data), nodo);
    }

    else {
        nodo->set_izquierdo(insertar(nodo->get_izquierdo(), data), nodo);
    }
    return nodo;
}

template <class K, class T>
void ABB<K, T>::insertar(T data)
{
    this->raiz = insertar(this->raiz, data);
}

template <class K, class T>
void ABB<K, T>::imprimir_in_order(NodoABB<K, T>* nodo)
{
    if (nodo != NULL)
    {
        imprimir_in_order(nodo->get_izquierdo());
        std::cout<<nodo->get_data()<<' ';
        imprimir_in_order(nodo->get_derecho());
    }
}

template <class K, class T>
void ABB<K, T>::imprimir_in_order()
{
    this->imprimir_in_order(this->raiz);
}

template <class K, class T>
NodoABB<K, T>* ABB<K, T>::buscar(NodoABB<K, T>* nodo, T data)
{
    if (nodo == NULL || nodo->get_data() == data)
        return nodo;

    if (data > nodo->get_data())
        return buscar(nodo->get_derecho(), data);

    return buscar(nodo->get_izquierdo(), data);
}

template <class K, class T>
bool ABB<K, T>::buscar(T data)
{
    NodoABB<K, T>* result = buscar(this->raiz, data);

    return result != NULL;
}

template <class K, class T>
T ABB<K, T>::obtener_min(NodoABB<K, T>* nodo)
{
    if(nodo == NULL)
        return -1;
    else if(nodo->get_izquierdo() == NULL)
        return nodo->get_data();
    else
        return obtener_min(nodo->get_izquierdo());
}

template <class K, class T>
T ABB<K, T>::obtener_min()
{
    return obtener_min(this->raiz);
}

template <class K, class T>
T ABB<K, T>::obtener_max(NodoABB<K, T>* nodo)
{
    if(nodo == NULL)
        return -1;
    else if(nodo->get_derecho() == NULL)
        return nodo->get_data();
    else
        return obtener_max(nodo->get_derecho());
}

template <class K, class T>
T ABB<K, T>::obtener_max()
{
    return obtener_max(this->raiz);
}

template <class K, class T>
T ABB<K, T>::sucesor(NodoABB<K, T>* nodo)
{
    if (nodo->get_derecho() != NULL)
    {
        return obtener_min(nodo->get_derecho());
    }
    NodoABB<K, T>* sucesor = NULL;
    NodoABB<K, T>* ancestor = this->raiz;
    while(ancestor != nodo) {
        if(nodo->get_data() < ancestor->get_data()) {
            sucesor = ancestor;
            ancestor = ancestor->get_izquierdo();
        }
        else
            ancestor = ancestor->get_derecho();
    }
    return sucesor->get_data();
}

template <class K, class T>
T ABB<K, T>::sucesor(T data)
{
    NodoABB<K, T>* data_nodo = this->buscar(this->raiz, data);
    // Return the key. If the key is not found or sucesor is not found, return -1
    if(data_nodo == NULL)
        return -1;
    else return sucesor(data_nodo);
}

template <class K, class T>
T ABB<K, T>::predecesor(NodoABB<K, T> * nodo)
{
    if (nodo->get_izquierdo() != NULL)
    {
        return obtener_max(nodo->get_izquierdo());
    }

    NodoABB<K, T>* sucesor = NULL;
    NodoABB<K, T>* ancestor = this->raiz;
    while(ancestor != nodo) {
        if(nodo->get_data() > ancestor->get_data()) {
            sucesor = ancestor; // so far this is the deepest nodo for which current nodo is in izquierdo
            ancestor = ancestor->get_derecho();
        }
        else
            ancestor = ancestor->get_izquierdo();
    }
    return sucesor->get_data();
}

template <class K, class T>
T ABB<K, T>::predecesor(T data)
{
    NodoABB<K, T> * data_nodo = this->buscar(this->raiz, data);

    if(data_nodo == NULL)
        return -1;
    else return predecesor(data_nodo);
}

template <class K, class T>
NodoABB<K, T> * ABB<K, T>::borrar(NodoABB<K, T>* nodo, T data)
{
    // The given nodo is not found in ABB
    if (nodo == NULL)
        return NULL;

    if (nodo->get_data() == data)
    {
        if (nodo->esHoja())
            delete nodo;
        else if (nodo->tiene_solo_hijo_derecho())
        {
            // The only child will be connected to the padre's of nodo directly
            nodo->get_derecho()->set_padre(nodo->get_padre());
            // Bypass nodo
            NodoABB<K, T>* aux = nodo;
            nodo = nodo->get_derecho();
            delete aux;
        }
        else if (nodo->tiene_solo_hijo_izquierdo())
        {
            // The only child will be connected to the padre's of nodo directly
            nodo->get_izquierdo()->set_padre(nodo->get_padre());
            // Bypass nodo
            NodoABB<K, T>* aux = nodo;
            nodo = nodo->get_izquierdo();
            delete aux;
        }

        // The nodo has two children (izquierdo and derecho)
        else
        {
            // Find sucesor or predecesor to avoid quarrel
            T sucesor_data = this->sucesor(data);

            // Replace nodo's key with sucesor's key
            nodo->set_data(sucesor_data);

            // Delete the old sucesor's key
            nodo->set_derecho(borrar(nodo->get_derecho(), sucesor_data));
        }
    }

    else if (nodo->get_data() < data)
        nodo->set_derecho(borrar(nodo->get_derecho(), data));

    else
        nodo->set_izquierdo(borrar(nodo->get_izquierdo(), data));

    return nodo;
}

template <class K, class T>
void ABB<K, T>::borrar(T data)
{
    this->raiz = borrar(this->raiz, data);
}

template <class K, class T>
NodoABB<K, T>* ABB<K, T>::get_raiz(){
    return this->raiz;
}

template <class K, class T>
bool ABB<K, T>::esta_vacio()
{
    return this->raiz == NULL;
}


template <class K, class T>
void ABB<K, T>::borrar_todo(NodoABB<K, T>* nodo)
{
    if(nodo == NULL)
        return;
    this->borrar_todo(nodo->get_izquierdo());
    this->borrar_todo(nodo->get_derecho());
    delete nodo;
}

template <class K, class T>
void ABB<K, T>::borrar_todo()
{
    this->borrar_todo(this->raiz);
}

template <class K, class T>
ABB<K, T>::~ABB<K, T>()
{
    this->borrar_todo();
}



#endif /* SRC_ABB_H_ */
