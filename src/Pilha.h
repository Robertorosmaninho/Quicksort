#ifndef PILHA_H
#define PILHA_H
typedef struct Item{
	int _esquerda;
	int _direita;

	Item() = delete;
	Item(int e, int d) : _esquerda(e), _direita(d){}
}Item;

typedef struct Celula{
	Item *_elemento;
	Celula *_proximo;	

	Celula(Item *item) : _elemento(item), _proximo(nullptr){}
	Celula(Item *item, Celula *prox) 
					: _elemento(item), _proximo(prox){}

} Celula;

class Pilha{
private:
	Celula *_topo;
	int _tamanho;

public:
	Pilha();
	~Pilha();

	void Empilha(Item *item);
	Item* Desempilha();
	int get_tamanho();
	Celula* get_top();
};
#endif
