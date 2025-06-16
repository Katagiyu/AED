#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct noF
{
    char dado[50];
    struct noF *prox;
} noFila;

typedef struct
{
    noFila *inicio;
    noFila *fim;
    int tamFila;
} fila;

void fila_cria(fila *q);
int fila_insere(fila *q, char *descproduto);
int fila_getTamanho(fila q);
void fila_mostra(fila q);


typedef struct noP
{
    char dado[50];
    struct noP *prox;
} noPilha;

typedef struct
{
    noPilha *topo;
    int tamPilha;
} pilha;

void pilha_cria(pilha *s);
int pilha_empilha(pilha *s, char *descproduto);
int pilha_getTamanho(pilha s);
void pilha_mostra(pilha s);

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    fila dadosFila;
    pilha dadosPilha, dadosPilha2;

    char descproduto[100];
    int sucesso, opcao;

    pilha_cria(&dadosPilha);
    pilha_cria(&dadosPilha2);
    fila_cria(&dadosFila);

    do
    {
        printf("\nEscolha uma Opção:\n");
        printf("1 - Adicionar ao Estoque\n");
        printf("2 - Mostrar Estoque\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            do
            {
                printf("----------------------------------------");
                printf("\n\nEscolha o tipo:\n");
                printf("1 - Camiseta\n");
                printf("2 - Short\n");
                printf("3 - Suplementos\n");
                printf("4 - Voltar ao menu principal\n");
                int tipo;
                printf("Tipo: ");
                scanf("%d", &tipo);

                if (tipo == 4)
                {
                    system("cls");
                    printf("Retornando ao menu principal...\n");
                    break;
                }

                if (tipo < 1 || tipo > 4)
                {
                    system("cls");
                    printf("Opção inválida. Por favor, escolha entre 1 e 4.\n");
                    continue;
                }

                system("cls");
                printf("Você Escolheu Guardar Mercadorias.\n");
                printf("Descreva o produto: ");
                scanf(" %[^\n]", descproduto);

                switch (tipo)
                {
                case 1:
                    system("cls");
                    sucesso = pilha_empilha(&dadosPilha, descproduto);
                    if (!sucesso)
                        printf("Erro ao empilhar %s.\n", descproduto);
                    else
                    {
                        printf("Palavra %s empilhada.\n\n", descproduto);
                        pilha_mostra(dadosPilha);
                    }
                    break;

                case 2:
                    system("cls");
                    sucesso = pilha_empilha(&dadosPilha2, descproduto);
                    if (!sucesso)
                        printf("Erro ao empilhar %s.\n", descproduto);
                    else
                    {
                        printf("\nPalavra %s empilhada.\n\n", descproduto);
                        pilha_mostra(dadosPilha2);
                    }
                    break;

                case 3:
                    system("cls");
                    sucesso = fila_insere(&dadosFila, descproduto);
                    if (!sucesso)
                        printf("Erro ao inserir %s na fila.\n", descproduto);
                    else
                    {
                        printf("Palavra %s inserida na fila.\n\n", descproduto);
                        fila_mostra(dadosFila);
                    }
                    break;
                }

            }
            while (1);
            break;

        case 2:
            system("cls");
            printf("\nDados Pilha camisetas:\n");
            pilha_mostra(dadosPilha);
            printf("\n\n------------------------------------\n\n");
            printf("\nDados Pilha bermudas:\n");
            pilha_mostra(dadosPilha2);
            printf("\n\n------------------------------------\n\n");
            printf("\nDados Fila suplementos:\n");
            fila_mostra(dadosFila);

            break;

        case 3:
            system("cls");
            printf("\nAdeus João...\n");
            break;

        default:
            system("cls");
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    }
    while (opcao != 3);
}

void fila_cria(fila *q)
{
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

int fila_insere(fila *q, char *descproduto)
{
    noFila *aux = (noFila *) malloc(sizeof(noFila));
    if (aux == NULL) return 0;

    strcpy(aux->dado, descproduto);
    aux->prox = NULL;
    q->tamFila++;

    if (q->inicio == NULL)
    {
        q->inicio = aux;
        q->fim = aux;
    }
    else
    {
        q->fim->prox = aux;
        q->fim = aux;
    }
    return 1;
}

int fila_getTamanho(fila q)
{
    return q.tamFila;
}

void fila_mostra(fila q)
{
    noFila *aux = q.inicio;
    int tam = 0;
    if (aux == NULL)
    {
        printf("Fila vazia...\n");
        return;
    }

    while (aux != NULL)
    {
        printf("[%d] Palavra enfileirada: %s\n", tam, aux->dado);
        aux = aux->prox;
        tam++;
    }
    printf("Total de itens na fila: %d\n", fila_getTamanho(q));
}

void pilha_cria(pilha *s)
{
    s->topo = NULL;
    s->tamPilha = 0;
}

int pilha_empilha(pilha *s, char *descproduto)
{
    noPilha *aux = (noPilha *) malloc(sizeof(noPilha));
    if (aux == NULL) return 0;

    strcpy(aux->dado, descproduto);
    aux->prox = s->topo;
    s->topo = aux;
    s->tamPilha++;

    return 1;
}

int pilha_getTamanho(pilha s)
{
    return s.tamPilha;
}

void pilha_mostra(pilha s)
{
    noPilha *aux = s.topo;
    int tam = 0;
    if (aux == NULL)
    {
        printf("Pilha vazia...\n");
        return;
    }

    while (aux != NULL)
    {
        printf("[%d] Produtos no estoque: %s\n", tam, aux->dado);
        aux = aux->prox;
        tam++;
    }
    printf("\nTotal de itens na pilha: %d\n", pilha_getTamanho(s));
}
