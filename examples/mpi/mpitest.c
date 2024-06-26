#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int rc;
    int size;
    int myrank;

    rc = MPI_Init (&argc, &argv);
    if (rc != MPI_SUCCESS) {
        fprintf (stderr, "MPI_Init() failed");
        return EXIT_FAILURE;
    }

    rc = MPI_Comm_size (MPI_COMM_WORLD, &size);
    if (rc != MPI_SUCCESS) {
        fprintf (stderr, "MPI_Comm_size() failed");
        MPI_Finalize();
        return EXIT_FAILURE;
    }

    rc = MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
    if (rc != MPI_SUCCESS) {
        fprintf (stderr, "MPI_Comm_rank() failed");
        MPI_Finalize();
        return EXIT_FAILURE;
    }

    fprintf (stdout, "Hello, I am rank %d/%d\n", myrank, size);
    MPI_Finalize();
    return EXIT_SUCCESS;
}
