#if 0
#include <stdio.h>

int inputCount();
int costCalculator(int);
void outputCost(int);

int main()
{
	int count, costCclt;
	count = inputCount();

	costCclt = costCalculator(count);

	outputCost(costCclt);
}

int inputCount()
{
	int count;

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &count);

	return count;
}

int costCalculator(int count)
{
	int cost = 0;

	if (count <= 5)
		cost = 600;
	else if (count <= 10)
		cost = 800;
	else
		cost = (cost + 800) + ((int)((count - 10) / 2.0 + 0.5) * 100);

	return cost;
}

void outputCost(int metroCost)
{
	printf("��� : %d \n", metroCost);
}
#endif
