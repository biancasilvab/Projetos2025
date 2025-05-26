# Alocação encadeada
Este código é uma implementação de estruturas de dados dinâmicos com **alocação encadeada**, onde o usuário pode escolher interativamente entre diferentes tipos de listas.

## Lista simplesmente encadeada  
`void inserirListaEncadeada(struct s_no **ptlista)`  
`int buscarListaEncadeada(struct s_no *ptlista, int x)`   
`void removerListaEncadeada(struct s_no **ptlista)`  
`void imprimeListaEncadeada(struct s_no *ptlista)`  

 ## Lista simplesmente circular 
`void inserirListaCircular(struct s_no **ptlista)`  
`int buscarListaCircular(struct s_no *ptlista, int x)`  
`void removerListaCircular(struct s_no **ptlista)`  
`void imprimeListaCircular(struct s_no *ptlista)`

## Lista duplamente encadeada com nó cabeça
`void inserirListaDuplamente(struct s_no **ptlista)`  
`int buscarListaDuplamente(struct s_no *ptlista, int x)`  
`void removerListaDuplamente(struct s_no **ptlista)`  
`void imprimeListaDuplamente(struct s_no *ptlista)`  

## Fila (FIFO)  
`void inserirFila(struct s_no **ptlista)`  
`void removerFila(struct s_no **ptlista)`  
`void imprimeFilaPilha(struct s_no *ptlista)`  

## Pilha (LIFO)  
`void inserirPilha(struct s_no **ptlista)`  
`void removerPilha(struct s_no **ptlista)`  
`void imprimeFilaPilha(struct s_no *ptlista)`

# Compilação
Execute pela linha de comando do Linux  
##### `gcc t1.c -o t1 -Wall -Wextra -pedantic`
