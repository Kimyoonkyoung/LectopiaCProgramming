/*
	!!������ ����ϱ�

	������ 2~9���� �� ȭ�鿡 ������ ���� ����ϵ� 2�� for���� 2set�� �̿��ؼ� �ѹ� ����ϰ�
	�ٷ� �̾ 3�� for�� 1set���� �̿��ؼ� �Ȱ��� ��µǵ��� �ۼ��Ͻÿ�

	@2017.01.11 pm09:17
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j, k;

	printf("<2�� for���� �̿��� ���>\n");

	for (i = 1; i <= 9; i++)
	{
		for (j = 2; j <= 5; j++ )
			printf("%d * %d = %2d\t", j, i, j*i);

		printf("\n");
	}

	printf("\n\n");

	for (i = 1; i <= 9; i++)
	{
		for (j = 6; j <= 9; j++)
			printf("%d * %d = %2d\t", j, i, j*i);

		printf("\n");
	}

	printf("---------------------------------------------------------------------------------- \n\n");
	printf("<3�� for���� �̿��� ���>\n");

	for (i = 2; i <= 6; i += 4)
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = i; k <= (i + 3); k++)
				printf("%d * %d = %2d\t", k, j, k * j);

			printf("\n");
		}
		printf("\n\n");
	}
}
#endif