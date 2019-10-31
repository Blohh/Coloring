#include <cstdio>
#include <stdlib.h>

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