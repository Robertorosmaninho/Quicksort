//Autor: Roberto Gomes Rosmaninho Neto
//GitHub: RobertoRosmaninho
//Contato: Robertogomes@dcc.ufmg.br
//Útima Edição: 7/06/2019

#include <iostream>
#include <sstream>

#include "Quicksort.h"
#include "Vector.h"

#define NUM_TESTES 1

int main(int argc, char *argv[ ]){
	
	//Trata excessões de parametros
	if(argc < 3){
		std::cout << "Uso ./nomedoprograma <variacao> <tipo> <tamanho>\n";
		return 0;
	}
	
	//Declara varáveis importantes
	int *vetores[NUM_TESTES], *vetor, n;
	double tempo[NUM_TESTES], tempo_mediano, n_comp_medio = 0, n_mov_medio = 0;
	unsigned long int  n_comp[NUM_TESTES], n_mov[NUM_TESTES]; 
	std::string variacao, tipo, tamanho, detalhes;

	//Le Argumentos
	variacao = argv[1];
	tipo = argv[2];
	tamanho = argv[3];
	
	if(argc > 4)
		detalhes = argv[4];
	
	//Converte string pra inteiro
	std::istringstream iss (tamanho);
	iss >> n;
	
	//Trata excessão de tamanho do vetor
	if(n < 0){
		std::cout << "Digite um tamanho positivo!\n";
		return 0;
	}

	//Gerador de Vetor para personalizar o vetor de acordo com a ordenação	
	Vector *GeradorDeVetor = new Vector(n);

	for(int i = 0; i < NUM_TESTES; i++){
		//Reconhece o tipo
		if(tipo == "Ale")
			vetor = GeradorDeVetor->OrdemAleatoria();
		if(tipo == "OrdC")
			vetor = GeradorDeVetor->OrdemCrescente();
		if(tipo == "OrdD")
			vetor = GeradorDeVetor->OrdemDecrescente();

		QuickSort *Quick = new QuickSort(n, vetor);
		vetores[i] = GeradorDeVetor->CopiaVetor();

		//Reconhece a variação do Quicksort
		if(variacao == "QC"){ //Classico
			tempo[i] = Quick->get_tempo(1); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
 		if(variacao == "QM3"){ //Utilizando Mediana de 3 como Pivô
			tempo[i] = Quick->get_tempo(3); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
		if(variacao == "QPE"){ //Utilizando o Primeiro elemento como Pivô 
			tempo[i] = Quick->get_tempo(2); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}	
		if(variacao == "QI1"){ //Utilizando Inserção quando há K chaves < 1% do total  
			tempo[i] = Quick->get_tempo(4); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
		if(variacao == "QI5"){ //Utilizando Inserção quando há K chaves < 5% do total
			tempo[i] = Quick->get_tempo(5); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
		if(variacao == "QI10"){//Utilizando Inserção quando há K chaves < 10% do total
			tempo[i] = Quick->get_tempo(6); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
		if(variacao == "QNR"){ //Utlizando o Quicksort não recursivo
			tempo[i] = Quick->get_tempo(7); 
			n_comp[i] = Quick->get_comp(); 
			n_mov[i] = Quick->get_mov();
		}
	}

	//Ordena os tempos de execução e recebe a mediana destes
	GeradorDeVetor->OrdenaDouble(NUM_TESTES, tempo);
	tempo_mediano = tempo[NUM_TESTES/2];

	//Calcula a média de Movimentações e Comparações
	for(int i = 0; i < NUM_TESTES; i++){
		n_comp_medio += n_comp[i];
		n_mov_medio += n_mov[i];
	}
	n_comp_medio /= NUM_TESTES;
	n_mov_medio /= NUM_TESTES;

	//Saídas	
	std::cout << variacao << " " << tipo << " " << tamanho << " ";
	std::cout	<< n_comp_medio << " " << n_mov_medio << " ";
	std::cout	<< tempo_mediano << std::endl;

 	if(detalhes == "-p"){
		int *atual; 
    for(int i = 0; i < NUM_TESTES; i++){
			atual = vetores[i];
      for(int j = 0; j < n; j++){
        std::cout << atual[j] << " ";
			}
    	std::cout << std::endl;
		}
  } 

return 0;
}
