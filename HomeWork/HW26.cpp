#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int input();
int output(int, int);
int random(int);

int main()
{
	int num, player, ret;
	int play1 = 0, play3 = 0;

	while (1)
	{
		srand((unsigned int)time(NULL));
		num = random(3) + 1;

		player = input();

		ret = output(player, num);

		if (ret == 1)
			play1++;
		else if (ret == 3)
			play3++;
		else
			break;
	}

	printf("���� ��� : %d �� %d ��", play1, play3);

}

int output(int input, int num)
{
	if (input == 1)
	{
		if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return 3;
		}
		else if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			return 1;
		}
		else if (num == 3)
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			return 2;
		}
	}
	else if (input == 2)
	{
		if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return 2;
		}
		else if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return 3;
		}
		else if (num == 3)
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
			return 1;
		}
	}
	else if (input == 3)
	{
		if (num == 1)
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			return 1;
		}
		else if (num == 2)
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return 2;
		}
		else if (num == 3)
		{
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			return 3;
		}
	}
}

int input()
{
	int input, ret;
	
	while (1)
	{
		printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
		ret = scanf("%d", &input);
		
		if (ret != 1)
		{
			printf("������ �Է� �ϼ���!!\n");
			getchar();
		}
		else if (input > 0 && input < 4)
			break;
		else
			printf("1 - 3 ������ ���ڸ� �Է� �ϼ���!!\n");
	}

	return input;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}