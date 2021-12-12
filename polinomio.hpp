/*
 * polinomio.hpp
 */

#ifndef POLINOMIO
#define POLINOMIO

#include "monomio.hpp"
#include "listaGenerica.cpp"

/*
 * Lista de Monómios 
 */
class Polinomio {
private:
	
	// Instanciação da lista de monómios
	Lista <Monomio> lstM;
		
public:

	// Construtor
	Polinomio();
	
	// Destrutor
	~Polinomio();

	/*
	 * ordenarP - ordena um polinómio por 
	 * ordem crescente do grau de cada monómio
	 * --> polinómio
	 * <-- polinómio ordenado (ímplicito)
	 */
	void ordenarP(Polinomio*);
		
	/*
	 * simplificarP - simplifica o polinómio somando os
	 * coeficientes dos monómios de igual grau
	 * --> polinómio
	 * <-- polinómio simplificado (ímplicito)
	 */
	Polinomio* simplificarP(Polinomio*);
	
	/*
	 * eliminaZeros - elimina todos os monómios do polinómio,
	 * cujo coeficiente é zero
	 * --> polinómio
	 * <--
	 */
	void eliminaZeros(Polinomio*);
	
	/*
	 * lerP - faz a leitura do polinómio
	 * --> int, polinómio
	 * <-- polinómio (ímplicito)
	 */
	void lerP(int,Polinomio*);
	
	/*
	 * escreverP - escrever um polinómio (a.x^b + c.x^d ...)
	 * --> polinómio
	 * <-- polinómio (ímplicito)
	 */
	void escreverP(Polinomio*);
	
	/*
	 * somaP - soma dois polinómios
	 * --> p1,p2,p3
	 * <-- p3 = p1 + p2
	 */
	void somaP(Polinomio*,Polinomio*,Polinomio*);
	
	/*
	 * subtracaoP - diferença entre dois polinómios
	 * --> p1,p2,p3
	 * <-- p3 = p1 - p2
	 */
	void subtracaoP(Polinomio*,Polinomio*,Polinomio*);
	
	/*
	 * multiplicacaoP - produto dois polinómios
	 * --> p1,p2,p3
	 * <-- p3 = p1*p2
	 */
	void multiplicacaoP(Polinomio*,Polinomio*,Polinomio*);	
};
#endif
