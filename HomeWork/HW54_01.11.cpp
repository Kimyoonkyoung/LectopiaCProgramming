/*
	!!���� �˻� ���α׷�(���� �˻�)

	HW53�� ����� Ȯ���Ͽ� ���ڿ� ���� ã�� ���ڰ� ���� ���� ��� ��� ��ġ�� ����ϴ� ���α׷� �ۼ�

	@2017.01.12 pm02:58
*/
#if 0
#include <stdio.h>
#include <string.h>

int inputChar(char*, char*);
int strcheck(char*, char);

int main()
{
	char word[100], inputWord, ret;
	int strLength, i, count;

	while (1)
	{
		count = 0;

		ret = inputChar(word, &inputWord);

		if (ret == 0)
			break;

		printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� ", word, inputWord);

		strLength = strlen(word);

		for (i = 0; i < strLength; i++)
		{
			ret = strcheck(&word[i], inputWord);
			if (ret == 1)
			{
				printf("%d�� ��ġ�� ", i);
				count++;
			}
		}

		if (count > 0)
		{
			printf("�����մϴ�.\n\n");
			
		}
		else
			printf("�������� �ʽ��ϴ�.\n\n");
	}

#if 0
	while (1)
	{
		ret = inputChar(word, &inputWord);

		if (ret == 0)
			break;

		ret = strcheck(word, inputWord);

		if (ret >= 0)
			printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d�� ��ġ�� �����մϴ�.\n\n", word, inputWord, ret);
		else
			printf("\"%s\" ���ڿ� �ȿ� '%c' �������� �ʽ��ϴ�.\n\n", word, inputWord);
	}
#endif
}

int strcheck(char *word, char inputWord)
{
	int i;

	if (*word == inputWord)
		return 1;
	
	return -1;
#if 0
	int i, strLength;

	strLength = strlen(word);

	for (i = 0; i < strLength; i++)
	{
		if (word[i] == inputWord)
			return i;
	}
	return -1;
#endif
}

int inputChar(char *word, char *inputWord)
{
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", word);

	if (strcmp(word, "end") == 0)
		return 0;

	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", inputWord);

	return 1;
}
#endif