#include "Pilha.h"
#include <iostream>

Pilha::Pilha(){
	this->_topo = 0;
	this->_tamanho = 0;
}

Pilha::~Pilha(){
	while(this->_tamanho > 0){
		Desempilha();
	}
}

void Pilha::Empilha(Item *item){
	
	Celula *c = new Celula(item, this->get_top());
	_tamanho++;
	_topo = c;
}

Item* Pilha::Desempilha(){
	if(this->_tamanho == 0){
		std::cout << "Lista Vazia!" <<std::endl;
		return nullptr;
	}
	
	Celula *topo = this->_topo;
	this->_topo = this->_topo->_proximo;
	this->_tamanho--;
	return topo->_elemento;

}

int Pilha::get_tamanho(){
	return this->_tamanho;
}

Celula* Pilha::get_top(){
	return _tamanho == 0 ? nullptr : _topo;
}
