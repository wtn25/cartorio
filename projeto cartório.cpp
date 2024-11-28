#include <stdio.h> //biblioteca de comunicaçao com usuário
#include <stdlib.h>// biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocaçao de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()// função responsável por cadastrar o usuário
{
	//início da criação de variáveis /strings
	char arquivo[40];// 
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	// final criação de variáveis 
	
	printf("digite cpf a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s" , cpf);// %s refere-se a strings - quando preciso salvar uma string
	
	strcpy(arquivo,cpf);// copia os valores das strings
	
	FILE *file;//cria o arquivo
	
	file=fopen(arquivo, "w");//cria o arquivo e o "w" sig.escrever
	fprintf(file,cpf);//salvo valor da variável
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
		printf("não foi possível abrir o arquivo ,não localizado!.\n");	

	while (fgets(conteudo, 200,file) !=NULL)
	{
		printf("\n essas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf  do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("o usuário não se encontra no sistema!.\n");
		system("pause");
	
	}
	
}


int main()//definindo variáveis 
{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		system("cls");// responsável por limpar tela
		
	
		setlocale(LC_ALL,"portuguese");// biblioteca em portugues
	
		printf("###cartório da EBAC###\n\n");// início do menu -o comndo barra n pula linha e  deixa o progr.limpo p/ususrio
		printf("escolha a opção desejada do menu:\n\n")	;
		printf("\t1-registrar nome\n");// comand.barra t add espaço no início
		printf("\t2-consultar nomes\n");
		printf("\t3-deletar nomes\n\n");
		printf("qual opção desejada");//final menu
		printf("\t4-sair do sistema\n\n ");
		
    	scanf("%d",&opcao); // pausa o programa e aguarda instruçoes,armazenando escolha do usuário 
    
    
   		system("cls");//limpar tela depois de o usuário colocar alguma instrução 
   		 
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
    		printf("essa opção não está disponível\n");//fim da seleção 
			system("pause");
			break;
		  }
		
			
	}
}
