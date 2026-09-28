PROGRAM:

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Node {
     int vertex;
     struct Node* next;
};

struct Graph {
     struct Node* adjLists[MAX_VERTICES];
     int visited[MAX_VERTICES];
};

struct Queue {
     int items[MAX_VERTICES];
     int front;
     int rear;
};

struct Node* createNode(int v) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->vertex = v;
     newNode->next = NULL;
     return newNode;
}

struct Graph* createGraph() {
     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
     int i;
     for (i = 0; i < MAX_VERTICES; i++) {
         graph->adjLists[i] = NULL;
         graph->visited[i] = 0;
     }
     return graph;
}

struct Queue* createQueue() {
     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
     q->front = -1;
     q->rear = -1;
     return q;
}

int isEmpty(struct Queue* q) {
     return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
     if (q->rear == MAX_VERTICES - 1)
         printf("Queue is full\n");
     else {
         if (q->front == -1) q->front = 0;
         q->rear++;
         q->items[q->rear] = value;
     }
}

int dequeue(struct Queue* q) {
     int item;
     if (isEmpty(q)) {
         printf("Queue is empty\n");
         item = -1;
     } else {
         item = q->items[q->front];
         q->front++;
         if (q->front > q->rear) {
             q->front = q->rear = -1;
         }
     }
     return item;
}

void addEdge(struct Graph* graph, int src, int dest) {
     struct Node* newNode = createNode(dest);
     newNode->next = graph->adjLists[src];
     graph->adjLists[src] = newNode;
     newNode = createNode(src);
     newNode->next = graph->adjLists[dest];
     graph->adjLists[dest] = newNode;
}

void BFS(struct Graph* graph, int startVertex) {
     struct Queue* q = createQueue();
     graph->visited[startVertex] = 1;
     enqueue(q, startVertex);
     while (!isEmpty(q)) {
         int currentVertex = dequeue(q);
         printf("Visited %d\n", currentVertex);
         struct Node* temp = graph->adjLists[currentVertex];
         while (temp) {
             int adjVertex = temp->vertex;
             if (graph->visited[adjVertex] == 0) {
                 graph->visited[adjVertex] = 1;
                 enqueue(q, adjVertex);
             }
             temp = temp->next;
         }
     }
}

int main() {
     struct Graph* graph = createGraph();
     addEdge(graph, 0, 1);
     addEdge(graph, 0, 2);
     addEdge(graph, 1, 2);
     addEdge(graph, 1, 3);
     addEdge(graph, 2, 3);
     printf("BFS Traversal starting from vertex 0:\n");
     BFS(graph, 0);
     return 0;
}
