/*
	!!���ڿ� ù ���ڿ� ������ ���� ����ϱ�

	�ټ� ���� ���ڿ��� �Է� �޾� char 5�� 20���� 2���� �迭(�迭�� : srt)�� ������� ������ ��,
	���ĺ� �������(a~z������) sort �Ͽ� ���ڿ� ��ü, ù ����, ������ ���ڸ� �������.

	@2017.01.12 pm07:37
*/
#if 0
#include <stdio.h>
#include <string.h>

void inputString(char(*)[20]);
void sort(char(*)[20]);
void outputString(char(*)[20]);

int main()
{
	char str[5][20];

	inputString(str);
	sort(str);
	outputString(str);
}

void outputString(char(*str)[20])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][strlen(str[i]) - 1]);
	}
}

void sort(char(*str)[20])
{
	char swaping[20];

	int i, j;

	for (i = 0; i < 5 - 1; i++)
	{
		for (j = (i + 1); j < 5; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				//swaping = dataArray[i];
				strcpy(swaping, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], swaping);
			}
		}
	}
}

void inputString(char(*str)[20])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("# %d�� ���ڿ��� �Է��Ͻÿ� : ", i);
		scanf("%s", str[i]);
	}
}
#endif