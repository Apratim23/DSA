
#include <stdio.h>

#define MAX_VERTICES 10

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges, i, j, degree;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph with 0
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    for (i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    // Display the graph
    printf("The adjacency matrix of the graph is:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Display the degree of each vertex
    for (i = 0; i < vertices; i++) {
        degree = 0;
        for (j = 0; j < vertices; j++) {
            degree += graph[i][j];
        }
        printf("The degree of vertex %d is %d\n", i, degree);
    }

    return 0;
}
