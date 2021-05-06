typedef struct _ESCOLA_{
    int nAlunos;
    int maxAlunos;
    void ** alunos;
}escola;


escola *ColCreate(int maximo); //cria uma colecao escola
int ColDestroy(escola *s); // destroi colecao
int ColNewAluno(escola *s, void * aln); // adiciona aluno
void * ColQuest(escola *s, void *key, int(*cmp)(void*, void*)); // busca um aluno
void * Colremove(escola *s, void *key, int(*cmp)(void*, void*)); // remove um aluno
int searchName(escola *s); // busca pelo nome
int ColremoveName(escola *s); // remove pelo nome
int Colinsert(escola *s); // insere um aluno na escola
int listaAlunos(escola *s); // lista todos os alunos da escola
int freeAll(escola *s); // libera todos os alunos da escola

