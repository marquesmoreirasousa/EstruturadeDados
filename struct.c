#include<stdio.h>
#include<stdlib.h>

#define TAM 10000

//Definição da struct
typedef struct sContato{
    char nome[100];
    int ddd;
    int telefone;
    char email[70];
}CONTATO;

int menu(){
    int opcao;
    printf("\n==============MENU==============\n");
    printf("0                    - para sair\n");
    printf("1            - para novo contato\n");
    printf("2              - listar contatos\n");
    scanf("%d", &opcao);
    return opcao;
}

CONTATO cadastrarContato(){
    CONTATO novoContato;
    printf("Digite o nome do contato: \n");
    scanf(" %[^\n]", novoContato.nome);

    printf("Digite o DDD:\n");
    scanf("%d", &novoContato.ddd);

    printf("Digite o telefone:\n");
    scanf("%d", &novoContato.telefone);

    printf("Digite o email do contato: \n");
    scanf(" %[^\n]", novoContato.email);

    return novoContato;
}

void imprimirContato(CONTATO infoCont){
    printf("\n-----------------------\n");
    printf("NOME:  %s\n", infoCont.nome);
    printf("DDD:   %d\n", infoCont.ddd);
    printf("TEL:   %d\n", infoCont.telefone);
    printf("EMAIL: %s\n", infoCont.email);
}

int main(void){

    //struct sContato variavel1;
    CONTATO agenda[TAM];
    int qtd = 0;
    int opcao;

    do{
        opcao = menu();
        switch (opcao)
        {
        case 0:
            printf("Obrigado por utilizar o sistema!\n");
            break;
        case 1:
            if(qtd == TAM)
                printf("Nao ha posicoes disponiveis na agenda!\n");
            else{
                agenda[qtd] = cadastrarContato();
                qtd++;
            }
            break;
        case 2:
            if(qtd == 0)
                printf("Nao ha contatos salvos!\n");
            else{
                for(int i = 0; i < qtd; i++)
                    imprimirContato(agenda[i]);
            }
            break;
        default:
        printf("OPCAO: %d", opcao);
        printf("Opcao invalida!\n");
            break;
        }

    }while(opcao != 0);


    return 0;
}