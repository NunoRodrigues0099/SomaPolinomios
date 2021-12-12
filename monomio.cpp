/*
 * monomio.cpp
 */

#include <iostream>
#include "monomio.hpp"

Monomio::Monomio(){
	
	coef = 0;
	grau = 0;
};

Monomio::Monomio(int _coef){
	
	coef = _coef;
	grau = 0;
};

Monomio::Monomio(int _coef, int _grau){
	
	coef = _coef;
	grau = _grau;
};

void Monomio::constroi(int _coef, int _grau){
	
	coef = _coef;
	grau = _grau;
};

int Monomio::coeficiente(){
	
	return coef;
};

int Monomio::grauMonomio(){
	
	return grau;
};

void Monomio::escreverM(){
	
	std::cout << coef << "x^" << grau << std::endl;
};

Monomio Monomio::somaM(Monomio m1){
	
	if (grau == m1.grauMonomio()){
		return (Monomio(coef+m1.coeficiente(),grau));
	}
	else {
		std::cout << "Monómios de Graus diferentes!" << std::endl;
		return 0;
	}
};

Monomio Monomio::subtracaoM(Monomio m1){
	
	if (grau == m1.grauMonomio()){
		return (Monomio(coef-m1.coeficiente(),grau));
	}
	else {
		std::cout << "Monómios de Graus diferentes!" << std::endl;
		return 0;
	}
};

Monomio Monomio::multiplicacaoM(Monomio m1){
	
	return (Monomio(coef*m1.coeficiente(),grau+m1.grauMonomio()));
};
