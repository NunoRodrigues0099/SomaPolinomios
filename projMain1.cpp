/*
 * projMain1.cpp
 * 
 * Este programa foi construido com o intuito de fazer operações
 * elementares (adição, subtração e multiplicação)
 * entres dois polinómios introduzidos por um utilizador.
 * 
 * Trabalho realizado por:
 * 	Alice Conceiçao (2018295146)
 * 	Nuno Rodrigues  (2018282528)
 * 	Grupo 4
 */

#include <iostream>
#include "monomio.hpp"
#include "listaGenerica.cpp"
#include "polinomio.hpp"

// Funções Auxiliares

// Menu de Apresentação
void apresentacao();

// Menu Principal
void menu();

// Cria um polinómio
void criarP1(int,Polinomio*);

// Cria um polinómio
void criarP2(int,Polinomio*);

void somaMain(Polinomio*,Polinomio*,Polinomio*);

void subtracaoMain(Polinomio*,Polinomio*,Polinomio*);

void multiplicacaoMain(Polinomio*,Polinomio*,Polinomio*);

void apresentacao(){
	
	std::cout<<"\n\n";    
	std::cout<<"***********************************************\n";
	std::cout<<"***********************************************\n";
	std::cout<<"*                    FCTUC                    *\n";
	std::cout<<"*          DEPARTAMENTO DE MATEMATICA         *\n";
	std::cout<<"***********************************************\n";
	std::cout<<"*    Programaçao Orientada para os Objetos    *\n";
	std::cout<<"*           Professor Pedro Quaresma          *\n";
	std::cout<<"*             Ano Letivo 2020/2021            *\n";
	std::cout<<"*                  Projeto 1                  *\n";
	std::cout<<"***********************************************\n";  
	std::cout<<"*    Trabalho realizado por:                  *\n";
	std::cout<<"*    - Alice Conceiçao (2018295146)           *\n";
	std::cout<<"*    - Nuno Rodrigues  (2018282528)           *\n";
	std::cout<<"*      Grupo 4                                *\n";
	std::cout<<"***********************************************\n";
	std::cout<<"***********************************************\n";
}

void menu(){
	
	std::cout<<"\n\n";    
	std::cout<<"***********************************************\n";
	std::cout<<"***********************************************\n";
	std::cout<<"***** PROGRAMA : OPERACOES COM POLINOMIOS *****\n";
	std::cout<<"*                    V 1.0                    *\n";
	std::cout<<"***********************************************\n";
	std::cout<<"*                     MENU                    *\n";
	std::cout<<"***********************************************\n";
	std::cout<<"* 1 - Adiçao                                  *\n";
	std::cout<<"* 2 - Subtraçao                               *\n";
	std::cout<<"* 3 - Multiplicaçao                           *\n";
	std::cout<<"* 0 - Sair                                    *\n";
	std::cout<<"***********************************************\n";
	std::cout<<"* Opçao:                                      *\n";
}

//criar polinómio1
void criarP1(int n,Polinomio*p1 ){
	
	std::cout<<"Polinómio 1\n";
	do {
		std::cout << "Número de Elementos: ";
		std::cin >> n;
	} while (n<=0);
	p1->lerP(n,p1);
	p1->ordenarP(p1);
	p1 = p1->simplificarP(p1);
	p1->eliminaZeros(p1);
	std::cout<<"P1: ";
	p1->escreverP(p1);
	std::cout<<"\n\n";
}

//criar polinómio2
void criarP2(int n,Polinomio *p2){
	std::cout<<"Polinómio 2\n";
	do {
		std::cout << "Número de Elementos: ";
		std::cin >> n;
	} while (n<=0);
	p2->lerP(n,p2);
	p2->ordenarP(p2);
	p2 = p2->simplificarP(p2);
	p2->eliminaZeros(p2);
	std::cout<<"P2: ";
	p2->escreverP(p2);	
	std::cout<<"\n\n";
}

void somaMain(Polinomio *p1,Polinomio *p2,Polinomio *p3) {
	p3->somaP(p1,p2,p3);
	std::cout << "Soma:\np = ";
	p3->ordenarP(p3);
	p3 = p3->simplificarP(p3);
	p3->eliminaZeros(p3);
	p3->escreverP(p3);
}

void subtracaoMain(Polinomio *p1,Polinomio *p2,Polinomio *p3) {
	p3->subtracaoP(p1,p2,p3);
	std::cout << "Subtração:\np = ";
	p3->ordenarP(p3);
	p3 = p3->simplificarP(p3);
	p3->eliminaZeros(p3);
	p3->escreverP(p3);
}

void multiplicacaoMain(Polinomio *p1,Polinomio *p2,Polinomio *p3) {
	p3->multiplicacaoP(p1,p2,p3);
	std::cout << "Multiplicação:\np = ";
	p3->ordenarP(p3);
	p3 = p3->simplificarP(p3);
	p3->eliminaZeros(p3);
	p3->escreverP(p3);
}

// Main
				
int main(int argc, char **argv)
{
	Polinomio *p1 = new Polinomio();
	Polinomio *p2 = new Polinomio();
	Polinomio *p3 = new Polinomio();
	int n,op;
	
	apresentacao();
	do {
		menu();
		std::cin >> op;
		system("clear");
		fflush(stdin);
		switch(op){
		case(1):
			std::cout<<"***********************************************\n";
			std::cout<<"*             Soma de 2 Polinomios            *\n";
			std::cout<<"***********************************************\n";
			
			//criar polinómio1
			criarP1(n,p1);
			
			//criar polinómio2
			criarP2(n,p2);
			
			//soma
			somaMain(p1,p2,p3);
			
			// apaga os polinómios criados
			p1->~Polinomio();
			p2->~Polinomio();
			p3->~Polinomio();
			break;
		case(2):
			std::cout<<"***********************************************\n";
			std::cout<<"*         Subtração entre 2 Polinomios        *\n";
			std::cout<<"***********************************************\n";
			
			//criar polinómio1
			criarP1(n,p1);
			
			//criar polinómio2
			criarP2(n,p2);
			
			//subtração
			subtracaoMain(p1,p2,p3);
			
			// apaga os polinómios criados
			p1->~Polinomio();
			p2->~Polinomio();
			p3->~Polinomio();
			break;
		case(3):
			std::cout<<"***********************************************\n";
			std::cout<<"*       Multiplicação entre 2 Polinomios      *\n";
			std::cout<<"***********************************************\n";
			
			//criar polinómio1
			criarP1(n,p1);
			
			//criar polinómio2
			criarP2(n,p2);
			
			//produto
			multiplicacaoMain(p1,p2,p3);
			
			// apaga os polinómios criados
			p1->~Polinomio();
			p2->~Polinomio();
			p3->~Polinomio();
			break;
		case(0):
			std::cout<<"***********************************************\n";
			std::cout<<"* Programa encerrado!                         *\n";
			std::cout<<"***********************************************\n";
			break;
		default:
			std::cout<<"***********************************************\n";
			std::cout<<"* Opçao invalida!                             *\n";
			std::cout<<"***********************************************\n";
		}
	} while (op != 0);
	return 0;
}
