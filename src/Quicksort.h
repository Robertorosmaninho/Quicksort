#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort{
private:	
	int *_vetor;
	int _mov, _comp;
	int _tamanho;
	int _caso;

public:
	QuickSort(int n, int *V);
	~QuickSort();	

	int* get_vetor();
	int  get_tamanho(); 

	int Mediana3(int *inicio, int *fim, int* V);
	void Insercao(int *V, int tamanho);
	int EscolhePivo(int Esq, int *inicio, int *fim, int* V);
 	void Particao(int Esq, int Dir, int *inicio, int *fim, int* V);
	void Ordena(int Esq, int Dir, int* V);

	int *Classico();
	int *Mediana();
	int *Primeiro();
	int *Insercao1();
	int *Insercao5();
	int *Insercao10();
	int *Iterativo();

	int  get_comp(); //Número de Comparações entre Chaves
	int  get_mov(); //Número de Movimentações de Registros
	double get_tempo(int Caso); //Tempo para Executar um Sort
};

#endif
