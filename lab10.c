#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// defining no of vertices in the graph
#define V 4

int minKey(int key[], bool mstSet[])
{
// Initialize min value
int min = INT_MAX, min_index;
int v;

for (v = 0; v < V; v++)
{

if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;
}

return min_index;
}

int printMST(int parent[], int graph[V][V])
{
printf("Edge \tWeight\n");
int i;
for (i = 1; i < V; i++)
printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
// Array to store constructed MST
int parent[V];
int key[V];
bool mstSet[V];

int i;
for (i = 0; i < V; i++)
key[i] = INT_MAX, mstSet[i] = false;

// Always including first 1st vertex in MST.
// Making key 0 so that this vertex is picked as first vertex.
key[0] = 0;
parent[0] = -1; // First node is always root of MST

int count;
for ( count = 0; count < V - 1; count++) 
{
// Picking the minimum key vertex from the set of vertices not yet included in MST
int u = minKey(key, mstSet);

// Adding  the picked vertex to the MST Set
mstSet[u] = true;

//considering only those vertices which are not present in mstSet[v]
int v;
for ( v = 0; v < V; v++)

//updating the key value when graph[u][v] is smaller than the key[v]
if ((graph[u][v] && mstSet[v] == false) && graph[u][v] < key[v])
parent[v] = u, key[v] = graph[u][v];
}

printMST(parent, graph);

}

int main()
{

int graph[V][V] = { { 0, 5, 10, 0},
{ 5, 0, 8, 15 },
{ 10, 8, 0, 20 },
{ 0, 15, 20, 0 },};


primMST(graph);

return 0;
}
