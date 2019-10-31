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
//return vertex of maximal degree
int foundVertexOfMaximalDegree(int **graph, int graph_length)
{
	int vertex = 0, maximal_degree = 0, degree = 0;
	for (int i = 0; i < graph_length; i++)
	{
		degree = 0;
		for (int j = 0; j < graph_length; j++)
			degree += graph[i][j];
		if (degree > maximal_degree)
		{
			maximal_degree = degree;
			vertex = i;
		}
	}
	return vertex;
}
//return length of subgraph
int subGraphLength(int **graph, enum boolean *visited, int vertex, int graph_length)
{
	int length = 1;
	visited[vertex] = true;
	for (int i = 0; i < graph_length; i++)
	{
		if (graph[vertex][i] == 1)
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				length = 1 + subGraphLength(graph, visited, i, graph_length);
			}

		}
	}
	return length;
}
//check if there is odd cycle
enum boolean isOddCycle(int **graph, enum boolean *visited, int vertex, int graph_length)
{
	int length = subGraphLength(graph, visited, vertex, graph_length), degree = 0;
	for (int i = 0; i < graph_length; i++)
	{
		degree = 0;
		if (visited[i] == true)
		{
			for (int j = 0; j < graph_length; j++)
				degree += graph[i][j];
			if (degree != 2)
				return false;
		}
		if (graph[vertex][i] == 1 && visited[i] == false)
			return false;
	}
	if (length % 2 == 0)
		return false;
	return true;
}
//check if subgraph is full
enum boolean subGraphIsFull(int **graph, int graph_length, int vertex)
{
	for (int i = 0; i < graph_length; i++)
	{
		if (i != vertex && graph[vertex][i] == 1)
		{
			for (int j = i + 1; j < graph_length; j++)
			{
				if (j != vertex && graph[i][j] != graph[vertex][j])
					return false;
			}
		}
	}
	return true;
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