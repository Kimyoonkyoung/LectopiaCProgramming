/*
	!!��Ī�Ǵ� �����

	���� ���� �Է� �޾� 2�� for���� �̿��Ͽ� ������ ���� ����Ͻÿ�.
	�ݺ������ϰ� ���� �� �Է¶����� ���� �Է½� ����.
	��, ������ iterator���� i, j �� ���μ� ���庯�� 1�� �� 3���� ����Ͽ� �ۼ� �� ��. 

	@2017.01.11 pm08:59
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j, inputNum;

	printf("# ��� ���μ��� �Է��Ͻÿ� : ");
	scanf("%d", &inputNum);

	while (getchar() == '\n')
	{
		for (i = inputNum; i >= 0; i--)
		{
			for (j = 0; j < (inputNum - i); j++)
				printf("*");
			for (j = 0; j <= (i * 2); j++)
				printf(" ");
			for (j = 0; j < (inputNum - i); j++)
				printf("*");
			printf("\n");
		}

		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
		scanf("%d", &inputNum);
	}
}
#endif