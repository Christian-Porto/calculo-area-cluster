# Cálculo Paralelo de uma Função Matemática com MPI

Este programa usa MPI para calcular de forma paralela a soma de `(x*x + x)` para um conjunto de intervalos, distribuídos entre vários processos. A soma resultante é usada para calcular um valor final que é comparado com a constante `0.8333333333333333333`.

## Funcionalidades

- **Cálculo Paralelo**: Utiliza a capacidade de processamento paralelo do MPI para dividir e calcular a função matemática em múltiplos processadores.
- **Redução de Dados**: Combina os resultados de todos os processos usando `MPI_Reduce` para calcular o valor final de pi.
- **Comparação com Constante**: Compara o resultado final com uma constante predefinida para determinar o erro.
