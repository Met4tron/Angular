#include <stdio.h>
#include <time.h>
#include <string.h>

struct Estacionamento
{
	char placa[7];
	char modelo[15];
	char dono[30];
	int status;
};

struct Tempo
{
	int hora[2];
	int minuto[2];
	int segundo[2];
};

int main(int argc, char** argv)
{	   
	   struct Tempo entrada;
	   struct Tempo saida;
	   struct Estacionamento park[20]; // 20 vagas
       
       time_t entrada1; time_t saida1;
       
       struct tm * ent;
       struct tm * sai;
       time(&entrada1);
       ent = localtime(&entrada1);
       printf("%s",asctime(ent));
       
	   int opcao = 0,vaga = 0,pesqV;
	   do
	   {
		   printf("\nDigite a Sua Opcao");
		   printf("\n1-Entrada\n2-Saida\n3-Sair do Sistema\n");
		   scanf("%d",&opcao);
		   switch(opcao)
		   {
		   case 1:
		   	printf("Digite uma Vaga (0 - 20) Para Estacionar\n");
		   	scanf("%d",&vaga);
		   	while(vaga > 20){
		   		printf("\nDigite um Numero Entre 0 - 20: ");
	   			scanf("%d",&vaga);
	   			
			   }
            if(park[vaga].status == 1){
				printf("\nJá existe um veiculos posicionado nesta vaga");
				break;
			}	
				fflush(stdin);
				printf("\nDigite a Sua Placa\t");
			   	//scanf("%s",&park[vaga].placa);
			   	gets(park[vaga].placa);
			   	printf("\nDigite o Modelo do Veiculo\t");
			   	//scanf("%s",&park[vaga].modelo);
			   	gets(park[vaga].modelo);
			   	printf("\nDigite o Primeiro Nome do Dono\t");
			   	//scanf("%s",&park[vaga].dono);
			   	gets(park[vaga].dono);
			   	printf("\nVeiculo Guardado na Vaga: %d\nGuarde consigo este numero !",vaga);
			   	park[vaga].status = 1;
			   
			   break;
		   case 2:
		   		printf("\nDigite o numero da Vaga correspondente ao carro que deseja\t");
		   		scanf("%d",&pesqV);
		   		while(park[pesqV].status != 1){
					   printf("Não ha veiculo registrado nesta vaga !\nDigite Novamente o Numero da Vaga");
					   scanf("%d",&pesqV);
                }
                printf("\nDados Sobre o Veiculo");
                printf("\nPlaca:\t%s",park[pesqV].placa);
                printf("\nModelo:\t%s",park[pesqV].modelo);
                printf("\nDono:\t%s",park[pesqV].dono);

				char vazio[8] = "";		 			 			
				strcpy(park[pesqV].modelo,vazio);
				strcpy(park[pesqV].dono,vazio);
				strcpy(park[pesqV].placa,vazio);
				park[pesqV].status = 0;
				
				int cont = 0;
				int horaa = 7200;
				
				
                time(&saida1);
                sai = localtime(&saida1);
                double a = difftime(saida1,entrada1);
                
                int horas = a/3600;
                int minutos = (a - (3600*horas))/60;
                int segundos = (a - (3600*horas)-(minutos*60));
                
	 	 	    printf("\n\nSegundos:  %.f\n\n",a);
                printf("\n\nMinutos:  %f\n\n",a/60);
                printf("\n\nHora: %f\n\n",a/3600);
                
                
                printf("\n\n%d %d %d",horas,minutos,segundos);
		   		break;
		   default:
		   	printf("Você Está Saindo do Sistema");
			   break;
		   }
	   } while(opcao !=3);	

}
