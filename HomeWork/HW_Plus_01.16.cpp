#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int*** myAlloc(int, int, int);
void dataInput(int***, int, int, int);
void dataOutput(int***, int, int, int);
void myDelete(int ***, int, int);
int random(int n);

int main()
{
	int ***ip;
	int wall, col, row;

	printf("wall(��) �� �Է� : ");
	scanf("%d", &wall);
	
	printf("row�� �Է� : ");
	scanf("%d", &row);

	printf("col �� �Է� : ");
	scanf("%d", &col);

	ip = myAlloc(wall, row, col);
	dataInput(ip, wall, row, col);
	dataOutput(ip, wall, row, col);
	myDelete(ip, wall, row);

}

int*** myAlloc(int wall, int row, int col)
{
	int i, j;
	int ***p;

	p = (int***)malloc(sizeof(int**) * wall);
	assert(p != NULL);

	for (i = 0; i < wall; i++)
	{
		p[i] = (int **)malloc(sizeof(int*) * row);
		assert(p[i] != NULL);

		for (j = 0; j < row; j++)
		{
			p[i][j] = (int*)malloc(sizeof(int) * col);
			assert(p[i][j] != NULL);
		}
	}

	return p;
}

void dataInput(int ***ip, int wall, int row, int col)
{
	int i, j, k;

	for (i = 0; i < wall; i++)
	{
		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
			{
				srand((unsigned int)time(NULL));
				ip[i][j][k] = random(9) + 1;
			}
		}
	}
}

void dataOutput(int ***ip, int wall, int row, int col)
{
	int i, j, k;

	for (i = 0; i < wall; i++)
	{
		printf("%d��\n", i + 1);
		for (j = 0; j < row; j++)
		{
			printf("%d�� \n", j + 1);
			for (k = 0; k < col; k++)
			{
				printf("%d  ", ip[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void myDelete(int ***ip, int wall, int row)
{
	int i, j;

	for (i = 0; i < wall; i++)
	{
		for (j = 0; j < row; j++)
			free(ip[i][j]);

		free(ip[i]);
	}

	free(ip);
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}