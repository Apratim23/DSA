
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int v[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

void enqueue(Queue *q, int vertex) {
    q->v[q->rear++] = vertex;
}

int dequeue(Queue *q) {
    return q->v[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void bfs(int adj[][MAX_VERTICES], int visited[], int n, int start) {
    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (adj[vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int n, start;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(adj, visited, n, start);

    return 0;
}
