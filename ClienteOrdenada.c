// main.c
#include "ListaOrdenada.h"

int main() {
  LISTA lista;
  REGISTRO reg;
  int max = 50;
  // Inicializar a lista
  inicializarLista(&lista, max);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Capacidade máxima da lista: %i.\n", max);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista em capacidade máxima (em bytes): %i.\n", tamanhoEmBytes(&lista, max));

  // Inserir elementos na lista com alocação dinamica: Necessário modificar a 
  // função de inserir para conferir o tamanho e decidir se é necessária a realocação.
  
  // No cliente, necessário inserir numeros em loop para demonstrar o alocamento.
  for (int i = 0; i<57; i++){
    reg.chave = i;
    inserirElemListaOrdSemDup(&lista, reg, &max);
  }


  // Exibir lista após inserções
  exibirLista(&lista);
  printf("Capacidade máxima da lista: %i.\n", max);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista em capacidade máxima (em bytes): %i.\n", tamanhoEmBytes(&lista, max));

  // Buscar um elemento na lista
  int pos = buscaSequencial(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaBinaria(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaSentinela(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);

  // Excluir alguns elementos da lista
  for (int i = 56; i>10; i--){
    excluirElemLista(&lista, i, &max);
  }


  // Exibir lista após exclusões
  exibirLista(&lista);
  printf("Capacidade máxima da lista: %i.\n", max);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista em capacidade máxima (em bytes): %i.\n", tamanhoEmBytes(&lista, max));

  // Reinicializar a lista
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Capacidade máxima da lista: %i.\n", max);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista em capacidade máxima (em bytes): %i.\n", tamanhoEmBytes(&lista, max));

  // Liberar memória alocada dinamicamente:
  free(lista.A);

  return 0;
}
