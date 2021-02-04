/*
 * main.cpp
 *
 *  Created on: Feb 4, 1994
 *      Author: nazaquintero
 */


#include<iostream>
#include "src/ABB.h"

using namespace std;

int main()
{
	ABB<string, int>* bst = new ABB<string, int>();
	string personajes[] = {"Goro", "Aang", "Zuko", "Gaara", "Kratos"};
	int vida[] = { 100, 70, 80, 90, 120};
	for(int i=0; i<5; i++)
		bst->insertar(personajes[i], vida[i]);

	bst->imprimir_in_order();

	delete bst;

}
