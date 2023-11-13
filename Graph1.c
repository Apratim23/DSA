
#include <stdio.h>

#define MAX_VERTICES 10

int main() {
  int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
  int numVertices, numEdges;

  printf("Enter the number of vertices: ");
  scanf("%d", &numVertices);

  printf("Enter the number of edges: ");
  scanf("%d", &numEdges);

  // Input edges
  for (int i = 0; i < numEdges; i++) {
    int u, v;
    printf("Enter edge %d (u v): ", i + 1);
    scanf("%d %d", &u, &v);
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  // Display adjacency matrix
  printf("\nAdjacency Matrix:\n");
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  // Display degree of each vertex
  printf("\nDegree of each vertex:\n");
  for (int i = 0; i < numVertices; i++) {
    int degree = 0;
    for (int j = 0; j < numVertices; j++) {
      degree += adjMatrix[i][j];
    }
    printf("Vertex %d: %d\n", i, degree);
  }

  return 0;
}
