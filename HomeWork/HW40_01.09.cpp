/*
	!!������ �ݾ����� ���Ǳ����ϱ�

	�Է� ���� ���� �ݾ����� ���� ���ۿ��� ũ����(500��), �����(700��), �ݶ�(400��)�� ����Ѵ�.
	�ܵ��� �ϳ��� ������ �ʰ� �� ������ ������ �����Ѵٸ� ���� ��� ��� �ϴ°�?
	��, ��� ǰ���� �� �� �̻��� �� �����ϴ� ������ �Ѵ�.
	(�ݺ����� �� �ݾ� �Է¶��� ���� �Է� �� ����.)

	@2017.01.09 pm05:05
*/
#if 0
#include <stdio.h>

int main()
{
	int haveMoney, costBread, costShrimp, costCola;
	int i, j, k;

	costBread = 500;
	costShrimp = 700;
	costCola = 400;

	printf("���� ����� ���� �ݾ� �Է� : ");
	scanf("%d", &haveMoney);

	while (getchar() == '\n')
	{
		for (i = 1; 1; i++)
		{
			if ((costBread * i) >= haveMoney)
				break;

			for(j = 1; 1; j++)
			{
				if (((costBread * i) + (costShrimp * j)) >= haveMoney)
					break;

				for (k = 1; 1; k++)
				{
					if (((costBread * i) + (costShrimp * j) + (costCola * k)) > haveMoney)
						break;

					if(((costBread * i) + (costShrimp * j) + (costCola * k)) == haveMoney)
						printf("ũ����(%d ��), �����(%d ��), �ݶ�(%d ��)\n", i, j, k);
				}
			}
		}
		printf("��� �����Ͻðڽ��ϱ�? \n\n");

		printf("���� ����� ���� �ݾ� �Է� : ");
		scanf("%d", &haveMoney);
	}
}
#endif