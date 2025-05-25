/*CIÊNCIA DA COMPUTAÇÃO - UEMS
TRABALHO 01
BIANCA DA SILVA BARROS
RGM: 49842 */
#include <stdio.h>
#include <stdlib.h>

struct s_no
{
    int info;
    struct s_no *prox;
    struct s_no *ante;
};

//********************************************************************************************************************************************************* */
void desalocaMemoria(struct s_no *ptlista)
{
    struct s_no *temp;
    while (ptlista != NULL)
    {
        temp = ptlista;
        ptlista = ptlista->prox;
        free(temp);
    }
}
void desalocaCircular(struct s_no **ptlista)
{
    if (*ptlista == NULL)
        return;

    struct s_no *pont = *ptlista;
    struct s_no *temp = pont->prox;
    while (temp != pont)
    {
        struct s_no *proximo = temp->prox;
        free(temp);
        temp = proximo;
    }
    free(pont);
    *ptlista = NULL;
}
//********************************************************************************************************************************************************* */
void imprimeListaEncadeada(struct s_no *ptlista)
{
    if (ptlista == NULL)
    {
        system("clear");
        printf("Lista esta vazio!!\n");
        return;
    }
    // Imprime os valores na lista
    struct s_no *pont = ptlista;
    while (pont != NULL)
    {
        printf("%d → ", pont->info);
        pont = pont->prox;
    }
    printf("NULL\n");
}

void imprimeListaCircular(struct s_no *ptlista)
{
    if (ptlista == NULL)
    {
        system("clear");
        printf("Lista esta vazio!!\n");
        return;
    }
    // Imprime os valores na lista
    struct s_no *pont = ptlista;
    do
    {
        printf("%d → ", pont->info);
        pont = pont->prox;
    } while (pont != ptlista);
    printf("(%d)\n", ptlista->info);
}

void imprimeListaDuplamente(struct s_no *ptlista)
{
    if (ptlista == NULL || ptlista->prox == NULL)
    {
        system("clear");
        printf("Lista esta vazia!!\n");
        return;
    }
    // Imprime valores
    struct s_no *pont = ptlista->prox;
    printf("HEAD ⇄ ");
    while (pont != NULL)
    {
        printf("%d ⇄ ", pont->info);
        pont = pont->prox;
    }
    printf("NULL\n");
}

void imprimeFilaPilha(struct s_no *ptlista)
{
    if (ptlista == NULL)
    {
        system("clear");
        printf("Fila ou Pilha vazia!!\n");
        return;
    }
    // Imprime os valores na lista
    struct s_no *pont = ptlista;
    while (pont != NULL)
    {
        printf("%d → ", pont->info);
        pont = pont->prox;
    }
    printf("ULTIMO\n");
}

//********************************************************************************************************************************************************* */
void inserirListaEncadeada(struct s_no **ptlista)
{
    struct s_no *novo_no, *pont, *ant;
    int valor, continuar;

    do
    {
        // Aloca um novo no
        novo_no = (struct s_no *)malloc(sizeof(struct s_no));
        if (novo_no == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        // Solicita um valor ao usuario
        printf("Digite o valor do novo no: ");
        scanf("%d", &valor);

        // //Inicia o novo no
        novo_no->info = valor;
        novo_no->prox = NULL;

        if (*ptlista == NULL || valor < (*ptlista)->info)
        {
            novo_no->prox = *ptlista;
            *ptlista = novo_no;
        }
        else
        {
            ant = *ptlista;
            pont = (*ptlista)->prox;
            while (pont != NULL && pont->info < valor)
            {
                ant = pont;
                pont = pont->prox;
            }
            novo_no->prox = pont;
            ant->prox = novo_no;
        }
        imprimeListaEncadeada(*ptlista);

        printf("Deseja inserir outro valor? (1-SIM, 2-NAO): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

int buscarListaEncadeada(struct s_no *ptlista, int x)
{
    while (ptlista != NULL)
    {
        if (ptlista->info == x)
        {
            return 1; // Encontrou o valor
        }
        ptlista = ptlista->prox;
    }
    return 0; // Nao encontrou o valor
}

void removerListaEncadeada(struct s_no **ptlista)
{
    struct s_no *ant = NULL, *pont = *ptlista;
    int valor;

    printf("Digite o valor para excluir: ");
    scanf("%d", &valor);

    // Encontra o valor e o anterior
    while (pont != NULL && pont->info != valor)
    {
        ant = pont;
        pont = pont->prox;
    }
    if (pont != NULL)
    {
        if (ant == NULL)
        {
            *ptlista = pont->prox;
        }
        else
        {
            ant->prox = pont->prox;
        }
        free(pont);
        system("clear");
        printf("\n-----------------\n");
        printf("|VALOR REMOVIDO!|\n");
        printf("-----------------\n");
    }
    else
    {
        system("clear");
        printf("\n--------------------\n");
        printf("|VALOR NAO ENCONTRADO|\n");
        printf("---------------------\n");
    }
    imprimeListaEncadeada(*ptlista);
}

//********************************************************************************************************************************************************* */
void inserirListaCircular(struct s_no **ptlista)
{
    struct s_no *novo_no, *pont, *ant;
    int valor, continuar;

    do
    {
        // Aloca um novo no
        novo_no = (struct s_no *)malloc(sizeof(struct s_no));
        if (novo_no == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        // Solicita um valor ao usuario
        printf("Digite o valor do novo no: ");
        scanf("%d", &valor);

        // Inicia o novo no
        novo_no->info = valor;

        if (*ptlista == NULL)
        {
            // Primeiro no aponta para si mesmo
            novo_no->prox = novo_no;
            *ptlista = novo_no;
        }
        else // Novo no sendo menor que o primeiro
            if (valor < (*ptlista)->info)
            {
                pont = *ptlista;
                while (pont->prox != *ptlista)
                {
                    pont = pont->prox;
                }
                pont->prox = novo_no;
                novo_no->prox = *ptlista;
                *ptlista = novo_no;
            }
            else
            {
                ant = *ptlista;
                pont = (*ptlista)->prox;
                while (pont != *ptlista && pont->info < valor)
                {
                    ant = pont;
                    pont = pont->prox;
                }
                ant->prox = novo_no;
                novo_no->prox = pont;
            }
        imprimeListaCircular(*ptlista);

        printf("Deseja inserir outro valor? (1-SIM, 2-NAO): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

int buscarListaCircular(struct s_no *ptlista, int x)
{
    struct s_no *pont = ptlista;
    do
    {
        if (pont->info == x)
        {
            return 1; // Encontrou o valor
        }
        pont = pont->prox;
    } while (pont != ptlista);
    return 0; // Nao encontrou o valor
}

void removerListaCircular(struct s_no **ptlista)
{
    struct s_no *ant = NULL, *pont = *ptlista;
    int valor;

    printf("Digite o valor para excluir: ");
    scanf("%d", &valor);

    do
    {
        if (pont->info == valor)
            break;
        ant = pont;
        pont = pont->prox;
    } while (pont != *ptlista);

    // Valor encontrado
    if (pont->info == valor)
    {
        // Lista com apenas um nó
        if (pont->prox == pont)
        {
            *ptlista = NULL;
        }
        else
        {
            if (pont == *ptlista)
            {
                // Atualiza ponteiro do último nó
                struct s_no *ultimo = *ptlista;
                while (ultimo->prox != *ptlista)
                    ultimo = ultimo->prox;
                *ptlista = pont->prox;
                ultimo->prox = *ptlista;
            }
            else
            {
                ant->prox = pont->prox;
            }
        }
        free(pont);
        system("clear");
        printf("\n-----------------\n");
        printf("|VALOR REMOVIDO!|\n");
        printf("-----------------\n");
    }
    else
    {
        system("clear");
        printf("---------------------\n");
        printf("|VALOR NAO ENCONTRADO|\n");
        printf("---------------------\n");
    }
    imprimeListaCircular(*ptlista);
}
//********************************************************************************************************************************************************** */
void inserirListaDuplamente(struct s_no **ptlista)
{
    struct s_no *novo_no;
    int valor, continuar;
    if (*ptlista == NULL)
    {
        *ptlista = (struct s_no *)malloc(sizeof(struct s_no));
        if (*ptlista == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        (*ptlista)->prox = NULL;
        (*ptlista)->ante = NULL;
    }

    do
    {
        struct s_no *head = *ptlista;
        struct s_no *pont = head;
        // Aloca um novo no
        novo_no = (struct s_no *)malloc(sizeof(struct s_no));
        if (novo_no == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        // Solicita um valor ao usuario
        printf("Digite o valor do novo no: ");
        scanf("%d", &valor);

        // Inicia o novo no
        novo_no->info = valor;
        novo_no->prox = NULL;

        if (head->prox == NULL)
        {
            head->prox = novo_no;
            novo_no->ante = head;
        }
        else
        {
            while (pont->prox != NULL)
            {
                pont = pont->prox;
            }
            pont->prox = novo_no;
            novo_no->ante = pont;
        }

        imprimeListaDuplamente(*ptlista);
        printf("Deseja inserir outro valor? (1-SIM, 2-NAO): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

int buscarListaDuplamente(struct s_no *ptlista, int x)
{
    struct s_no *pont = ptlista->prox; // Comeca com o proximo no apos o no cabeca
    while (pont != NULL)
    {
        if (pont->info == x)
        {
            return 1; // Encontrou o valor
        }
        pont = pont->prox;
    }
    return 0; // Nao encontrou o valor
}

void removerListaDuplamente(struct s_no **ptlista)
{
    struct s_no *ant = NULL, *exc, *pont = (*ptlista)->prox;
    int valor;

    printf("Digite o valor para excluir: ");
    scanf("%d", &valor);

    while (pont != NULL && pont->info != valor)
    {
        ant = pont;
        pont = pont->prox;
    }

    if (pont == NULL)
    {
        system("clear");
        printf("\n--------------------\n");
        printf("|VALOR NAO ENCONTRADO|\n");
        printf("---------------------\n");
        imprimeListaDuplamente(*ptlista);
        return;
    }

    if (ant == NULL)
    {
        (*ptlista)->prox = pont->prox;
        if (pont->prox != NULL)
        {
            exc = pont;
            pont = pont->prox;
            pont->ante = *ptlista;
        }
    }
    else
    {
        ant->prox = pont->prox;
        if (pont->prox != NULL)
        {
            exc = pont;
            pont = pont->prox;
            pont->ante = ant;
        }
    }

    free(exc);
    system("clear");
    printf("\n-----------------\n");
    printf("|VALOR REMOVIDO!|\n");
    printf("-----------------\n");
    imprimeListaDuplamente(*ptlista);
}
//********************************************************************************************************************************************************** */
void inserirFila(struct s_no **ptlista)
{
    struct s_no *novo_no, *fim = *ptlista;
    int valor, continuar;

    do
    {
        // Aloca um novo no
        novo_no = (struct s_no *)malloc(sizeof(struct s_no));
        if (novo_no == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        // Solicita um valor ao usuario
        printf("Digite o valor do novo no: ");
        scanf("%d", &valor);

        novo_no->info = valor;
        novo_no->prox = NULL;

        if (fim != NULL)
        {
            fim->prox = novo_no;
        }
        else
        {
            *ptlista = novo_no;
        }
        fim = novo_no;

        imprimeFilaPilha(*ptlista);
        printf("Deseja inserir outro valor? (1-SIM, 2-NAO): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

void removerFila(struct s_no **ptlista)
{
    struct s_no *removido;
    if (*ptlista != NULL)
    {
        removido = *ptlista;
        *ptlista = (*ptlista)->prox;
        free(removido);
        system("clear");
        printf("\n[FILA ATUALIZADA]:\n");
        imprimeFilaPilha(*ptlista);
    }
}

//******************************************************************************************************************************************************** */
void inserirPilha(struct s_no **ptlista)
{
    struct s_no *novo_no; // novo_no é o topo
    int valor, continuar;

    do
    {
        // Aloca um novo no
        novo_no = (struct s_no *)malloc(sizeof(struct s_no));
        if (novo_no == NULL)
        {
            printf("[ERROR]: Erro ao alocar memoria!\n");
            return;
        }
        // Solicita um valor ao usuario
        printf("Digite o valor do novo no: ");
        scanf("%d", &valor);

        novo_no->info = valor;
        novo_no->prox = *ptlista;
        *ptlista = novo_no;

        printf("TOPO → ");
        imprimeFilaPilha(*ptlista);
        printf("Deseja inserir outro valor? (1-SIM, 2-NAO): ");
        scanf("%d", &continuar);
    } while (continuar == 1);
}

// AJUSTAR IMPRESSAO
void removerPilha(struct s_no **ptlista)
{
    struct s_no *removido;
    if (*ptlista != NULL)
    {
        removido = *ptlista;
        *ptlista = (*ptlista)->prox;
        free(removido);
        system("clear");
        printf("\n[PILHA ATUALIZADA]:\n");
        imprimeFilaPilha(*ptlista);
    }
}

//******************************************************************************************************************************************************** */
int main()
{
    struct s_no *ptlista = NULL;
    int op, op2;
    int x;
    system("clear");
    printf("1.Lista simplesmente encadeada sem no cabeca ordenada\n");
    printf("2.Lista circular simplesmente encadeada sem no cabeca ordenada\n");
    printf("3.Lista duplamente encadeada com no cabeca (sem ordenacao)\n");
    printf("4.Fila (FIFO)\n");
    printf("5.Pilha(LIFO)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        do
        {
            system("clear");
            printf("Lista simplesmente encadeada sem no cabeca ordenada\n");
            printf("1.Inserir\n");
            printf("2.Buscar\n");
            printf("3.Remover\n");
            printf("0.Sair\n");
            printf("---> ");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                inserirListaEncadeada(&ptlista);
                break;
            case 2:
                if (ptlista == NULL)
                {
                    imprimeListaEncadeada(ptlista);
                    getchar();
                }
                else
                {
                    printf("Digite um valor para buscar na lista: ");
                    scanf("%d", &x);
                    if (buscarListaEncadeada(ptlista, x))
                    {
                        system("clear");
                        printf("\nENCONTRADO!!\n"); // MELHORAR VISUAL
                        imprimeListaEncadeada(ptlista);
                        getchar();
                    }
                    else
                    {
                        system("clear");
                        printf("\nNAO ENCONTRADO\n"); // MELHORAR VISUAL
                        imprimeListaEncadeada(ptlista);
                        getchar();
                    }
                }
                break;
            case 3:
                if (ptlista == NULL)
                {
                    imprimeListaEncadeada(ptlista);
                    getchar();
                }
                else
                {
                    removerListaEncadeada(&ptlista);
                    getchar();
                }
                break;

            case 0:
                system("clear");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
            getchar();
        } while (op2 != 0);
        break;
    case 2:
        do
        {
            system("clear");
            printf("Lista circular simplesmente encadeada sem no cabeca ordenada\n");
            printf("1.Inserir\n");
            printf("2.Buscar\n");
            printf("3.Remover\n");
            printf("0.Sair\n");
            printf("---> ");
            scanf("%d", &op2);

            switch (op2)
            {
            case 1:
                inserirListaCircular(&ptlista);
                break;
            case 2:
                if (ptlista == NULL)
                {
                    imprimeListaCircular(ptlista);
                    getchar();
                }
                else
                {
                    printf("Digite um valor para buscar na lista: ");
                    scanf("%d", &x);
                    if (buscarListaCircular(ptlista, x))
                    {
                        system("clear");
                        printf("\nENCONTRADO!!\n"); // MELHORAR VISUAL
                        imprimeListaCircular(ptlista);
                        getchar();
                    }
                    else
                    {
                        system("clear");
                        printf("\nNAO ENCONTRADO\n"); // MELHORAR VISUAL
                        imprimeListaCircular(ptlista);
                        getchar();
                    }
                }
                break;
            case 3:
                if (ptlista == NULL)
                {
                    imprimeListaCircular(ptlista);
                    getchar();
                }
                else
                {
                    removerListaCircular(&ptlista);
                    getchar();
                }
                break;
            case 0:
                system("clear");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
            getchar();
        } while (op2 != 0);
        break;
    case 3:
        do
        {
            system("clear");
            printf("Lista duplamente encadeada com no cabeca (sem ordenacao)\n");
            printf("1.Inserir\n");
            printf("2.Buscar\n");
            printf("3.Remover\n");
            printf("0.Sair\n");
            printf("---> ");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                inserirListaDuplamente(&ptlista);
                break;
            case 2:
                if (ptlista == NULL || ptlista->prox == NULL)
                {
                    imprimeListaDuplamente(ptlista);
                    getchar();
                }
                else
                {
                    printf("Digite um valor para buscar na lista: ");
                    scanf("%d", &x);
                    if (buscarListaDuplamente(ptlista, x))
                    {
                        system("clear");
                        printf("\nENCONTRADO!!\n");
                        imprimeListaDuplamente(ptlista);
                        getchar();
                    }
                    else
                    {
                        system("clear");
                        printf("\nNAO ENCONTRADO!!\n");
                        imprimeListaDuplamente(ptlista);
                        getchar();
                    }
                }
                break;
            case 3:
                if (ptlista == NULL || ptlista->prox == NULL)
                {
                    imprimeListaDuplamente(ptlista);
                    getchar();
                }
                else
                {
                    removerListaDuplamente(&ptlista);
                    getchar();
                }
                break;
            case 0:
                system("clear");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
            getchar();
        } while (op2 != 0);
        break;
    case 4:
        do
        {
            system("clear");
            printf("Fila (FIFO)\n");
            printf("1.Inserir\n");
            printf("2.Remover\n");
            printf("0.Sair\n");
            printf("---> ");
            scanf("%d", &op2);

            switch (op2)
            {
            case 1:
                inserirFila(&ptlista);
                break;
            case 2:
                if (ptlista == NULL)
                {
                    imprimeFilaPilha(ptlista);
                    getchar();
                }
                else
                {
                    removerFila(&ptlista);
                    getchar();
                }
                break;
            case 0:
                system("clear");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
            getchar();
        } while (op2 != 0);

        break;
    case 5:
        do
        {
            system("clear");
            printf("Pilha (LIFO)\n");
            printf("1.Inserir\n");
            printf("2.Remover\n");
            printf("0.Sair\n");
            printf("---> ");
            scanf("%d", &op2);

            switch (op2)
            {
            case 1:
                inserirPilha(&ptlista);
                break;
            case 2:
                if (ptlista == NULL)
                {
                    imprimeFilaPilha(ptlista);
                    getchar();
                }
                else
                {
                    removerPilha(&ptlista);
                    getchar();
                }
                break;
            case 0:
                system("clear");
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
            getchar();
        } while (op2 != 0);
        break;
    }
    // desalocaMemoria(ptlista);
    if (op == 2) // Caso o usuario escolha Lista Circular
        desalocaCircular(&ptlista);
    else
        desalocaMemoria(ptlista);
    return 0;
}