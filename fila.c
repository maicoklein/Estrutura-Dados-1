#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node* prox;
};
typedef struct Node node;

int tamanho;
int menu (void);
void opcao (node* FILA, int op);
void inicia (node* FILA);
int vazia (node* FILA);
node* aloca ();
void insere (node* FILA);
node* retira (node* FILA);
void exibe (node* FILA);
void libera (node* FILA);

int main (void)
{
	node* FILA = (node* ) malloc (sizeof (node));
	if (!FILA)
	{
		printf ("Memoria indisponivel!\n");
		exit (1);
	}
	else
	{
	inicia (FILA);
	int opc;

	do
	{
		opc = menu ();
		opcao (FILA, opc);
	}
	
	while (opc);
	free (FILA);
	return 0;
	}
}

int menu (void) //Exibe o menu com as opções de escolha
{
	int opc;

	printf ("Escolha a opcao\n");
	printf ("0. Sair\n");
	printf ("1. Zerar fila\n");
	printf ("2. Exibir fila\n");
	printf ("3. Adicionar Elemento na Fila\n");
	printf ("4. Retirar Elemento da Fila\n");
	printf ("Opcao: "); scanf ("%d", &opc);

	return opc;
}

void opcao (node* FILA, int opc) //Eh executada a opcao escolhida pelo usuario
{
	node* tmp;
	switch (opc){
		case 0:
			libera (FILA);
			break;

		case 1:
			libera (FILA);
			inicia (FILA);
			break;

		case 2:
			exibe (FILA);
			break;

		case 3:
			insere (FILA);
			break;

		case 4:
			tmp= retira (FILA);
			if (tmp != NULL){
				printf ("Retirado: %3d\n\n", tmp->num);
				free (tmp);
			}
			break;

		default:
			printf ("Comando invalido\n\n");
	}
}

void inicia (node* FILA) //Inicia o ponteiro da fila
{
	FILA->prox = NULL;
	tamanho = 0;
}

int vazia (node* FILA) //Verifica se a fila está vazia
{
	if (FILA->prox == NULL)
		return 1;
	else
		return 0;
}

node* aloca () //Aloca novo ponteiro
{
	node* novo = (node* ) malloc (sizeof (node));
	if (!novo)
	{
		printf ("Memoria indisponivel!\n");
		exit (1);
	}
	else
	{
		printf ("Novo elemento: "); scanf ("%d", &novo->num);
		return novo;
	}
}

void insere (node* FILA) //Insere novo elemento na fila
{
	node* novo = aloca ();
	novo->prox = NULL;

	if (vazia (FILA))
		FILA->prox = novo;
	else
	{
		node* tmp = FILA->prox;

		while (tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	tamanho++;
}
	
node* retira (node* FILA) //Retira o elemento da fila que por primeiro entrou
{
	if (FILA->prox == NULL)
	{
		printf ("Fila ja esta vazia\n");
		return NULL;
	}
	else
	{
		node* tmp = FILA->prox;
		FILA->prox = tmp->prox;
		tamanho--;
		return tmp;
	}

}

void exibe (node* FILA) //Exibe os elementos da fila
{
	if (vazia (FILA))
	{
		printf ("Fila vazia!\n\n");
		return ;
	}

	node* tmp;
	tmp = FILA->prox;
	printf ("Fila :");
	while ( tmp != NULL)
	{
		printf ("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf ("\n        ");
	int cont;
	for (cont = 0 ; cont < tamanho ; cont++)
		printf ("  ^  ");
	printf ("\nOrdem:");
	for (cont = 0 ; cont < tamanho ; cont++)
		printf ("%5d", cont+1);


	printf ("\n\n");
}

void libera (node* FILA) //Apaga os ponteiros que apontamanho os elementos da memória
{
	if (!vazia (FILA))
	{
		node* proxNode,
			 * atual;

		atual = FILA->prox;
		while (atual != NULL)
		{
			proxNode = atual->prox;
			free (atual);
			atual = proxNode;
		}
	}
}

