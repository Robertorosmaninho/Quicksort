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

	void OrdenaDouble(int tamanho, long double *tempo);
	int* CopiaVetor();
};
