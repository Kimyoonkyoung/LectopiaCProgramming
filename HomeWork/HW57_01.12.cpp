/*
	!!ȸ��(Palindrome) �˻� ���α׷�

	ȸ���� "level", "bob"�� ���� ������ ������ �ڷ� ������ �Ȱ��� �ܾ���� ���Ѵ�.
	���ڿ��� ȸ������ �ƴ����� �˻��ϴ� �Լ��� �ۼ��Ͽ� ȸ�� �˻� ���α׷��� �ۼ�����.
	�ݺ� �����ϰ� "end" �Է� �� ����

	@2017.01.12 pm06:36
*/
#if 0
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inputString(char*);
int testString(char*, int);
void outResult(char*, int);

int main()
{
	char inputS[100], sample[100];
	int strLength, ret;

	while (1)
	{
		inputString(inputS);

		if (strcmp(inputS, "end") == 0)
			break;

		strLength = strlen(inputS);
		strcpy(sample, inputS);

		ret = testString(inputS, strLength);

		outResult(inputS, ret);
	}
}

void outResult(char *inputS, int ret)
{
	if (ret == 1)
		printf("\"%s\" : ȸ���Դϴ�!\n\n", inputS);
	else
		printf("\"%s\" : ȸ���� �ƴմϴ�!\n\n", inputS);
}

int testString(char *inputS, int strLength)
{
	int i;

	for (i = 0; i < strLength / 2; i++)
	{
		if (tolower(inputS[i]) != tolower(inputS[(strLength - i) - 1]))
			return 0;
	}

	return 1;
}

void inputString(char *inputS)
{
	printf("# �ܾ� �Է� : ");
	scanf("%s", inputS);
}
#endif