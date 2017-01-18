/*
	!!���� �迭 ����� (���� �Ҵ�)

	2���� char ������ �迭 (char *p[5])�� �����Ͽ� ���ڿ��� 5�� �Է� �޾� ������ ���� 
	�����迭�� ����� ���ڿ��� �����ϰ�, ������������ ��Ʈ�Ͽ� ��� ����.

	@2017.01.18 pm10:36	
*/
#if 0
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

char* myAlloc(char*, int);
void dataOutput(char **ip);
void myDelete(char **);
void sort(char**);

int main()
{
	char temp[1000];
	char *pa[5];
	int i, len;

	//p = (char**)malloc(sizeof(char*) * 5);
	//assert(p != NULL);

	for (i = 0; i < 5; i++)
	{
		printf("# ���ڿ� %d : ", i + 1);
		scanf("%s", temp);
		len = strlen(temp);

		pa[i] = myAlloc(temp, len);
	}

	sort(pa);
	dataOutput(pa);

	myDelete(pa);
}

void sort(char**str)
{
	char *swaping;

	int i, j;

	for (i = 0; i < 5 - 1; i++)
	{
		for (j = (i + 1); j < 5; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				//swaping = dataArray[i];
				//strcpy(swaping, str[i]);
				//strcpy(str[i], str[j]);
				//strcpy(str[j], swaping);
				swaping = str[i];
				str[i] = str[j];
				str[j] = swaping;
			}
		}
	}
}

char* myAlloc(char *temp, int len)
{
	int i, j;
	char *p;

	p = (char *)malloc(sizeof(char) * len + 1);
	assert(p != NULL);
	
	for (i = 0; i < len; i++)
		p[i] = temp[i];

	p[len] = '\0';

	return p;
}

void myDelete(char **ip)
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		free(ip[i]);
	}
}

void dataOutput(char **ip)
{
	int i;

	for (i = 0; i < 5; i++)
		printf("%d. %s\n", i + 1, ip[i]);
}
#endif // 1