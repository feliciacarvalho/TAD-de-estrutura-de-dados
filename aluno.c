#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include "escola.h"
#include "aluno.h"


int cmpNomeAluno(void *a, void *b) {
    char *auxA;
    aluno *auxB;

    auxA = (char *)a;
    auxB = (aluno *)b;

    if (strcmp(auxA, auxB->nome) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int searchName(escola *s) {
    char aux_nome[50];
    aluno *aux_A;

    if(s!=NULL && s->nAlunos>0) {
        printf("Informe o nome que deseja buscar: ");
        fflush(stdin);
        scanf("%[^\n]s", aux_nome);
        fflush(stdin);
        aux_A = (aluno *)ColQuest(s, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL) {
            printf("Aluno encontrado:   \n");
            printf("Nome: %s\n", aux_A->nome);
            printf("Idade de %s: %d\n", aux_A->nome, aux_A->idade);
            printf("Nota %s: %.2f\n", aux_A->nome, aux_A->nota);
            getchar();
            return TRUE;
        } else {
            printf("Aluno %s nao encontrado!!\n", aux_nome);
            getchar();
            return FALSE;
        }
    }
    printf("Sem Alunos!\n");
    getchar();
    return FALSE;
}


int ColremoveName(escola *s) {// remove o aluno atraves do nome buscado
    char aux_nome[50];
    aluno *aux_A;
    if(s!=NULL && s->nAlunos>0) {
        printf("Informe o nome do aluno que deseja remover: ");
        fflush(stdin);
        scanf("%s", aux_nome);
        fflush(stdin);
        aux_A = (aluno *)Colremove(s, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL) {
            printf("O aluno %s foi removido\n", aux_nome);
            getchar();
            return TRUE;
        } else {
            printf("O aluno %s nao foi encontrado.\n", aux_nome);
            getchar();
            return FALSE;
        }
    }
    printf("Sem Alunos!\n");
    return FALSE;
}

int Colinsert(escola *s) {
    if(s!=NULL) {
        if (s->nAlunos < s->maxAlunos) {
            aluno *a =(aluno *)malloc(sizeof(aluno));
            if (a != NULL) {
                printf("Informe o nome do aluno: \n");
                scanf("%s", (a->nome));
                getchar();
                system("cls");
                printf("Informe a nota do aluno %s: \n", a->nome);
                scanf("%f", &(a->nota));
                system("cls");
                printf("Informe a idade do aluno %s: \n", a->nome);
                scanf("%d", &(a->idade));
                system("cls");
                ColNewAluno(s, (void *)a);

                getchar();

                return TRUE;

            }
        }
        printf("SALA CHEIA!\n\n");
        getchar();
    }
    printf("invalido!\n");
    getchar();
    return FALSE;
}

int listaAlunos(escola *s) {
    int i;
    if(s!=NULL) {
        if(s->nAlunos>0) {
            printf("\nAlunos Matriculados na escola:\n");
            for(i=0; i<s->nAlunos; i++) {
                aluno *aux = (aluno*)s->alunos[i];
                printf("\nNome: %s\n", aux->nome);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("A nota de %s: %.2f\n", aux->nome, aux->nota);

            }
            printf("\nAlunos Matriculados na escola\n");
            getchar();
            return TRUE;
        } else {
            printf("sem alunos na escola!\n");
            getchar();
        }
    }
    return FALSE;
}

int freeAll(escola *s) {
    int i;
    if(s!=NULL) {
        if(s->nAlunos>0) {
            for(i=0; i<s->nAlunos; i++) {
                free(s->alunos[i]);
            }
            s->nAlunos = 0;
            printf("Turma removida\n");
            int auxc = ColDestroy(s);
            if(auxc) {
                printf("sucess\n");
            }
            getchar();
            return TRUE;
        }
        printf("sem alunos para remover\n");
        int auxc = ColDestroy(s);
        if(auxc) {
            printf("sucess\n");
        }
        getchar();
        return FALSE;
    }
    return FALSE;
}

