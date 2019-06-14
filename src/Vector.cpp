#include "Vector.h"

#include <random>
#include <iostream>

#include <cstdlib>
#include <cmath>


Vector::Vector(int tamanho){
	this->_vetor = new int[tamanho];
	this->_tamanho = tamanho;
}

Vector::~Vector(){
	delete this->_vetor;
}

int* Vector::OrdemCrescente(){
	for(int i = 0; i < this->_tamanho; i++)
  this->_vetor[i] = i+1;

  return this->_vetor;
}

int* Vector::OrdemDecrescente(){
	int k = this->_tamanho;
  for(int i = 0; i < this->_tamanho; i++){
    this->_vetor[i] = k;
		k--;
	}

  return this->_vetor;
}

int* Vector::OrdemAleatoria(){
	//Gerador de Números Aleatórios -> Bibliografia: 1
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1,this->_tamanho);

  for(int i = 0; i < this->_tamanho; i++)
    this->_vetor[i] = dist(rng);

  return this->_vetor;	
}

//Função para ordenar os tempos de execução - Pequenos Casos - Inserção
void Vector::OrdenaDouble(int tamanho, double *tempo){
	int j;
  double aux;
  for(int i = 1; i < tamanho; i++){
    aux = tempo[i];
    j = i - 1;
    while((j >= 0) && (aux < tempo[j])){
      tempo[j+1] = tempo[j];
      j--;
    }
    tempo[j+1] = aux;
  }
}

//Copia elementos de um vetor em outro
int* Vector::CopiaVetor(){
	int *VetorNovo = new int[this->_tamanho];
  for(int i = 0; i < this->_tamanho; i++)
    VetorNovo[i] = this->_vetor[i];

  return VetorNovo;
}
