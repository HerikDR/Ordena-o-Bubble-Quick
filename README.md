


## Métodos de Ordenação: Bubble e Quick

Ambos os métodos possuem o propósito de ordenar valores guardados em um conjuto de dados, entretanto, funcionam de formas diferentes.

- **Método Bubble :** Um dos algoritmos mais simples para este propósito. Funciona percorrendo o conjunto de dados inúmeras vezes e, a cada passagem, traz o maior elemento ao topo do conjunto. Eficiente para pequenos conjuntos de dados.

- **Método Quick :** É um método onde a ideia "divida para conquistar" é aplicada. Sendo mais eficiênte para conjunto de dados maiores, seu funcionamento depende de um algoritmo que utiliza pivôs, onde divide em vários pedaços e são ordenados independentemente.

Nos testes de tempo utilizando 5000 pratos para ordenação, obtive:

Bubble: **1642ms**

Quick: **17ms**

O Quick executa a mesma tarefa quase 100x mais rápido que o Bubble, mostrando a diferença de efetividade de ambos métodos para grandes números de elementos.

Em relação aos **pivôs** utilizado no método Quick, foi implementando a função **"selecionar_pivo()"**, onde o pivô será sempre o último elemento do conjunto executado, onde "i" mantém os elementos menores que o pivô onde devem ser colocados. Percorrento o array em "j", se o elemento for igual ou menor ao valor do pivô, ele é movido à esquerda. Após ordenar, o pivô é movido para o primeiro elemento maior que ele. na função void "quick", o pivô se torna a variável "p". Existem outras formas de selecionar um pivô, como fazendo uma mediana ou escolhendo aleatóriamente, o que aumenta a eficiência do algoritmo em larga escala. Entretanto, para manter simplicidade, escolhi utilizar a forma básica.


## Autores

- [@HerikDR](https://github.com/HerikDR)

