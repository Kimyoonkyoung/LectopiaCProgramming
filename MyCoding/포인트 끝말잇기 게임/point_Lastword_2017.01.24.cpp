#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "doublelinkedlist.h"

void dataFileLoad(LinkedList *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
void wInput(LinkedList *, LinkedList *lp, int*);  // �ܾ� �Է� ó�� �Լ�
void mSearch(LinkedList *lp, DataType *word);      // ���ϰ˻��޴� ó�� �Լ�
int lastWordCheck(LinkedList *word, DataType *inData, int*);
void firstInput(LinkedList *word, DataType *first);

int main()
{
	LinkedList list;  //����Ʈ���� ����ü ����
	LinkedList word;
	DataType first;
	int round = 1;

	create(&list);      // ����ִ� ����Ʈ ���� �� �ʱ�ȭ
	dataFileLoad(&list); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
	sortList(&list, compareWord);

	create(&word);
	strcpy(first.word, "pointer");
	firstInput(&word, &first);
	
	while (1)
	{
		if (list.head->next == list.tail)
			break;

		printf("* ����Ʈ �ܾ� : ");
		display(&list, printWord);
		printf("\n");
	
		printf("* ����� �Է� �ܾ� : ");
		display(&word, printWord);

		wInput(&list, &word, &round);

		round++;
	}

	printf("\n** ����Ʈ �ܾ ��� ������ϴ�. ������ �����մϴ�.\n");
	
	destroy(&list);
	destroy(&word);
}

void firstInput(LinkedList *word, DataType *first)
{
	makeNode(first, word->tail->prev, word->tail);
}
/*----------------------------------------------------------------------------------
�Լ��� : mInput()
----------------------------------------------------------------------------------*/
void wInput(LinkedList *list, LinkedList *word, int *round)
{
	DataType inData;
	int ret = 0;

	while (1)
	{
		printf("\n# �����ձ� �ܾ� �Է�(%dȸ��) : ", *round);
		scanf("%s", inData.word);

		printf("\n");

		ret = lastWordCheck(word, &inData, round);

		if (ret == 1)
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			(*round)--;
		}
		else
		{
			word->cur = appendFromTail(word, &inData);
			mSearch(list, &inData);
		}

		break;
	}
}

int lastWordCheck(LinkedList *word, DataType *inData, int *round)
{
	Node *t;
	int length1, length2;

	t = word->tail;

	length1 = strlen(t->prev->data.word);
	length2 = strlen(inData->word);

	if (t->prev->data.word[length1 - 1] == inData->word[0])
		return 0;
	else
	{
		return 1;
		(*round)--;
	}
}
/*----------------------------------------------------------------------------------
�Լ��� : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp, DataType * word)
{
	Node *resp;

	resp = searchUnique(lp, word, compareWord);
	if (resp != NULL) //�����͸� ã������
	{
		//->cur = (Node*)malloc(sizeof(Node));
		//assert(word->cur != NULL);
		/*
		word->cur->prev = word->tail->prev;
		word->cur->next = word->tail;
		word->tail->prev->next = word->cur;
		word->tail->prev = word->cur;
		word->cur->data = resp->data;
		*/
		resp->next->prev = resp->prev;
		resp->prev->next = resp->next;
		
		free(resp);
	}

	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	fp = fopen("c:\\data\\pointWord.txt", "rt");
	assert(fp != NULL);
	DataType inData;
	char name[20];   // ���� ����

	while (fscanf(fp, "%s", name) != EOF)
	{
		strcpy(inData.word, name);
		appendFromTail(lp, &inData);
	}
	fclose(fp);
}
//-------------------------------------
//   word ����ü ���� �Լ�
//-------------------------------------
int compareWord(DataType *p1, DataType *p2) // Person ����ü�� name����� ���ϴ� �Լ�
{
	return (strcmp(p1->word, p2->word));  // strcmp()�Լ��� ���ϰ��� �ٷ� ����
}

void printWord(DataType *p)  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
{
	printf(" %s /", p->word);
}