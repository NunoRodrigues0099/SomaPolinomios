/*
 * polinomio.cpp
 */

#include <iostream>
#include "polinomio.hpp"
#include "monomio.hpp"
#include "listaGenerica.cpp"

// Construtor
Polinomio::Polinomio(){
	
	Lista <Monomio> *lstM = new Lista <Monomio>;
};

// Destrutor
Polinomio::~Polinomio(){
	
	Polinomio *p = new Polinomio();
	p->lstM.~Lista();
};

/*
 * ordenarP --> borbulhagem - bubble sort
 */
void Polinomio::ordenarP(Polinomio *p){
	
	int dim = p->lstM.comprimento();
	Monomio aux;
	bool ordenado;
	
	do{
		ordenado = true;
		for (int i = 0; i < dim; i++){
			if (p->lstM.verI(i).grauMonomio() > p->lstM.verI(i+1).grauMonomio()){
				aux = p->lstM.verI(i);		// salvaguarda p_i
				p->lstM.retirarI(i);		// apaga p_i ficando no seu lugar p_i+1
				p->lstM.inserirI(aux);		// insere p_i na posição i+1
				ordenado = false;
			}
		}
	} while (!ordenado);
};

Polinomio* Polinomio::simplificarP(Polinomio *p){
		
	Polinomio *aux = new Polinomio();	
	int i,dim;
		
	i = 1;
	p->ordenarP(p);
	dim = p->lstM.comprimento();
	
	while(i <= dim){
		if (i == dim){
			aux->lstM.inserirI(p->lstM.verI(i));
			i++;
		}
		else if (p->lstM.verI(i).grauMonomio() == p->lstM.verI(i+1).grauMonomio()){
			aux->lstM.inserirI(p->lstM.verI(i).somaM(p->lstM.verI(i+1)));
			i = i+2;
		}
		else {
			aux->lstM.inserirI(p->lstM.verI(i));
			i++;
		}
	}
	return aux;
};

void Polinomio::eliminaZeros(Polinomio *p){
	
	int dim = p->lstM.comprimento();
	int i;
	
	for (i = 1; i <= dim; i++){
		if (p->lstM.verI(i).coeficiente() == 0){
			p->lstM.retirarI(i);
		}
	}
};

void Polinomio::lerP(int n,Polinomio *p){
	
	Monomio m;
	int _coef,_grau,i;
		
	for (i = 1; i <= n; i++){
		std::cout << " Elemento " << i << std::endl;
		std::cout << " Introduza o Coeficiente: ";
		std::cin >> _coef;
		std::cout << "" << std::endl;
		std::cout << " Introduza o Grau: ";
		std::cin >> _grau;
		std::cout << "" << std::endl;
		m.constroi(_coef,_grau);
		p->lstM.inserirI(m);
	}
};

void Polinomio::escreverP(Polinomio *p){
	
	int dim = p->lstM.comprimento();
	int i = 1;
	
	if (p->lstM.vazia()) {
		std::cout << " 0 ";
	}
	else {
		while (i < dim){
			std::cout << p->lstM.verI(i).coeficiente() << "x^" << p->lstM.verI(i).grauMonomio() << " + ";
			i++;
		}
		std::cout << p->lstM.verI(dim).coeficiente() << "x^" << p->lstM.verI(dim).grauMonomio();	
	}
};

void Polinomio::somaP(Polinomio *p1,Polinomio *p2,Polinomio *p){
			
	int dim1 = p1->lstM.comprimento();
	int dim2 = p2->lstM.comprimento();
	int i,j;
	
	i = 1;
	j = 1;
	while (i <= dim1 && j<= dim2){
		if (p1->lstM.verI(i).grauMonomio() > p2->lstM.verI(j).grauMonomio()){
			p->lstM.inserirI(p1->lstM.verI(i));
			i++;
		}
		else{
			if (p1->lstM.verI(i).grauMonomio() < p2->lstM.verI(j).grauMonomio()){
				p->lstM.inserirI(p2->lstM.verI(j));
				j++;
			}
			else{
				p->lstM.inserirI(p1->lstM.verI(i).somaM(p2->lstM.verI(j)));
				i++;
				j++;
			}
		}
	}
	while (i <= dim1 || j <= dim2){
		if (i <= dim1){
			p->lstM.inserirI(p1->lstM.verI(i));
			i++;
		}
		if (j <= dim2){
			p->lstM.inserirI(p2->lstM.verI(j));
			j++;
		}
	}
};

void Polinomio::subtracaoP(Polinomio *p1,Polinomio *p2,Polinomio *p){

	Monomio m(-1);
	
	int dim1 = p1->lstM.comprimento();
	int dim2 = p2->lstM.comprimento();
	int i,j;
	
	i=1;
	j=1;
	while (i <= dim1 && j<= dim2){
		if (p1->lstM.verI(i).grauMonomio() > p2->lstM.verI(j).grauMonomio()){
			p->lstM.inserirI(p1->lstM.verI(i));
			i++;
		}
		else{
			if (p1->lstM.verI(i).grauMonomio() < p2->lstM.verI(j).grauMonomio()){
				p->lstM.inserirI(m.multiplicacaoM(p2->lstM.verI(j)));
				j++;
			}
			else{
				p->lstM.inserirI(p1->lstM.verI(i).subtracaoM(p2->lstM.verI(j)));
				i++;
				j++;
			}
		}
	}
	while (i <= dim1 || j <= dim2){
		if (i <= dim1){
			p->lstM.inserirI(p1->lstM.verI(i));
			i++;
		}
		if (j <= dim2){
			p->lstM.inserirI(m.multiplicacaoM(p2->lstM.verI(j)));
			j++;
		}
	}
};

void Polinomio::multiplicacaoP(Polinomio *p1,Polinomio *p2,Polinomio *p){
	
	int dim1 = p1->lstM.comprimento();
	int dim2 = p2->lstM.comprimento();
	int i,j;
	
	for (i = 1; i <= dim1; i++){
		for (j = 1; j <= dim2; j++){
			p->lstM.inserirI(p1->lstM.verI(i).multiplicacaoM(p2->lstM.verI(j)));
		}
	}
};
