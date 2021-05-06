#include <stdio.h>
#include <stdlib.h>
#include "escola.h"
#include "aluno.h"


int main(){
    int temp, opt, maxVagas;
    escola *s = NULL;


    while(opt!=0){

        system("cls");

        printf("       Menu\n\n");

        printf("Escolha uma opcao:\n");
        printf("1 - Criar uma turma\n");
        printf("2 - Inserir aluno\n");
        printf("3 - Buscar um aluno\n");
        printf("4 - Remover um aluno\n");
        printf("5 - Listar alunos\n");
        printf("6 - Destruir\n");
        printf("0 - Sair\n");
        scanf("%d",&opt);

        switch(opt) {
            case 1:{
                printf("digite a quantidade de alunos na turma:\n");
                scanf("%d", &maxVagas);
                while(maxVagas<=0) {
                    printf("inválido!");
                    scanf("%d", &maxVagas);
                }
                s = ColCreate(maxVagas);
                break;
            }
            case 2:{
                Colinsert(s);
                break;
            }
            case 3:{
                searchName(s);
                getchar();
                break;
            }
            case 4:{
                ColremoveName(s);
                getchar();
                break;

            }
            case 5:{
                listaAlunos(s);
                getchar();
                break;
            }
            case 6:{
                freeAll(s);
                getchar();
                break;
            }
            case 0:{
                temp = -1;
                break;
            }
            default:{
                break;
            }
        }
    }

    return 0;
}

