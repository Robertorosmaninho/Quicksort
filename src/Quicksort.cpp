#include "Quicksort.h"
#include "Pilha.h"
#include <chrono>
#include <iostream>

QuickSort::QuickSort(int n, int *V){
	this->_mov = 0;
	this->_comp = 0;
	this->_caso = 0;
	this->_vetor = V; 
	this->_tamanho = n;
}

QuickSort::~QuickSort(){}

int* QuickSort::get_vetor(){
	return this->_vetor;
}

int  QuickSort::get_tamanho(){
	return this->_tamanho;
}


int QuickSort::Mediana3(int *inicio, int *fim, int *V){
	int x = 0, a = V[*inicio], b = V[(*inicio+*fim)/2], c = V[*fim];

	if ((b <= a && a <= c) || (c <= a && a <= b))
		x = a;
	else if ((a <= b && b <= c) || (c <= b && b <= a))
		x = b;
	else if ((a <= c && c <= b) || (b <= c && c <= a))
		x = c;

	this->_comp+=2; //Comparação+=2
	return x;
}

int QuickSort::EscolhePivo(int Esq, int *inicio, int *fim, int* V){
	int x = 0;
	switch(this->_caso){
		case 1: // Pivo Central
			x = (*inicio + *fim)/2;
			x = V[x];
			break;
		case 2: //Pivo Primeiro
			x = Esq;
			x = V[x];
			break;
		case 3: //Mediana de 3
			x = Mediana3(inicio, fim, V);
			break;
		case 4: //Mediana de 3 + Inserção se tamanho < 1%
			x =  Mediana3(inicio, fim, V);
			break;
		case 5: //Mediana de 3 + Inserção se tamanho < 5%
			x  = Mediana3(inicio, fim, V);
		break;
		case 6: //Mediana de 3 + Inserção se tamanho < 10%
			x = Mediana3(inicio, fim, V);
		break;
		default:
			std::cout << "Erro na Escolha do Pivo\n";
			break;
	}
	return x;
}

void QuickSort::Insercao(int* V, int tamanho){
	int j, aux;
	for(int i = 1; i < tamanho; i++){
		aux = V[i];
		j = i - 1;
		while((j >= 0) && (aux < V[j])){
			this->_comp++; //Comparação++
			V[j+1] = V[j];
			this->_mov++; //Movimentação++
			j--;
		}
		V[j+1] = aux;
		this->_mov++; //Movimentação++
	}
}

void QuickSort::Particao(int Esq, int Dir, int *inicio, int *fim, int* V){
	int aux = 0;
	*inicio = Esq;
	*fim = Dir;

	int x = EscolhePivo(Esq, inicio, fim, V);

	//Lógica do Partição
	do{
		while(x > V[*inicio]){
			(*inicio)++;
			this->_comp++; //Comparação++
		}
		while(x < V[*fim]){
			(*fim)--;
			this->_comp++;  //Comparação++
		}
		if(*inicio <= *fim){
			aux = V[*inicio];
			V[*inicio] = V[*fim];
			V[*fim] = aux;
			this->_mov++; //Movimentação++
			(*inicio)++;
			(*fim)--;
		}
	}while(*inicio <= *fim);
}

void QuickSort::Ordena(int Esq, int Dir, int* V){
	int inicio, fim;
	if(this->_caso == 4 && ((Esq + Dir) < (this->_tamanho * 0.01))){
			Insercao(V, Esq + Dir);
	}else if(this->_caso == 5 && ((Esq + Dir) < (this->_tamanho * 0.05))){
			Insercao(V, Esq + Dir);
	}else if(this->_caso == 6 && ((Esq + Dir) < (this->_tamanho * 0.10))){
			Insercao(V, Esq + Dir);
	}else{
	Particao(Esq, Dir, &inicio, &fim, V);
	if(Esq < fim) Ordena(Esq, fim, V);
	if(Dir > inicio) Ordena(inicio, Dir, V);
	}
}

//Pivô é o Elemento Central
int* QuickSort::Classico(){
	this->_caso = 1;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivô é o Primeiro Elemento
int* QuickSort::Primeiro(){
	this->_caso = 2;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivô é a "Mediana de 3" - Primeiro, Central, Último Elemeto
int* QuickSort::Mediana(){
	this->_caso = 3;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivô é a "Mediana de 3" - Interrompe Partição e Inicia Inserção quando k = 1%
int* QuickSort::Insercao1(){
	this->_caso = 4;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivô é a "Mediana de 3" - Interrompe Partição e Inicia Inserção quando k = 5%
int* QuickSort::Insercao5(){
	this->_caso = 5;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivô é a "Mediana de 3" - Interrompe Partição e Inicia Inserção quando k = 10%
int* QuickSort::Insercao10(){
	this->_caso = 6;
	Ordena(0, this->_tamanho-1, this->_vetor);
	return this->_vetor;
}

//Pivo é o Elemento Central - Executa o QuickSort em usar Recursão
int* QuickSort::Iterativo(){
	Pilha *pilha = new Pilha();	
	int Esq, Dir, inicio, fim;

	//Como esse Quicksort utliza o Elemento Centro devemos usar o caso 1	
	this->_caso = 1;

	Esq = 0;
	Dir = this->_tamanho-1;
	
	Item *item = new Item(Esq, Dir);
	pilha->Empilha(item);
	
	do{
		if(Dir > Esq){

			Particao(Esq, Dir, &inicio, &fim, this->_vetor);
			if((fim - Esq) > (Dir - inicio)){
				Item *If = new Item(Esq, fim);
				pilha->Empilha(If);
				Esq = inicio;
			}else{
				Item *Else = new Item(inicio, Dir);
				pilha->Empilha(Else);
				Dir = fim;
			}
	
		}else{
			Item *ElseFinal;
			ElseFinal = pilha->Desempilha();
			Dir = ElseFinal->_direita;
			Esq = ElseFinal->_esquerda;
		}

	}while(pilha->get_tamanho());

	return this->_vetor;
}

//Número de Comparações entre Chaves
long long int  QuickSort::get_comp(){
	return this->_comp;
}

//Número de Movimentações de Registros
long long int  QuickSort::get_mov(){ 
	return this->_mov;
}
double QuickSort::get_tempo(int Caso){
	using namespace std::chrono;
	
	high_resolution_clock::time_point t1; 
	high_resolution_clock::time_point t2;

	switch(Caso){
		case 1:
			t1 = high_resolution_clock::now();
			this->Classico();
			t2 = high_resolution_clock::now();
			break;
		case 2:
			t1 = high_resolution_clock::now();
			this->Primeiro();
			t2 = high_resolution_clock::now();
			break;
		case 3:
			t1 = high_resolution_clock::now();
			this->Mediana();
			t2 = high_resolution_clock::now();
			break;
		case 4:
			t1 = high_resolution_clock::now();
			this->Insercao1();
			t2 = high_resolution_clock::now();
			break;
		case 5:
			t1 = high_resolution_clock::now();
			this->Insercao5();
			t2 = high_resolution_clock::now();
			break;
		case 6:
			t1 = high_resolution_clock::now();
			this->Insercao10();
			t2 = high_resolution_clock::now();
			break;
		case 7:
			t1 = high_resolution_clock::now();
			this->Iterativo();
			t2 = high_resolution_clock::now();
			break;
		default:
			std::cout << "Erro Opção Inválida!" << std::endl;
			return 0;
	}
	duration<double, std::micro> elapsed_time = duration_cast<duration<double> >(t2 - t1);
	double x = elapsed_time.count();
	return x;
}
