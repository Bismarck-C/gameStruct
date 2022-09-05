#pragma once
#include <iostream>
#include <string>
using namespace std;

//estructura Nodo
struct Nodo{
private:
	string word; //dato
	Nodo* next; // puntero siguiente
public:
	Nodo() {
		this->word = "";
		this->next = NULL;
	}
	void setWord(string word) {
		this->word = word;
	}
	string getWord() {
		return word;
	}

	void push(Nodo*&, char word);//metodos
	bool find(Nodo*, string);
	void pop(Nodo*&, string& n);
};

void Nodo::push(Nodo*& lista, char pWord) {
	//paso 1: crear un nuevo nodo
	Nodo* newNodo = new Nodo();
	newNodo->word = pWord;
	//paso 2 creamos dos auxiliares el primero apunta a a lista = NULL
	Nodo* aux1 = lista;

	// case to insert nodos

	if (lista == aux1) {//Sabemos si la lista esta vacía si es = NULL
		lista = newNodo; 
	
	}
	newNodo->next = aux1;

}

bool Nodo::find(Nodo* lista, string pFind) {
	Nodo* auxNodo = new Nodo();
	auxNodo = lista;

	while (auxNodo != NULL) {// se intera hasta llegar a NULL
		if (auxNodo->getWord() == pFind) { //se comparan las letras
			return true;
		}
		auxNodo = auxNodo->next; //se pasa al siguiente nodo de la lista
		
	}
	return false;
	

}
void Nodo::pop(Nodo*& lista, string& n) {

	Nodo* auxNodo;
	auxNodo = lista; // nuestro aux se iguala a la lista;
	n = auxNodo->getWord(); 
	lista = auxNodo->next; // lista estara apuntando al siguiente elemento de la lista; 
	delete auxNodo; // se borra aux ya que este apunta al primer elemento de la lista;

}
