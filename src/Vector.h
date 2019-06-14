class Vector{
private:
	int *_vetor;
	int _tamanho;

public:
	Vector(int tamanho);
	~Vector();

	int* OrdemCrescente();
	int* OrdemDecrescente();
	int* OrdemAleatoria();

	void OrdenaDouble(int tamanho, double *tempo);
	int* CopiaVetor();
};
