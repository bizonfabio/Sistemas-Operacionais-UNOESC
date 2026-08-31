#include <stdio.h>

//variaveis

#define TAM_MEM 20


typedef struct {

    int id;
    int tam;

} Proc; //estrutura para simular um processo na memória;


//Funcoes

void mostrar_memoria(int memoria[]){
    int cont;
    
    for(cont = 0; cont < TAM_MEM; cont++ ){
        printf("[%d]",memoria[cont]);
    }       
    //printf("Contrario \n");
    /*for(cont = TAM_MEM -1; cont >= 0; cont--){
        printf("[%d]",memoria[cont]);
    }*/

}

int conta_zero(int memoria[]){ // função para contar espaços mínimos vazios na memória;

    int qtd = 0;

    for(int i = 0; i <TAM_MEM; i++){
        if(memoria[i] == 0){
            qtd++;
        }
    }
    printf("\nQuantidade de zeros livres: %d\n", qtd);
    
}

int blocos_livres(int memoria[]){ 
    /*funcao mostra a quantidade e blocos vazios e ocupados na memória, importante para checar se existe memória disponível antes de alocar
    importante lembrar que fazer essa checagem também ocupa memória.
    */

    int qtd_blocos = 0;
    int blocos_cheios = 0;
    int em_bloco_livre = 0;
    int em_bloco_cheio = 0;
    

    for(int i = 0; i <TAM_MEM; i++){
        if(memoria[i] == 0){ //se memoria livre contar ir ate o lugar ocupado
            em_bloco_cheio = 0; // saiu bloco cheio
            if(em_bloco_livre == 0){
                em_bloco_livre = 1;
                qtd_blocos++;        
            }            
        }   
            else{
                em_bloco_livre = 0; // esta em bloco cheio
                if(em_bloco_cheio == 0){                   
                em_bloco_cheio = 1;
                blocos_cheios++;
                }
        }
    }
    printf("\nQuantidade de blocos livres: %d\n", qtd_blocos);
    printf("\nQuantidade de blocos cheios: %d\n", blocos_cheios);
    
}


int first_fit(int memoria[], Proc procs){

    /*
    Funcao que aloca os processos na memória. Essa função usa o método first fit, que aloca o processo no primeiro bloco de memória disponível.
    */
    int cont;
    printf("Entrou na funcao\n");
    for(cont = 0; cont < TAM_MEM; cont++){  //percorre toda a memória 
    //printf("%d\n", memoria[cont]);     

        if (memoria[cont] == 0) //se o valor da memória no índice atual for == 0 então deve ser medido o tamanho do bloco livre.
        {
            printf("Bloco eh zero\n");
            int tam_bloco = 0; //bloco livre inicia com tamanho 0;
            int inicio = cont; //o início do bloco é a posicao que o contador encontrou o primeiro zero.

            while(cont <= TAM_MEM && memoria[cont] == 0){ //enquanto o contador for menor que o tamanho da memória e o valor da memória for zero
                
                tam_bloco++; //o bloco livre aumenta da tamanho.
                cont++;

                if(tam_bloco >= procs.tam){ //se o tamanho do bloco livre é maior ou igual ao tamanho do processo, então o processo deve ser alocado nesse lugar.
                    printf("Encontrou bloco\n");
                    printf("Inicio  %d\n", inicio);
                    printf("Tamanho bloco %d\n", tam_bloco);
                    for(int i = inicio; i < inicio + tam_bloco; i++){ //outro contador inicia na posição inicial//8 do bloco e vai até o final do bloco//11, que é início + tamanho (8 + 3 = 11)
                        memoria[i] = procs.id;
                    }
                    printf("Bloco Alocado\n");
                    return 1;    
                }
                
            }
            printf("Nao encontrou bloco valido\n");            
        }
            
    }

    return 0;
}

int best_fit(int memoria[], Proc procs){ //funciona SOMENTE se o tamanho do bloco for exatamente igual ao do processo.

    int cont;
    printf("Entrou na funcao\n");
    for(cont = 0; cont < TAM_MEM; cont++){   
    printf("%d\n", memoria[cont]);     

        if (memoria[cont] == 0)
        {
            printf("Bloco eh zero\n");
            int tam_bloco = 0;
            int inicio = cont;

            while(cont <= TAM_MEM && memoria[cont] == 0){
                printf("memoria eh valida \n");
                tam_bloco++;
                cont++;
                }
                if(tam_bloco == procs.tam){
                    printf("Encontrou bloco\n");
                    for(int i = inicio; i < inicio + tam_bloco; i++){
                        memoria[i] = procs.id;
                    }
                    printf("Bloco Alocado\n");
                    return 1;    
                }
                
            
            printf("Nao encontrou bloco valido\n");            
        }
            
    }

    return 0;
}


int main()
{

    int memoria[TAM_MEM] = {
        1, 1, 1, 1, 
        0, 0, 2, 2,
        0, 0, 0, 0,
        3, 3, 3, 0,
        0, 0, 0, 0
    };
    
    
    Proc procs[] = {
        {4, 2},
        {5, 3},
        {6, 5}
    };
    
    int qtd_procs = 3;
    int i;
    
    
    //Estado inicial da memoria
    printf("Estado inicial Memoria\n");
    mostrar_memoria(memoria);
    blocos_livres(memoria);
    
    best_fit(memoria, procs[0]);
    
    /*for(i=0;i< qtd_procs; i++){
        first_fit(memoria, procs[i]); //selecione seu metodo
    }
    */
    printf("\nMemoria apos alocacao\n");
    //mostrar_memoria(memoria);
    
    
    
    
    
}
