/*
	!!���ڰ˻� ���α׷�(���� �˻�)

	���ڿ� �ϳ� ���� �ϳ��� �Է� �޾� ���ڿ��߿��� ���ڰ� ���ԵǾ� �ִ°��� �˻��Ͽ� ������
	��ġ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	��, ���ڿ� ���� ã�� ���ڰ� ���� ���� ��� ù ��° ��ġ�� ���� ��(���� �˻��� ����)
	�˻� �۾��� �ݺ��ϸ� �Է� ���ڿ��� "end"�Է� �� �����ϱ�

	@2017.01.12 am11:59
*/
#if 0
#include <stdio.h>
#include <string.h>

int inputChar(char*, char*);
int strcheck(char*, char);

int main()
{
	char word[100], inputWord, ret;

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
}

int strcheck(char *word, char inputWord)
{
	int i, strLength;

	strLength = strlen(word);

	for (i = 0; i < strLength; i++) 
	{
		if (word[i] == inputWord)
			return i;
	}
	return -1;
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