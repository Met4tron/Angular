
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
 
 struct Tempo{
        unsigned int hora, minuto, segundo;
};
struct Estacionamento{
       char placa[7];
       char marca[15];
       struct Tempo entrada; 
       struct Tempo saida;
       struct Tempo estadia;
       int status;
};
int main(){
	   struct tm *local;
	   time_t t;
	   t = time(NULL);
	   local = localtime(&t);
	   // Função de Time.h para pegar a hora,min e seg atual do sistema
	   unsigned int hora2,minutos2,segundos2;
	   hora2 = local->tm_hour; // Hora
	   minutos2 = local->tm_min; // Minutos
	   segundos2 = local->tm_sec; // Segundos
	   
	   
       struct Estacionamento parking[20]; // Inicializo estaciomento com 20 vagas
       int i=0,temp, num;
       char pesq[7];
   		while (num!=3)
   		{
			printf ("\n Menu \n 1 - Entrada \n 2 - Saida \n 3 - Sair \n");
 			printf ("\nDigite a opcao requerida: ");
        	scanf("%d",&num);
       		switch (num) {
	            case 1:
	        	if(i==20){
	          	printf("Estacionamento Lotado, espere um carro sair");
	          	break;
	        	}
		        for(temp=0;temp<1;temp++){                                                 
		        printf("\nDigite a placa : ");
		        scanf("%s", &parking[i].placa);
		        printf("\nDigite a Marca - Nome do Veiculo: ");
		        scanf("%s", &parking[i].marca);
		        parking[i].entrada.hora = hora2;
		        parking[i].entrada.minuto = minutos2;
		        parking[i].entrada.segundo = segundos2;
		        printf("\nHorario de Entrada:  Hora: %d | Minuto: %d | Segundos: %d\n",parking[i].entrada.hora,parking[i].entrada.minuto,parking[i].entrada.segundo);
		        parking[i].status=1;
		        i++;
	        }
	             break;  
	 
	            case 2:
	            printf ("\n\nDigite o numero da placa.\n");
	            scanf("%s",&pesq);
	            for(i=0;i<=20;i++){
	             if(strcmp(pesq,parking[i].placa)==0){ // Confere a placa do carro no estaciomento
	             printf("\nNome: %s", parking[i].placa);
	             printf("\Veiculo: %s", parking[i].marca);
	             printf("\nDigite a hora da saida ");
	             scanf("%d",&parking[i].saida.hora);
	             printf("\nDigite o minuto de saida");
	             scanf("%d",&parking[i].saida.minuto);
	             printf("\nDigite o segundo de saida");
	             scanf("%d",&parking[i].saida.segundo);
	             int a = parking[i].estadia.hora = parking[i].saida.hora - parking[i].entrada.hora; // Calculo de conversão de Horas de estadia
	             int b = parking[i].estadia.minuto = parking[i].saida.minuto - parking[i].entrada.minuto; // Calculo de conversão de Minutos de estadia
	             int c = parking[i].estadia.segundo = parking[i].saida.segundo - parking[i].entrada.segundo; // Calculo de conversão de Segundos de estadia
	             printf("\nHora Entrada:  %d:%d:%d", parking[i].entrada.hora, parking[i].entrada.minuto, parking[i].entrada.segundo);
	             printf("\nHora Saida: %d:%d:%d",parking[i].saida.hora,parking[i].saida.minuto,parking[i].saida.segundo);
	             printf("\nSeu Tempo de Estadia foi: Hora: %d | Minuto: %d | Segundos: %d\n",a,abs(b),abs(c));
	             --i; // Retira uma Posição, deixando uma vaga
	             // Abs é o valor absoluto sem sinal !
	            
	             
	       		break;
	        	
             } 
             if (i==21){
                  printf("Veiculo nao encontrado");
             }
            }                   
            break;
 
              continue;
 
            default:
                printf("\n\nNenhuma opcao foi escolhida.");
                break;
                }
}
 
    return 0;
}

