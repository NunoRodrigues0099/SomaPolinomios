/*
 * monomio.hpp
 */

#ifndef MONOMIO
#define MONOMIO

class  Monomio {
private:
	int coef;
	int grau;
public:

	/*
	 * Construtor com 0 argumentos --> 0.x^0
	 */
	Monomio();
	
	/*
	 * Construtor com 1 argumento a --> a.x^0
	 */
	Monomio(int);
	
	/*
	 * Construtor com 2 argumentos a, n --> a.x^n
	 */
	Monomio(int,int);
	
	/*
	 * Dados dois inteiros (coeficiente, grau) constrói um monómio
	 */
	void constroi(int,int);
	
	/*
	 * Dado um monómio devolve o seu coeficiente
	 */
	int coeficiente();
	
	/*
	 * Dado um monómio devolve o seu grau
	 */
	int grauMonomio();
	
	/*
	 * Escrever Monómio
	 * --> monómio
	 * <-- escreve a.x^b, a => coeficiente, b => grau
	 */
	 void escreverM();
	
	/*
	 * Soma de Monómios
	 * a,c => coeficiente, b,d => grau
	 * --> m1 = a.x^b, m2 = c.x^d
	 * <-- m3 = m1 + m2 = (a+b).x^b, se e só se b = d
	 */
	Monomio somaM(Monomio);
	
	/*
	 * Subtração de Monómios
	 * a,c => coeficiente, b,d => grau
	 * --> m1 = a.x^b, m2 = c.x^d
	 * <-- m3 = m1 - m2 = (a-b).x^b, se e só se b = d
	 */
	Monomio subtracaoM(Monomio);
	
	/*
	 * Multiplicação de Monómios
	 * a,c => coeficiente, b,d => grau
	 * --> m1 = a.x^b, m2 = c.x^d
	 * <-- m3 = m1*m2 = (a*b).x^(b+d)
	 */
	Monomio multiplicacaoM(Monomio);
};

#endif
