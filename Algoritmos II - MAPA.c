#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 200

typedef struct dados{
	int codigo;
	char titulo[30];
    char descricao[100];
    int data;
    int status;
    char gerente[30];
    int tempo;
    char linguagem[30];
    char cliente[50];
}projetos;

int posicao = 0;

void cadastrarProjeto(projetos cadastro[MAX]);
void relatorioProjeto(projetos cadastro[MAX]);
void buscarAfazer(projetos cadastro[MAX]);
void buscarFazendo(projetos cadastro[MAX]);
void buscarConcluido(projetos cadastro[MAX]);
void buscarNome(projetos cadastro[MAX]);

int main(){
	setlocale(LC_ALL, "Portuguese");
	projetos cadastro[MAX];
	
	int escolha;

	
	system("cls");	
	do{
		system("cls");
		printf("****************************************************");
		printf("\n GESTAO DE PROJETOS ");
		printf("\n****************************************************");
		printf("\n 1 - Cadastrar Projeto");
		printf("\n 2 - Imprimir Todos os Projetos");
		printf("\n 3 - Imprimir todos os projetos com status A Fazer");
		printf("\n 4 - Imprimir todos os projetos com status Fazendo");
		printf("\n 5 - Imprimir todos os projetos com status Concluido");
		printf("\n 6 - Busca por Nome");
		printf("\n 7 - Sair");
		printf("\n << Escolha uma opcao do menu: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrarProjeto(cadastro);			
				break;
			case 2:
				relatorioProjeto(cadastro);
				break;
			case 3:
				buscarAfazer(cadastro);
				break;
			case 4:
				buscarFazendo(cadastro);
				break;
			case 5:
				buscarConcluido(cadastro);
				break;
			case 6:
				buscarNome(cadastro);
				break;
			case 7:
				printf("\nSaindo da Aplicacao\n");
				system("Pause");
				break;
			default:
				printf("\nEscolha incorreta\n");
				system("Pause");
		}
	}while(escolha != 7);
	return 0;
}

void cadastrarProjeto(projetos cadastro[MAX]){
	int cod;
    int selecionarStatus;
    char statusSelecionado;
	system("cls");
	printf("***************************************");
	printf("\n CADASTRO");
	printf("\n***************************************");
	char resp = 's';
	
	while(resp == 's' && posicao <= MAX){
		posicao++;
		printf("\nCodigo: %d ", posicao);
		//scanf("%d", &cadastro[posicao].codigo);
		cadastro[posicao].codigo = posicao;
		printf("\nInforme o projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].titulo);
        printf("\nInforme a descricao do projeto: ");
        fflush(stdin);
        gets(cadastro[posicao].descricao);
        printf("\nInforme o ano: ");
        fflush(stdin);
        scanf("%d", &cadastro[posicao].data);
        printf("\nSelecione o status do projeto:");
		teste: printf("\n1 - A Fazer | 2 - Fazendo | 3 - Concluido: ");
		fflush(stdin);
		scanf("%d", &cod);
		switch (cod)
		{
		case 1:
			cadastro[posicao].status=1;
			break;
		case 2:
			cadastro[posicao].status = 2;
			break;
		case 3:
			cadastro[posicao].status = 3;
			break;
		default:
			printf("Código incorreto.");
			goto teste;
		}
		next: printf("\nInforme o gerente do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].gerente);
		printf("\nInforme a duracao do projeto: ");
		fflush(stdin);
		scanf("%d", &cadastro[posicao].tempo);
		printf("\nInforme a linguagem do projeto: ");
		fflush(stdin);
		gets(cadastro[posicao].linguagem);
		printf("\nInforme o cliente: ");
		fflush(stdin);
		gets(cadastro[posicao].cliente);

			if (posicao < MAX)
			{
				printf("\n\nDeseja cadastrar novo Projeto? [s] Sim [n] Nao: ");
				fflush(stdin);
				scanf("%c", &resp);
			}
			else
			{
				printf("\nVoc� atingiu o limite de 200 projetos.\n");
				resp = 'n';
			}
		}
}
void relatorioProjeto(projetos cadastro[MAX]){
	system("cls");
	printf("***************************************");
	printf("\n RELATORIO ");
	printf("\n***************************************\n");
	int linha=1;
	
	if(posicao >= 1){
		while(linha <= posicao){
			printf("%d - %s\n", cadastro[linha].codigo, cadastro[linha].titulo);
            printf("Descricao: %s\n", cadastro[linha].descricao);
            printf("Ano: %d\n", cadastro[linha].data);
			printf("Status: ");
			switch (cadastro[linha].status)
			{
			case 1:
				printf("A Fazer\n");
				 break;

			case 2:
				printf("Fazendo\n"); 
				break;

			case 3:
				printf("Concluido\n"); 
				break;

			default:
				break;
			}
            printf("Gerente: %s\n", cadastro[linha].gerente);
            printf("Duracao do Projeto: %d\n", cadastro[linha].tempo);
            printf("Linguagem: %s\n", cadastro[linha].linguagem);
            printf("Cliente: %s\n", cadastro[linha].cliente);
			printf("\n***************************************\n");


			linha++;
        }	
			
	}else{
		printf("\nSem Registros Cadastrados\n");
	}	
	system("Pause");
}

void buscarAfazer(projetos cadastro[MAX])
{
	system("cls");
	int codigo, achou;
	printf("***************************************");
	printf("\n Imprimir todos os projetos com Status: A Fazer. ");
	printf("\n***************************************");
	achou = 0;
	int j = 0;
	while((achou == 0) && (j <= posicao)){
		if(1 == cadastro[j].status){
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].titulo);
			printf("Descricao: %s\n", cadastro[j].descricao);
			printf("Ano: %d\n", cadastro[j].data);
			printf("Status: ");
			switch (cadastro[j].status)
			{
			case 1:
				printf("A Fazer\n");
				break;

			case 2:
				printf("Fazendo\n");
				break;

			case 3:
				printf("Concluido\n");
				break;

			default:
				break;
			}
			printf("Gerente: %s\n", cadastro[j].gerente);
			printf("Duracao do Projeto: %d\n", cadastro[j].tempo);
			printf("Linguagem: %s\n", cadastro[j].linguagem);
			printf("Cliente: %s\n", cadastro[j].cliente);
			printf("\n***************************************\n");
			achou = 1;
			system("Pause");
		}
		j++;
	}
		if(achou == 0 ){
			printf("\nRegistro nao encontrado com o Status: A Fazer.");
			system("Pause");
		}
}

void buscarFazendo(projetos cadastro[MAX])
{
	system("cls");
	int codigo, achou;
	printf("***************************************");
	printf("\n Imprimir todos os projetos com Status: Fazendo. ");
	printf("\n***************************************");
	achou = 0;
	int j = 0;
	while ((achou == 0) && (j <= posicao))
	{
		if (2 == cadastro[j].status)
		{
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].titulo);
			printf("Descricao: %s\n", cadastro[j].descricao);
			printf("Ano: %d\n", cadastro[j].data);
			printf("Status: ");
			switch (cadastro[j].status)
			{
			case 1:
				printf("A Fazer\n");
				break;

			case 2:
				printf("Fazendo\n");
				break;

			case 3:
				printf("Concluido\n");
				break;

			default:
				break;
			}
			printf("Gerente: %s\n", cadastro[j].gerente);
			printf("Duracao do Projeto: %d\n", cadastro[j].tempo);
			printf("Linguagem: %s\n", cadastro[j].linguagem);
			printf("Cliente: %s\n", cadastro[j].cliente);
			printf("\n***************************************\n");
			achou = 1;
			system("Pause");
		}
		j++;
	}
	if (achou == 0)
	{
		printf("\nRegistro nao encontrado com o Status: Fazendo.");
		system("Pause");
	}
}

void buscarConcluido(projetos cadastro[MAX])
{
	system("cls");
	int codigo, achou;
	printf("***************************************");
	printf("\n Imprimir todos os projetos com Status: Concluido. ");
	printf("\n***************************************");
	achou = 0;
	int j = 0;
	while ((achou == 0) && (j <= posicao))
	{
		if (3 == cadastro[j].status)
		{
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].titulo);
			printf("Descricao: %s\n", cadastro[j].descricao);
			printf("Ano: %d\n", cadastro[j].data);
			printf("Status: ");
			switch (cadastro[j].status)
			{
			case 1:
				printf("A Fazer\n");
				break;

			case 2:
				printf("Fazendo\n");
				break;

			case 3:
				printf("Concluido\n");
				break;

			default:
				break;
			}
			printf("Gerente: %s\n", cadastro[j].gerente);
			printf("Duracao do Projeto: %d\n", cadastro[j].tempo);
			printf("Linguagem: %s\n", cadastro[j].linguagem);
			printf("Cliente: %s\n", cadastro[j].cliente);
			printf("\n***************************************\n");
			achou = 1;
			system("Pause");
		}
		j++;
	}
	if (achou == 0)
	{
		printf("\nRegistro nao encontrado com o Status: Concluido.");
		system("Pause");
	}
}
void buscarNome(projetos cadastro[MAX]){
	system("cls");
	char nome[30];
	int achou, j;
	printf("***************************************");
	printf("\n Buscar por nome");
	printf("\n***************************************");
	printf("\nEntre com o nome (identico ao cadastrado): ");
	fflush(stdin);
	gets(nome);
	achou = 0;
	j = 0;
	while((achou == 0) && (j < MAX)){
		if(strcmp(cadastro[j].titulo,nome)==0){
			printf("\n%d - %s\n", cadastro[j].codigo, cadastro[j].titulo);
			printf("Descricao: %s\n", cadastro[j].descricao);
			printf("Ano: %d\n", cadastro[j].data);
			printf("Status: ");
			switch (cadastro[j].status)
			{
			case 1:
				printf("A Fazer\n");
				break;

			case 2:
				printf("Fazendo\n");
				break;

			case 3:
				printf("Concluído\n");
				break;

			default:
				break;
			}
			printf("Gerente: %s\n", cadastro[j].gerente);
			printf("Duracao do Projeto: %d\n", cadastro[j].tempo);
			printf("Linguagem: %s\n", cadastro[j].linguagem);
			printf("Cliente: %s\n", cadastro[j].cliente);
			printf("\n***************************************\n");
			achou = 1;
			system("Pause");
		}
		j++;
	}
	if(achou == 0 ){
		printf("\nRegistro nao encontrado com o nome %s \n", nome);
		system("Pause");
	}
}
