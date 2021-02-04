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
	int datos[] = { 23, 12, 31, 3, 7, 15, 29, 88, 53};
	for(int i=0;i<9;i++)
		bst->insertar(datos[i]);

	bst->imprimir_in_order();

	delete bst;

}
