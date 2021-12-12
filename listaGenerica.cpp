/*
 * listaGenerica.cpp
 */

#ifndef LISTAGENERICA
#define LISTAGENERICA

#include <iostream>
#include "monomio.hpp"

/*
 * Lista de Elementos (Genéricos)
 */
template <class Elementos>
class Lista {
private:

	// Nós da Lista
	struct NoLista {
		
		Elementos elem;
		NoLista *proxNo;
	};
	NoLista *ptLista; // apontador para o primeiro elemento
	
	// define como vazios (e privados) os construtores por cópia e por
	// atribuição
	Lista (const Lista &){}
	void operator=(const Lista &){}
	
public:

	// Construtor
	Lista(){
		
		ptLista = NULL;
	};
	
	// Destrutor
	~Lista(){
		
		NoLista *aux;
		while (ptLista != NULL){
			
			aux = ptLista;
			ptLista = ptLista->proxNo;
			delete aux;
		}
	};
	
	// Manipuladores
	
	/*
	 * inserirI - insere o elemento "elem" no fim da lista.
	 * --> lista (ímplicita), elem
	 * <-- lista com um novo elemento
	 */
	void inserirI(Elementos elemento){
		
		if (ptLista == NULL){
			ptLista = new NoLista;
			ptLista->elem = elemento;
			ptLista->proxNo = NULL;
		}
		else{
			NoLista *aux = ptLista;
			while (aux->proxNo != NULL){
				aux = aux->proxNo;
			}
			aux->proxNo = new NoLista;
			aux = aux->proxNo;
			aux->elem = elemento;
			aux->proxNo = NULL;
		}
	};
	
	/*
	 *retirarI - remove o elemento da posição "posicao".
	 * Se "posicao" estiver para além do fim da lista devolve
	 * o valor falso e não retira nenhum elemento nos outros casos
	 * devolve o valor verdade e retira o elemento em causa 
	 * --> lista (ímplicita), posicao
	 * <-- verdade, a lista (com o elemento retirado)
	 * 	   falso, lista (não alterada, "posicao", valor incorreto)
	 */
	bool retirarI(int posicao){
		
		NoLista *ant=NULL, *prox=ptLista;
		int i=1;
		
		while (i < posicao && prox != NULL){
			ant = prox;
			prox = prox -> proxNo;
			i++;
		}
		if (prox != NULL){
			if (ant == NULL){
				ptLista = prox->proxNo;
			}
			else{
				ant->proxNo = prox->proxNo;
			}
			delete prox;
			return (true);
		}
		else{
			return(false);
		}
	};
	
	/*
	 * verI - devolve o elemento da posição "posicao".
	 * Devolve o último elemento da lista no caso da posição requerida
	 * estar para além do fim da lista
	 * --> lista (ímplicita), posicao
	 * <-- elem (o elemento na posição "posicao")
	 */
	Elementos verI(int posicao){
		
		NoLista *pos=ptLista;
		int i=1;
		
		while (i < posicao && pos->proxNo != NULL){
			pos = pos->proxNo;
			i++;
		}
		return pos->elem;
	};
	
	/* vazia - verifica se a lista está ou não vazia
	 * --> lista (ímplicita)
	 * <-- verdade, a lista está vazia
	 * 	   falso, lista não está vazia
	 */ 
	bool vazia(){
		return ptLista == NULL;
	};
	
	/*
	 * comprimento - devolve o número de elementos da lista
	 * --> lista (ímplicita)
	 * <-- n (número de elementos na lista)
	 */
	int comprimento(){
		
		NoLista *pos = ptLista;
		int cmp=0;
		
		while (pos != NULL){
			pos = pos->proxNo;
			cmp++;
		}
		return cmp;
	};
};

#endif
