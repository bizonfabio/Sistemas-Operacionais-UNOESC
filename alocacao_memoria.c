#include <stdio.h>

//variaveis

#define TAM_MEM 20


typedef struct {

    int id;
    int tam;

} Proc;


//Funcoes

void mostrar_memoria(int memoria[]){
    int cont;
    for(cont = 0; cont < TAM_MEM; cont++ ){
        printf("[%d]",memoria[cont]);

    }        
    

}

int first_fit(int memoria[], Proc procs){

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
                printf("memoria e valida e igual a zero\n");
                tam_bloco++;
                cont++;

                if(tam_bloco >= procs.tam){
                    printf("Encontrou bloco\n");
                    for(int i = inicio; i < inicio + tam_bloco; i++){
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
        2, 2, 0, 0,
        2, 0, 0, 0,
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

    
    best_fit(memoria, procs[0]);
    
    /*for(i=0;i< qtd_procs; i++){
        first_fit(memoria, procs[i]); //selecione seu metodo
    }
    */
    printf("\nMemoria apos alocacao\n");
    mostrar_memoria(memoria);
    
    
    
    
    
}
