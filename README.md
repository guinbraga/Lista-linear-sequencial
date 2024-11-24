Nesta atividade, recebemos três arquivos para um programa em C que realizava a implementação de uma lista linear sequencial estática, e foi-nos pedido que implementássemos a alocação dinâmica dessa lista seguindo as seguintes regras:
- Ao atingir a capacidade máxima, devíamos dobrar o tamanho da lista;
- Ao atingir 25% da capacidade máxima da lista, deveríamos diminuí-la pela metade;

Fizemos a implementação usando a função realloc nas funções da Inserção e da Exclusão de elementos, verificando o nro de elementos da lista era igual (ou 1/4) 
da capacidade máxima de elementos da lista. Usando uma variável para a capacidade máxima 'max' e passando um ponteiro para essa variável nas funções de Inserção e Exclusão,
fazemos a realocação e mudamos o valor da variável dentro das funções. 

Para demonstrar o funcionamento, também adaptamos a função de tamanho em Bytes para que funcione de maneira dinâmica a partir da variável 'max', e modificamos
o código no cliente de forma a demonstrar a alocação dinâmica com loops. Ao final do programa, usamos a função free() para a liberação da memórima alocada dinamicamente, assim impedindo vazamentos de memória.
