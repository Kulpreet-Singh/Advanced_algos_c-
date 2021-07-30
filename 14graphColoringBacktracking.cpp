#include <stdbool.h>
#include <stdio.h>
#define V 4

void printSolution(int color[])
{
	printf("Solution Exists: Following are the assigned colors \n");
	for (int i = 0; i < V; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}

bool graphColoringUtil(	bool graph[V][V], int m, int color[], int v)
{
	if (v == V){
		printf("\nPossible Solution: ");
		printSolution(color);
		printf("\n");
		return true;
	}
	bool res = false;
	for (int c = 1; c <= m; c++) {
		if (isSafe(	v, graph, color, c)) {
			color[v] = c;
			res = graphColoringUtil(graph, m, color, v + 1) || res;
			color[v] = 0;
		}
	}
	return res;
}

bool graphColoring( bool graph[V][V], int m)
{
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;
	if (
		graphColoringUtil(graph, m, color, 0) == false) {
		printf("Solution does not exist");
		return false;
	}
//	printSolution(color);
	return true;
}



int main()
{
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; 
	graphColoring(graph, m);
	return 0;
}

