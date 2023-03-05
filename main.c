#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define N 6

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];
};


// Data structure to store adjacency list nodes of the graph
struct Node
{
    int dest;
    struct Node* next;
};

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};





// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    // add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // get the source and destination vertex
        int src = edges[i].src;
        int dest = edges[i].dest;

        // allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;

        // point new node to the current head
        newNode->next = graph->head[src];

        // point head pointer to the new node
        graph->head[src] = newNode;
    }

    return graph;
}

