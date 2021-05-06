#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include "escola.h"


escola *ColCreate(int maximo) { //Recebe o n�mero m�ximo de itens para a Cole��o a ser criada
    escola *s;
    if(maximo>0) {
        s = (escola*)malloc(sizeof(escola));
        if (s!= NULL) {
            s->alunos = (void**)malloc(sizeof(void*)*maximo);
            if(s->alunos!=NULL) {
                s-> maxAlunos = maximo;
                s->nAlunos = 0;
                return s; //Retorna um ponteiro para um novo TAD Cole��o vazio
            }
        }
    }
    return NULL;
}

//Destr�i um TAD Cole��o
int ColDestroy(escola *s) {
    if (s != NULL) {  // Ponteiro para o TAD
        if(s->nAlunos==0) {
            free(s ->alunos);
            free(s);
            return TRUE; //Retorna TRUE(1) e TAD Cole��o destru�do liberando seu espa�o da mem�ria ou FALSE(0) - Caso contr�rio
        }
    }
    return FALSE;
}

int ColNewAluno(escola *s, void * aln) {
    if (s!=NULL) {
        if(s->nAlunos < s->maxAlunos) { // se o tad n estiver cheio
            s->alunos[s->nAlunos] = aln;
            s->nAlunos ++;// incremeta um novo aluno na colecao
            return TRUE;
        }
    }
    return FALSE;
}

void * ColQuest(escola *s, void *key, int(*cmp)(void*, void*)) {
    int i = 0;
    if(s!= NULL) { //TAD Cole��o existente n�o vazio
        if(s->nAlunos>0) {
            while(i < s->nAlunos && cmp(key, s->alunos[i])!=TRUE) {
                ++i;
            }
            if (i < s->nAlunos && cmp(key, s->alunos[i])== TRUE) { //compara cada aluno existente na colecao com o que foi buscado
                return s->alunos[i];
            }
        }
    }
    return NULL;
}

void * Colremove(escola *s, void *key, int(*cmp)(void*, void*)) {
    int i = 0;
    void * aux;
    if(s!= NULL) {// se tad nao vazio
        if(s->nAlunos>0) { // se numero de alunos maior que 0
            while(i < s->nAlunos && cmp(key, s->alunos[i])!=TRUE ){
                i++;
            }
            if (i < s->nAlunos && cmp(key, s->alunos[i])== TRUE) {//encontra aluno pela chave de busca(no caso o nome) se igual TRUE...
                aux = s->alunos[i];
                for (; i < s->nAlunos-1; i++) {
                    s->alunos[i] = s->alunos[i+1];//percorre cada aluno da colecao ate achar o que foi buscado
                }
                s->nAlunos --; //remove o aluno buscado
                return aux;
            }
        }
    }
    return NULL;
}

