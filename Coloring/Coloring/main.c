#include <cstdio>
#include <stdlib.h>
enum boolean {
	false,
	true,
};

//creates empty 2-dimentional size x size table
void createEmpty2DimentionalTable(int **tab, int size)
{
	tab = malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++)
		tab[i] = malloc(sizeof(int)*size);
}
//fills 2-dimentional size x size table
void fill2DimentionalTable(int **tab, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%d", &tab[i][j]);
}
//counts connections in graph
int countConnectionsInGraph(int **graph, int graph_size)
{
	int count_of_connections;
	for (int i = 0; i < graph_size; i++)
		for (int j = 0; j < graph_size; j++)
			count_of_connections += graph[i][j];
	return count_of_connections;
}
//checks if graph is full
enum boolean isGraphFull(int **graph, int graph_size, int count_of_connections)
{
	int countOfConnectionsInFullGraph = graph_size * (graph_size - 1);
	if (count_of_connections == countOfConnectionsInFullGraph) return true;
	else return false;
}
//checks if graph is empty
enum boolean isGraphEmpty(int **graph, int graph_size, int count_of_connections)
{
	int countOfConnectionsInEmptyGraph = 0;
	if (count_of_connections == countOfConnectionsInEmptyGraph) return true;
	else return false;
}
int main()
{
	int graph_length = 0,
		**graph,
		degree,
		maximal_degree = 0,
		vertex = 0,
		sum = 0;
	return 0;
}