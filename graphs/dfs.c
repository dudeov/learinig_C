#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct GraphNode {
    char value;
    int neighbors_count;
    /*
    Почему "**neighbors"? Потому в дальнейшем зто будет массив указателей;
    struct GraphNode **neighbors == stuct GraphNode *neighbors[10];
    
    Но мы будем выделять память в куче:
    Node->neighbors = malloc(10*sizeof(struct GraphNode *));
    */
    struct GraphNode **neighbors;
};

struct Graph {
    int size;
    struct GraphNode **nodes;
    /*
    Почему бы не вернуть просто *root?
    Потому что потом нельзя будет достучаться до остальных эл-тов графа:
    Можно: grpaph->root
    Нельзя: graph->random_node

    А так можно достучаться до любого эл-та графа:
    graph->nodes[index]
    */
};

struct Visited {
    int size;
    struct GraphNode **nodes;
};


struct Graph *createGraph() {
    /*
    
        A
        |\
        B-C
        | |\
        D-E-J
        |/
        F
    
    in Python:
    tree = {"A":["B","C"], "B":["C", "A", "D"], "C":["B", "E", "J"], "D":["E", "F"], "E":["D", "C","J"], "J":["E", "C"], "F":["D", "E"],}
    */
    struct Graph *graph = malloc(sizeof(*graph));
    graph->size = 7;
    graph->nodes = malloc(graph->size * sizeof(struct GraphNode *));
    struct GraphNode *A = malloc(sizeof(struct GraphNode));
    graph->nodes[0] = A;
    struct GraphNode *B = malloc(sizeof(struct GraphNode));
    graph->nodes[1] = B;
    struct GraphNode *C = malloc(sizeof(struct GraphNode));
    graph->nodes[2] = C;
    struct GraphNode *D = malloc(sizeof(struct GraphNode));
    graph->nodes[3] = D;
    struct GraphNode *E = malloc(sizeof(struct GraphNode));
    graph->nodes[4] = E;
    struct GraphNode *F = malloc(sizeof(struct GraphNode));
    graph->nodes[5] = F;
    struct GraphNode *J = malloc(sizeof(struct GraphNode));
    graph->nodes[6] = J;

    A->value = 'A';
    A->neighbors_count = 2;
    A->neighbors = malloc(A->neighbors_count*sizeof(struct GraphNode *));
    A->neighbors[0] = B;
    A->neighbors[1] = C;

    B->value = 'B';
    B->neighbors_count = 2;
    B->neighbors = malloc(B->neighbors_count*sizeof(struct GraphNode *));
    B->neighbors[0] = C;
    B->neighbors[2] = D;

    C->value = 'C';
    C->neighbors_count = 4;
    C->neighbors = malloc(C->neighbors_count*sizeof(struct GraphNode *));
    C->neighbors[0] = B;
    C->neighbors[1] = E;
    C->neighbors[2] = J;
    C->neighbors[3] = D;

    D->value = 'D';
    D->neighbors_count = 4;
    D->neighbors = malloc(D->neighbors_count*sizeof(struct GraphNode *));
    D->neighbors[0] = B;
    D->neighbors[1] = C;
    D->neighbors[2] = E;
    D->neighbors[3] = F;
    
    E->value = 'E';
    E->neighbors_count = 5;
    E->neighbors = malloc(E->neighbors_count*sizeof(struct GraphNode *));
    E->neighbors[0] = D;
    E->neighbors[1] = C;
    E->neighbors[2] = J;
    E->neighbors[3] = F;
    E->neighbors[4] = B;

    J->value = 'J';
    J->neighbors_count = 2;
    J->neighbors = malloc(J->neighbors_count*sizeof(struct GraphNode *));
    J->neighbors[0] = C;
    J->neighbors[1] = E;

    F->value = 'F';
    F->neighbors_count = 3;
    F->neighbors = malloc(F->neighbors_count*sizeof(struct GraphNode *));
    F->neighbors[0] = D;
    F->neighbors[1] = E;
    F->neighbors[2] = J;

    return graph;
}


void DFS(struct Graph *graph, struct GraphNode *cpointer, struct Visited *visited) {
    if (graph->size == visited->size)
        return;
    for (int i = 0; i < visited->size; i++) {
        if (visited->nodes[i] == cpointer) {
            return;
        }
    }
    visited->nodes[visited->size] = cpointer;
    visited->size++;
    printf("Visiting %c, ", cpointer->value);
    for (int i = 0; i < cpointer->neighbors_count; i++) {
        DFS(graph, cpointer->neighbors[i], visited);
    }
}

int main() {
    struct Graph *newGraph = createGraph();
    struct Visited *visited = malloc(sizeof(struct Visited));
    visited->nodes = malloc(newGraph->size*sizeof(struct GraphNode *));
    visited->size = 0;
    DFS(newGraph, newGraph->nodes[0], visited);
    // Visiting A, Visiting B, Visiting C, Visiting E, Visiting D, Visiting F, Visiting J,
}
