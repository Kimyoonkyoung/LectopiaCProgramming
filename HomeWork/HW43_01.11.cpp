/*
	!�ﰢ ���ĺ� ����ϱ�

	������ �빮�ڸ� �Է� �޾� �� ���ں��� 'A' ���ڱ��� ������ ���� ����Ͻÿ�.
	�ݺ� �����ϰ� ������ �빮�� �̿ܿ� �ٸ� ���� �Է� �� ���� �Ͻʽÿ�.
	��, ������ iterator���� i, j �� �Էµ� ���� ���庯�� 1���� ����Ͽ� �� 3���� ������ ����� ��

	@2017.01.11 pm10:58
*/
#if 01
#include <stdio.h>

int main()
{
	int i, j;
	char inputAlpa;

	while (1)
	{
		printf("* ������ �빮�� �Է�( 'A' ~ 'Z' ) : ");
		scanf("%c", &inputAlpa);

		if ((inputAlpa >= 'A' && inputAlpa <= 'Z') != 1)
			break;

		for (i = 0; i <= (inputAlpa - 'A'); i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("%c", (inputAlpa - j));
			}
			printf("\n");
		}

		getchar();
	}
}
#endif