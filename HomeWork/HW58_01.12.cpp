/*
	!!���ڿ� ���� ������ �� ���ϱ�

	���ڿ��� �Է� �޾� ���ڿ� ���� ���ڵ��� �� ���� ����Ѵ�. (���ڿ��� ���̴� 99���Ϸ� ���� ��)
	���� �� �Է� ���� ���ڿ��� "ab123@5f#4_31"�̸� 123+5+4+31�� ����Ͽ� 163�� ��� ���ش�.
	��, ��� �� ���� �ν��Ѵٴ� �����Ͽ��� ���α׷��� �غ���
	�ݺ� �����ϰ� "end" �Է� �� ����

	@2017.01.12 pm08:38
*/
#if 01
#include <stdio.h>
#include <string.h>
#include <math.h>

void inputString(char*);
int sNumCalculator(char*);
void outputResult(char*, int);
int tenCalcu(int);

int main()
{
	char inputS[100];
	int ret;

	while (1)
	{
		inputString(inputS);

		if (strcmp(inputS, "end") == 0)
			break;

		ret = sNumCalculator(inputS);

		outputResult(inputS, ret);
	}
}

void outputResult(char *inputS, int ret)
{
	printf("\"%s\" ���� �� ���ڴ� [%d]�Դϴ�.\n\n", inputS, ret);
}

int sNumCalculator(char *inputS)
{
	int sum = 0, i, j, count;

	for (i = 0; i < strlen(inputS); i++)
	{
		if (inputS[i] >= '0' && inputS[i] <= '9')
		{
			count = 0;
			for (j = 1; j < strlen(inputS) - i; j++)
			{
				if (inputS[i + j] >= '0' && inputS[i + j] <= '9')
				{
					count++;
				}
				else
					break;
			}
			sum += (inputS[i] - '0') * pow(10, count);
		}
	}
	return sum;
}

void inputString(char *inputS)
{
	printf("# ������ �Է��Ͻÿ� : ");
	scanf("%s", inputS);
}

int tenCalcu(int count)
{
	int i, result = 1;

	if (count > 0)
	{
		for (i = 0; i < count; i++)
			result *= 10;

		return result;
	}
	else
		return 1;
}
#endif