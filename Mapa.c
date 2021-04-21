#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define max_clientes 5

typedef struct {
	int codigo;
	char nome[50];
	char telefone[50];
	char email[50];
	int ativo;
	int cont;
} Agenda;
Agenda clientes[max_clientes];

void telaInicial();
void inserir();
void cadastros();

int main() 
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	telaInicial();

	return 0;
}

void telaInicial(){
	int op;
	do{
		system("cls");
		printf("_ _ _ _ _ _ _ AGENDA BETA _ _ _ _ _ _ _\n\n");
		printf("1 - INSERIR UM NOVO CADASTRO \n");
		printf("2 - MOSTRAR TODOS OS CADASTROS \n");
		printf("0 - ENCERRAR \n\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		fflush (stdin);
		printf("_______________________________________\n\n");
		if (op == 1){
			inserir();
		}else{
			if (op == 2){
				cadastros();
			}else{
				if (op > 2){
					printf("Erro: opção inválida!\n\n");
					system("pause");					
				}

			}
		}
	}while(op != 0);
}

void inserir(){
	int codigo;
	char nome[50];
	char telefone[50];
	char email[50];
	int op, i;

	system ("cls");
		
	if (clientes[4].cont == 4)
	{
		printf("_ _ _ _ _ _ _ Cadastro de cliente _ _ _ _ _ _ _\n\n");
		printf("Agenda lotada!\n\n");
		printf("________________________________________________\n\n");
		system("pause");
	}else{
		codigo = rand() % 1000;
				
		printf("_ _ _ _ _ _ _ Cadastro de cliente _ _ _ _ _ _ _\n\n");
		printf("Insira o nome do cliente: \n");
		gets(nome);
		fflush(stdin);
				
		printf("Insira o numero de telefone: \n");
		gets(telefone);
		fflush(stdin);
						
		printf("Insira o e-mail: \n");
		scanf("%s", email);
		fflush(stdin);
				
		for (i = 0; i < max_clientes; ++i)
		{
			if (clientes[i].ativo == 0)
			{
			clientes[i].codigo = codigo;
			strcpy(clientes[i].nome, nome);
			strcpy(clientes[i].telefone, telefone);
			strcpy(clientes[i].email, email);
			clientes[i].ativo = 1;
			clientes[i].cont = i;
			break;
			}
		}
	}	
}
	
void cadastros(){
	system ("cls");
	int i;
	
	printf("_ _ _ _ _ _ _ Clientes cadastrados _ _ _ _ _ _ _\n\n");
	if (clientes[i].ativo != 0){
		for (i = 0; i < max_clientes; ++i)
		{
			if (clientes[i].ativo == 1)
			{
			printf("Código: %d\n", clientes[i].codigo);
			printf("Nome: %s\n", clientes[i].nome);
			printf("Telefone: %s\n", clientes[i].telefone);
			printf("E-mail: %s\n", clientes[i].email);
			printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\n");			
			}
		}
	}else{
		printf("Agenda Vazia!\n");
	}
	printf("________________________________________________\n\n");
	system("pause");
}

