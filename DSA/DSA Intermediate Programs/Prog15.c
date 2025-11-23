#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];  
int n = 0;  

void createGraph() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Graph Created Successfully.\n");
}

void insertEdge() {
    int u, v;
    printf("Enter the two vertices for the edge (u v): ");
    scanf("%d %d", &u, &v);

    if (u >= n || v >= n || u < 0 || v < 0) {
        printf("Invalid vertices.\n");
        return;
    }

    adj[u][v] = 1;
    adj[v][u] = 1; 
    printf("Edge inserted between %d and %d.\n", u, v);
}

void printAdjMatrix() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void listAdjacentVertices() {
    int v, i;
    printf("Enter the vertex: ");
    scanf("%d", &v);

    if (v >= n || v < 0) {
        printf("Invalid vertex.\n");
        return;
    }

    printf("Vertices adjacent to %d: ", v);
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create Graph\n");
        printf("2. Insert an Edge\n");
        printf("3. Print Adjacency Matrix\n");
        printf("4. List Adjacent Vertices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createGraph(); break;
            case 2: insertEdge(); break;
            case 3: printAdjMatrix(); break;
            case 4: listAdjacentVertices(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

