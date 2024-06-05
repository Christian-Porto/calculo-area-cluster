#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char** argv) {
    int n, i, procid, nprocs;
    double pi;
    double sum, x, h, mypi;
    double cincobarraseis = 0.8333333333333333333;

    // Inicializa o ambiente MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &procid);

    // Obtém o nome do processador
    char nome_do_processo[MPI_MAX_PROCESSOR_NAME];
    int tamanho_nome;
    MPI_Get_processor_name(nome_do_processo, &tamanho_nome);

    if (procid == 0) {
        printf("Entre com o número de intervalos: ");
        scanf("%d", &n);
    }

    // Broadcast do número de intervalos para todos os processos
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    h = 1.0 / (double) n;
    sum = 0.0;
    for (i = procid + 1; i <= n; i += nprocs) {
        x = h * ((double)i - 0.5);
        sum +=((x*x) + x);
    }
    mypi = h * sum;

    // Reduz todos os valores de pi locais em pi final
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (procid == 0) {
        printf("Pi é aproximadamente %.16f, erro é %.16f\n", pi, fabs(cincobarraseis-pi));
    }

    // Finaliza o ambiente MPI
    MPI_Finalize();
    return 0;
}