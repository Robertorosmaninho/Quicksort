if [ -f OrdemCrescente.txt ]; then
	rm OrdemCrescente.txt
	touch OrdemCrescente.txt
fi

if [ -f OrdemDecrescente.txt ]; then
	rm OrdemDecrescente.txt
	touch OrdemDecrescente.txt
fi

if [ -f OrdemAleatoria.txt ]; then
	rm OrdemAleatoria.txt
	touch OrdemAleatoria.txt
fi

#Expande a memória do Stack
ulimit -s 65532

#Compila o programa
make

#Define os tamanhos dos vetores
vetor=(50000 100000 150000 200000 250000 300000 350000 400000 450000 500000)


#################### Executa Ordem Crescente ####################
echo "#### Vetores Organizados de Forma Crescente ###" > OrdemCrescente.txt
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Clássica ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QC OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo ""  >> OrdemCrescente.txt

echo "## Ordenação: Primeiro Elemento ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do 
./tp2 QPE OrdC ${vetor[$i]} >> OrdemCrescente.txt
done 
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Mediana de 3 ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QM3 OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Insercao 1% ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QI1 OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Insercao 5% ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QI5 OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Insercao 10% ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QI10 OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo "" >> OrdemCrescente.txt

echo "## Ordenação: Nao Recursivo ##" >> OrdemCrescente.txt
echo "" >> OrdemCrescente.txt
for i in {0..9} ;do
./tp2 QNR OrdC ${vetor[$i]} >> OrdemCrescente.txt
done
echo "" >> OrdemCrescente.txt

#################### Executa Ordem Decrescente ####################
echo "#### Vetores Organizados de Forma Derescente ###" > OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Clássica ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QC OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo ""  >> OrdemDecrescente.txt

echo "## Ordenação: Primeiro Elemento ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do 
./tp2 QPE OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done 
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Mediana de 3 ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QM3 OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Insercao 1% ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QI1 OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Insercao 5% ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QI5 OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Insercao 10% ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QI10 OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo "" >> OrdemDecrescente.txt

echo "## Ordenação: Nao Recursivo ##" >> OrdemDecrescente.txt
echo "" >> OrdemDecrescente.txt
for i in {0..9} ;do
./tp2 QNR OrdD ${vetor[$i]} >> OrdemDecrescente.txt
done
echo "" >> OrdemDecrescente.txt


#################### Executa Ordem Aleatória ####################
echo "#### Vetores Organizados de Forma Aleatória  ###" > OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Clássica ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QC Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo ""  >> OrdemAleatoria.txt

echo "## Ordenação: Primeiro Elemento ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do 
./tp2 QPE Ale ${vetor[$i]} >> OrdemAleatoria.txt
done 
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Mediana de 3 ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QM3 Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Insercao 1% ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QI1 Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Insercao 5% ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QI5 Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Insercao 10% ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QI10 Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo "" >> OrdemAleatoria.txt

echo "## Ordenação: Nao Recursivo ##" >> OrdemAleatoria.txt
echo "" >> OrdemAleatoria.txt
for i in {0..9} ;do
./tp2 QNR Ale ${vetor[$i]} >> OrdemAleatoria.txt
done
echo "" >> OrdemAleatoria.txt

#Testa se já exite o diretório de resultado de testes
if [ -d ../Resultados ]; then
	rm -r ../Resultados
fi

#Cria o diretório de resultado de testes e move os resultado para este
mkdir ../Resultados
mv  OrdemAleatoria.txt OrdemDecrescente.txt OrdemCrescente.txt ../Resultados

