
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

typedef struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void dfs(Graph *g, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[v][i] && !visited[i]) {
            dfs(g, i);
        }
    }
}

void dfs_traversal(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < g->num_vertices; i++) {
        if (!visited[i]) {
            dfs(g, i);
        }
    }
}

int main() {
    Graph g = {
        .num_vertices = 5,
        .adj_matrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}
        }
    };

    printf("DFS Traversal: ");
    dfs_traversal(&g);
    printf("\n");

    return 0;
}
