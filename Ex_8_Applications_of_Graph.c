PROGRAM:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10
#define INFINITY 999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src);

int main() {
     int graph[MAX_VERTICES][MAX_VERTICES], n, src;
     printf("Enter the number of vertices: ");
     scanf("%d", &n);
     printf("Enter the cost adjacency matrix (enter %d for no direct path):\n", INFINITY);
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
             scanf("%d", &graph[i][j]);
             if (graph[i][j] == 0 && i != j) {
                 graph[i][j] = INFINITY;
             }
         }
     }
     printf("Enter the source vertex (starting from 0): ");
     scanf("%d", &src);
     dijkstra(graph, n, src);
     return 0;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
     int dist[MAX_VERTICES], visited[MAX_VERTICES], count, minDist, nextNode;
     for (int i = 0; i < n; i++) {
         dist[i] = graph[src][i];
         visited[i] = 0;
     }
     dist[src] = 0;
     visited[src] = 1;
     count = 1;
     while (count < n - 1) {
         minDist = INFINITY;
         for (int i = 0; i < n; i++) {
             if (dist[i] < minDist && !visited[i]) {
                 minDist = dist[i];
                 nextNode = i;
             }
         }
         visited[nextNode] = 1;
         for (int i = 0; i < n; i++) {
             if (!visited[i]) {
                 if (minDist + graph[nextNode][i] < dist[i]) {
                     dist[i] = minDist + graph[nextNode][i];
                 }
             }
         }
         count++;
     }
     printf("\nShortest distances from source %d:\n", src);
     for (int i = 0; i < n; i++) {
         if (i != src) {
             printf("To vertex %d: %d\n", i, dist[i]);
         }
     }
}
