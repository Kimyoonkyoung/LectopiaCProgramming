#include <stdio.h>

int main()
{
	double height, sum = 0;
	int i = 0;

	while (i < 5)
	{
		printf("- %d �� �л��� Ű��? ", i + 1);
		scanf("%lf", &height);
		sum += height;
		i++;
	}

	sum /= 5;

	printf("�ټ� ���� ��� Ű�� %.1lfcm �Դϴ�.", sum);
}