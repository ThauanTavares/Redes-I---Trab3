#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

/*THAUAN DE SOUZA TAVARES DA SILVA*
  GRR20171591*/

/*Programa simula uma transmissão de dados, usando Janelas Deslizantes Volta-N o programa só aceita
a mensagem em sequencia, caso venha a sair da sequência ele pega a posição que parou e transmite a partir da mesma*/

/*Objetivo: 
    O receptor se recusa a aceitar qualquer pacote, exceto o próximo na sequência.
 Se um pacote for perdido em trânsito, os pacotes seguintes serão ignorados 
 até que o pacote ausente seja retransmitido*/



int main(){
    unsigned int tamanho;
    unsigned int linhas;
    char **mensagem;
    char **mensagemRec;
    
    int *pariMenEnvLinha;
    int *pariMenEnvColuna;

    int *pariMenRecLinha;
    int *pariMenRecColuna;


    //int *pariMensagemRecebida;
    
    
    linhas=4;
    
    tamanho=4;

    //aloca matrizes
    mensagem=(char**) malloc((linhas)*sizeof(char *));
    for (int i = 0; i < linhas ; i++){
        mensagem[i]=(char*) malloc((linhas)*sizeof(char ));

    }
    //aloca matrizes

    mensagemRec=(char**) malloc((linhas)*sizeof(char *));
    for (int i = 0; i < linhas ; i++){
        mensagemRec[i]=(char*) malloc((linhas)*sizeof(char ));

    }
    //le mensagem a enviar
    for ( int i = 0; i < linhas; i++){
        printf("\n %dº linha da mensagem sem espaço entre os bits Ex:111 \n\n",i+1);
        
        /*for (int j = 0; j < tamanho; j++){
            scanf("%c",&mensagem[i][j]);
        }*/
        //printf("\n");
        fscanf(stdin,"%s",mensagem[i]);

    }
    

    printf("\n Mensagem Digitada\n\n");
    
    for ( int i = 0; i < linhas; i++){
        for (int j = 0; j < tamanho; j++){
           printf("%c ",mensagem[i][j]);
        }
        printf("\n");
    }

    pariMenEnvLinha=(int*) malloc((linhas)*sizeof(int ));//i fixo varia o j para achar a paridade
    pariMenEnvColuna=(int*) malloc((tamanho)*sizeof(int ));//j fixo varia o i para achar a paridade
    
    pariMenRecLinha =(int*) malloc((linhas)*sizeof(int ));//i fixo varia o j para achar a paridade
    pariMenRecColuna=(int*) malloc((tamanho)*sizeof(int ));//j fixo varia o i para achar a paridade

    /*CALCULA A PARIDADE DA MENSAGEM*/
    for ( int i = 0; i < linhas; i++){
        pariMenEnvLinha[i]=paridadeLinha(mensagem,i,tamanho);
    }
    
    for ( int i = 0; i < tamanho; i++){
        pariMenEnvColuna[i]=paridadeColuna(mensagem,i,linhas);
    }

    
    //mensagem recebida
    for ( int i = 0; i < linhas; i++){
        for (int j = 0; j < tamanho; j++){
           mensagemRec[i][j]=mensagem[i][j];
        }
    }
    gerandoInterferencia(mensagemRec,tamanho,linhas);//simula uma interferencia alterando o valor 
    
    printf("\n Mensagem que chegou\n\n");

    for ( int i = 0; i < linhas; i++){
        for (int j = 0; j < tamanho; j++){
           printf("%c ",mensagemRec[i][j]);
        }
        printf("\n");
    }

    int linhaOk;
    int colunaOk;
    
    int erro=0;
    while(erro==0){
        for ( int i = 0; i < linhas; i++){
            pariMenRecLinha[i]=paridadeLinha(mensagemRec,i,tamanho);
        }

        for ( int i = 0; i < tamanho; i++){
            pariMenRecColuna[i]=paridadeColuna(mensagemRec,i,linhas);
        }


        linhaOk=-1;
        colunaOk=-1;

        for (int i = 0; i < linhas; i++){
            if(pariMenEnvLinha[i] != pariMenRecLinha[i]){
                linhaOk=i;
            }
        }
        for (int i = 0; i < tamanho; i++){
            if(pariMenEnvColuna[i] != pariMenRecColuna[i]){
                colunaOk=i;
            }
        }
    
        printf("\n Verificando Integridade\n\n");
        
        
        if((linhaOk != -1) && (colunaOk)!=-1){
            printf("\n Erro detectado na mensagem!\n");
            printf("Volta-N enviar linha %d em diante \n",linhaOk+1);
            gerandoInterferencia(mensagemRec,tamanho,linhas);//simula uma interferencia alterando o valor 

            for ( int i = linhaOk; i < linhas; i++){
                for (int j = 0; j < tamanho; j++){
                    //printf("\nENTROU NA COPIA DENTRO DO ERRO\n");
                    mensagemRec[i][j]=mensagem[i][j];
                }
            }       

        }else{
            printf("\n Mensagem sem Erro!\n\n");
            erro=1;
        }

    }

    if((linhaOk == -1) && (colunaOk)==-1){
        printf("\n Mensagem Recebida com Sucesso!!!\n\n");
        for ( int i = 0; i < linhas; i++){
            for (int j = 0; j < tamanho; j++){
               printf("%c ",mensagem[i][j]);
            }
        printf("\n");
        }
    }
    
    
    
}
