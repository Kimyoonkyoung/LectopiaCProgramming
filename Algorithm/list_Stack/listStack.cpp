#include "liststack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : initStack() -  ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ�
  �������� : sPtr - ���ð��� ����ü�� �ּ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr)
{
	sPtr->head = (Snode *)calloc(1, sizeof(Snode)); //��� ��� ����
	assert(sPtr->head!=NULL);
	sPtr->tail = (Snode *)calloc(1, sizeof(Snode)); //���� ��� ����
	assert(sPtr->tail!=NULL);
	/*����尡 ���ϳ�带, ���ϳ�尡 ���ϳ�带 ����Ű�� ��*/
	sPtr->head->next=sPtr->tail;
	sPtr->tail->next=sPtr->tail;
	sPtr->cur = NULL;
	return ;
}
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : push() - ���ÿ� ������ �ϳ��� ������
  �������� : sPtr - ���ñ���ü�� �ּ�
           inData - ���ÿ� ������ ������
  ���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, DataType inData) /* stack�� ������ �����ϱ� */
{
	sPtr->cur = (Snode*)calloc(sizeof(Snode), 1);
	if (sPtr->cur == NULL)
		return FALSE;

	sPtr->cur->next = sPtr->head->next;
	sPtr->head->next = sPtr->cur;
	
	sPtr->cur->data = inData;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ��� : pop() - ���ÿ��� ������ �ϳ��� ����
  �������� : sPtr - ���ñ���ü�� �ּ�
             popData - ���� �����͸� ������ �������� �ּ�
  ���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, DataType *popData)
{
	Snode *fre;

	sPtr->cur = sPtr->head->next;

	if (sPtr->cur != sPtr->tail)
	{
		*popData = sPtr->cur->data;
		fre = sPtr->cur;
		sPtr->head->next = sPtr->cur->next;

		free(fre);
		return TRUE;
	}
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : printStack() - ������ ��� �����͸� ��� ��
  �������� : sPtr - ���ñ���ü�� �ּ�
             print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printStack(Stack *sPtr, void(*print)(DataType *))
{
	sPtr->cur = sPtr->head->next;

	while (sPtr->cur != sPtr->tail)
	{
		print(&(sPtr->cur->data));
		sPtr->cur = sPtr->cur->next;
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : destroyStack() - ���� �Ҹ� �Լ�
  �������� : sPtr - ���ñ���ü�� �ּ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr)
{
	Snode *np, *fre;

	np = sPtr->head->next;

	while (np != sPtr->tail)
	{
		fre = np;
		sPtr->head->next = np->next;
		
		np = np->next;
		free(fre);
	}

	free(sPtr->head);
	free(sPtr->tail);

	sPtr->head = NULL;
	sPtr->tail = NULL;
	sPtr->cur = NULL;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: getStackTop() - ���ó��� �ֻ���� ���� �о���� �Լ�(pop������ ����)
  ��������: sPtr - ���ñ���ü�� �ּ�
            getData - ���� �����͸� ������ �������� �ּ�
  ���ϰ�: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int getStackTop(Stack *sPtr, DataType *getData)
{
	if(isStackEmpty(sPtr))  // stack�� ��������� pop����
	{
		return FALSE;
	}
	*getData = sPtr->head->next->data;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: isStackEmpty() - ������ ����ִ°� �˻�
  ��������: sPtr - ���ñ���ü�� �ּ�
  ���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->head->next == sPtr->tail)
		return TRUE;
	else
		return FALSE;
}
