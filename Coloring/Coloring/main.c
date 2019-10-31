#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}
//counts connections in graph
int countConnectionsInGraph(int **graph, int graph_size)
{
	int count_of_connections = 0;;
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
void createVisitedTable(int graph_size, enum boolean *visited)
{
	for (int i = 0; i < graph_size; i++) visited[i] = false;
}
//checks if chromatic number is greater than maximal degree
enum boolean isChromaticNumberGreaterThanMaximalGraphDegree(int **graph, int graph_size)
{
	enum boolean *visited = malloc(sizeof(enum boolean)*graph_size);
	createVisitedTable(graph_size, visited);
	int vertex_of_maximal_degree = foundVertexOfMaximalDegree(graph, graph_size);
	//if (isGraphEmpty(graph, graph_size, count_of_connections) == true || isGraphFull(graph, graph_size, count_of_connections)) return true;
	if (subGraphIsFull(graph, graph_size, vertex_of_maximal_degree)) return true;
	else if (isOddCycle(graph, visited, vertex_of_maximal_degree, graph_size)) return true;
	return false;
}
int main()
{
	int graph_length = 0,
		**graph;
	scanf("%d", &graph_length);
	graph = malloc(sizeof(int*)*graph_length);
	for (int i = 0; i < graph_length; i++)
		graph[i] = malloc(sizeof(int)*graph_length);
	fill2DimentionalTable(graph, graph_length);
	enum boolean is_chromatic_number_greater = isChromaticNumberGreaterThanMaximalGraphDegree(graph, graph_length);
	if (is_chromatic_number_greater == true) printf("True");
	else printf("False");
	for (int i = 0; i < graph_length; i++)
		free(graph[i]);
	free(graph);
	return 0;
}