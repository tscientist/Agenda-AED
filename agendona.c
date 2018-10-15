/*
	Caroline de Souza
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct agenda{
	char nome[40];
	char telefone[10];
}AGENDA;

typedef struct variaveis{
	int i, j, escolha, num_contatos, tam_buffer, flag;
	char nome_pesquisa[40];
}VARIAVEIS;

	void* incluir(void *pBuffer){
		VARIAVEIS *var;
		AGENDA *contato;
		void *buffer_aux;

		var = pBuffer;

		var->tam_buffer = var->tam_buffer + sizeof(VARIAVEIS);
		pBuffer = realloc(pBuffer, var->tam_buffer);
		var = pBuffer;

		buffer_aux = pBuffer;
		buffer_aux = buffer_aux +sizeof(VARIAVEIS);
		buffer_aux = buffer_aux + sizeof(AGENDA) * (var->num_contatos);
		contato = buffer_aux;

		printf("Nome: ");
		scanf("%s", contato->nome);
		printf("Numero: ");
		scanf("%s", contato->telefone);

		var->num_contatos++;

		return pBuffer;
	}


/*
		var = pBuffer;
		var->cont++;
		pBuffer=realloc(pBuffer,sizeof(AGENDA));
		buffer_aux=pBuffer;

		for(var->i=0;var->i<var->cont;var->i++){
			buffer_aux++;
		}
		contato = buffer_aux;
		printf("Nome: ");
		scanf("%s", &contato->nome)
		contato->nome[strcspn(contato->nome,"/n")]=0;
		printf("Numero: ");
		scanf("%d", &contato->telefone)
		contato->telefone[strcspn(contato->telefone,"/n")]=0;
*/

	void listar(void *pBuffer){
			VARIAVEIS *var;
			AGENDA *contato;
			void *buffer_aux;

			buffer_aux = pBuffer;
			var = pBuffer;


		if(var->num_contatos >0){
				buffer_aux = buffer_aux +sizeof(VARIAVEIS);
				contato = buffer_aux;
				for (var->i = 0; var->i < var->num_contatos; ++var->i){
							printf("Nome: %s\n", contato[var->i].nome);
							printf("Telefone: %s\n",contato[var->i].telefone);
				}
			}else{
				printf("---------------------------\n");
				printf("Não existem contatos salvos\n");
					printf("Escolha outra opção!!!\n");
				printf("---------------------------\n");


		}
	}
	void* apagar(void *pBuffer){
			VARIAVEIS *var;
			AGENDA *contato;
			void *buffer_aux;

			buffer_aux = pBuffer;
			var = pBuffer;

			var->flag=0;

			if(var->num_contatos >0){
				buffer_aux = buffer_aux +sizeof(VARIAVEIS);
				contato = buffer_aux;

				printf("Digite o nome do contato:\n");
				scanf("%s", var->nome_pesquisa);

				for (var->i = 0; var->i < var->num_contatos; ++var->i){
					if((strcmp(var->nome_pesquisa, contato[var->i].nome))==0){
						var->flag++;
						for(var->j = var->i; var->j < var->num_contatos; var->j++){
							contato[var->j] = contato[var->j+1];
						}
						var->num_contatos = var->num_contatos -1;
						var->tam_buffer = var->tam_buffer - sizeof(AGENDA);
						pBuffer = realloc(pBuffer, var->tam_buffer);
					}
				}
				if(var->flag!=0){
					printf("Nenhum contato com esse nome foi encontrado\n");
				}

			}else{
				printf("---------------------------\n");
				printf("Não existem contatos salvos\n");
				printf("Escolha outra opção!!!\n");
				printf("---------------------------\n");
			}
			return pBuffer;

	}
	void buscar(void *pBuffer){
			VARIAVEIS *var;
			AGENDA *contato;
			void *buffer_aux;
			buffer_aux = pBuffer;
			var = pBuffer;

			var->flag =0;

			if(var->num_contatos >0){
				buffer_aux = buffer_aux +sizeof(VARIAVEIS);
				contato = buffer_aux;
				printf("Digite o nome do contato:\n");
				scanf("%s", var->nome_pesquisa);

				for (var->i = 0; var->i < var->num_contatos; ++var->i){
					if((strcmp(var->nome_pesquisa, contato[var->i].nome))==0){
							printf("Nome: %s\n", contato[var->i].nome);
							printf("Telefone: %s\n",contato[var->i].telefone);
							var->flag++;
					}
				}
				if(var->flag!=0){
					printf("Nenhum contato com esse nome foi encontrado\n");
				}

			}else{
				printf("---------------------------\n");
				printf("Não existem contatos salvos\n");
					printf("Escolha outra opção!!!\n");
				printf("---------------------------\n");
		}
	}
void* bubbleSort(void *pBuffer){
		VARIAVEIS *var;
		AGENDA *contato;
		void *buffer_aux;

		var = pBuffer;

		var->tam_buffer = var->tam_buffer + sizeof(AGENDA);
		pBuffer = realloc(pBuffer, var->tam_buffer);
		var = pBuffer;

		var->num_contatos = var->num_contatos +1;
		buffer_aux = pBuffer;

		buffer_aux = buffer_aux +sizeof(VARIAVEIS);
		buffer_aux = buffer_aux +sizeof(AGENDA)*(var->tam_buffer-1);
        contato = buffer_aux;

		for(var->i = 0; var->i < var->num_contatos-2; var->i++){
            for(var->j = 0; var->j < var->num_contatos-1 - var->num_contatos-2; var->j++){
                if(contato[var->j].nome[0] > contato[var->j + 1].nome[0]){
                    contato[var->num_contatos-1] = contato[var->j];
                    contato[var->j] = contato[var->j+1];
                    contato[var->j+1] = contato[var->num_contatos-1];
                }
            }
        }
    var->num_contatos = var->num_contatos - 1;
    var->tam_buffer = var->tam_buffer - sizeof(AGENDA);
    pBuffer = realloc(pBuffer, var->tam_buffer);

    printf("\nAgenda ordenada!\n");
    return pBuffer;
}
void* insertionSort(void *pBuffer){
    void *buffer_aux;
    VARIAVEIS *var;
    AGENDA *contato, *aux;

    var = pBuffer;
    buffer_aux = pBuffer;

    buffer_aux = buffer_aux + sizeof(VARIAVEIS);
    contato = buffer_aux;
    aux = contato + sizeof(AGENDA) * (var->num_contatos-1);

    for(var->j =0; var->j < var->num_contatos; var->j++){
        var->i = var->j - 1;
        aux[0] = contato[var->j];

        while((var->i >= 0) && (aux[0].nome[0] < contato[var->i].nome[0])){
            contato[var->i+1] = contato[var->i];
            var->i--;
        }
        contato[var->i+1] = aux[0];

    }

    printf("\nAgenda ordenada!\n");
    return pBuffer;

}


void menu(void *pBuffer){
		VARIAVEIS *p;
		p=pBuffer;
	do{
	printf("Agenda");
	printf("\nEscolha uma opção!");
	printf("\n1 - Incluir");
	printf("\n2 - Apagar");
	printf("\n3 - Listar");
	printf("\n4 - Buscar");
    printf("\n5 - Ordenar: bubble");
    printf("\n6 - Ordenar: insertion");
	printf("\n0 - Encerrar\n");
	scanf("%d", &p->escolha);
	switch(p->escolha){
		case 0:
			printf("Programa encerrado");
		break;
		case 1:
			pBuffer=incluir(pBuffer);
		break;
		case 2:
			pBuffer = apagar(pBuffer);
		break;
		case 3:
			listar(pBuffer);
		break;
		case 4:
			buscar(pBuffer);
		break;
        case 5:
			bubbleSort(pBuffer);
		break;
        case 6:
			insertionSort(pBuffer);
		break;
		default:
				printf("Opção invalida");
		break;
	}
}while(p->escolha);//while(p->repetir!=0);
}

void menu2(){
//int main(){
	void *pBuffer;
	VARIAVEIS *var;

	pBuffer=malloc(sizeof(VARIAVEIS));

	var = pBuffer;
	var->num_contatos=0;
	var->tam_buffer= sizeof(VARIAVEIS);

	if(pBuffer==NULL){
			printf("Erro!");
			exit(1);
	}
	menu(pBuffer);
}
