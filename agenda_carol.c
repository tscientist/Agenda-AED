/*
	Caroline de Souza
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
typedef struct agenda{
	char nome[40], telefone[10];
}AGENDA;	

typedef struct variaveis{
	int i, escolha, cont, repetir;
}VARIAVEIS;
	
	void incluir(void *pBuffer){
		VARIAVEIS *var;
		AGENDA *contato;
		void *aux;
		var = pBuffer;
		var->cont++;
		pBuffer=realloc(pBuffer,sizeof(AGENDA));
		aux=pBuffer;
		
		for(var->i=0;var->i<var->cont;var->i++){
			aux++;
		}
		contato = aux;	
		printf("Nome:");
		scanf("%d", &contato->nome);
		printf("Numero:");
		scanf("%d", &contato->telefone);

	}
	void listar(void *pBuffer){
		VARIAVEIS *var;
		AGENDA *contato;
		var = pBuffer;
		contato = pBuffer;	

		for(var->i=0;var->i<var->cont;var->i++){
			printf("Nome: %s", contato->nome);
			printf("Telefone: %s",contato->telefone);

		}
	}
	void apagar(void *pBuffer){
			printf("tada3");
	}
	
void menu(void *pBuffer){
		VARIAVEIS *p;
		p=pBuffer;
	do{
	printf("Agenda");
	printf("\nEscolha uma opção!");
	printf("\n1 - Incluir");
	printf("\n2 - Apagar");
	printf("\n3 - Listar\n");	
	scanf("%d", &p->escolha);
	switch(p->escolha){
		case 1:
			incluir(pBuffer);
		break;
		case 2:
			apagar(pBuffer);
		break;
		case 3:
			listar(pBuffer);
		break;		
		default:
				printf("Opção invalida");
		break; 
	}
	printf("deseja continuar?");
	scanf("%d", &p->repetir);
}while(p->repetir!=0);
}
int main(){
	void *pBuffer;
	pBuffer=malloc(sizeof(VARIAVEIS));
	if(pBuffer==NULL){
			printf("Erro!");
			exit(1);
	}
	menu(pBuffer);	
}

