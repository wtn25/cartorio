#include <stdio.h> //biblioteca de comunica�ao com usu�rio
#include <stdlib.h>// biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca�ao de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro()// fun��o respons�vel por cadastrar o usu�rio
{
	//in�cio da cria��o de vari�veis /strings
	char arquivo[40];// 
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	// final cria��o de vari�veis 
	
	printf("digite cpf a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s" , cpf);// %s refere-se a strings - quando preciso salvar uma string
	
	strcpy(arquivo,cpf);// copia os valores das strings
	
	FILE *file;//cria o arquivo
	
	file=fopen(arquivo, "w");//cria o arquivo e o "w" sig.escrever
	fprintf(file,cpf);//salvo valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobre nome a ser cadastrado");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:  ");
	scanf("%s" , cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
		setlocale(LC_ALL,"portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado");
	scanf("%s" ,cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
		printf("n�o foi poss�vel abrir o arquivo ,n�o localizado!.\n");	

	while (fgets(conteudo, 200,file) !=NULL)
	{
		printf("\n essas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf  do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	
	}
	
}


int main()//definindo vari�veis 
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		system("cls");// respons�vel por limpar tela
		
	
		setlocale(LC_ALL,"portuguese");// biblioteca em portugues
	
		printf("###cart�rio da EBAC###\n\n");// in�cio do menu -o comndo barra n pula linha e  deixa o progr.limpo p/ususrio
		printf("escolha a op��o desejada do menu:\n\n")	;
		printf("\t1-registrar nome\n");// comand.barra t add espa�o no in�cio
		printf("\t2-consultar nomes\n");
		printf("\t3-deletar nomes\n\n");
		printf("qual op��o desejada");//final menu
		printf("\t4-sair do sistema\n\n ");
		
    	scanf("%d",&opcao); // pausa o programa e aguarda instru�oes,armazenando escolha do usu�rio 
    
    
   		system("cls");//limpar tela depois de o usu�rio colocar alguma instru��o 
   		 
		switch(opcao)
	      {
	      	case 1: 
	      	registro();
			break;
			
			case 2:
			consulta();
    		break;
    	
    		case 3:
    		deletar();	
    		break;
    	
    		case 4:
    		printf("obrigado por utilizar o sistema!\n");	
    		return 0;
    		break;
    		
    		default :
    		printf("essa op��o n�o est� dispon�vel\n");//fim da sele��o 
			system("pause");
			break;
		  }
		
			
	}
}
