#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 

/*--------------------------------------------------------------------------------------
  �Լ����ױ�� : initQueue() - ť �ʱ�ȭ �Լ�
  �������� : qPtr - ť ����ü�� �ּ�
             size - ť�� ũ��
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initQueue(Queue * qPtr, int size) 
{ 
	qPtr->qSize = size; 
	qPtr->front = 0; 
	qPtr->rear = 0; 
	qPtr->queue = (DataType *)calloc(qPtr->qSize, sizeof(DataType)); 
} 
/*--------------------------------------------------------------------------------------
  �Լ����ױ�� : enqueue() - ť�� ������ �ϳ��� ������
  �������� : qPtr - ť ����ü�� �ּ�
             inData - ť�� ������ ������
  ���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qPtr, DataType inData) 
{ 
	if (isQueueFull(qPtr) == FALSE)
	{
		qPtr->queue[qPtr->rear] = inData;
		qPtr->rear = ++(qPtr->rear) % qPtr->qSize;
		return TRUE;
	}

	return FALSE;
} 
/*--------------------------------------------------------------------------------------
  �Լ��� �� ��� : dequeue() - ť���� ������ �ϳ��� ����
  �������� : qPtr - ť ����ü�� �ּ�
             getData - ���� �����͸� ������ �������� �ּ�
  ���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qPtr, DataType * getData) 
{ 
	int i;

	if (isQueueEmpty(qPtr) == FALSE)
	{
		*getData = qPtr->queue[qPtr->front];
		qPtr->front = (++qPtr->front) % qPtr->qSize;

		return TRUE;
	}
	else
		return FALSE;
} 
/*--------------------------------------------------------------------------------------
  �Լ����ױ�� : printQueue() - ť ���� ��� �����͸� ��� ��
  �������� : qPtr - ť ����ü�� �ּ�
             print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr, void (*print)(DataType *) ) 
{ 
	int i;

	for(i = qPtr->front; i != qPtr->rear; i = (++i % qPtr->qSize))
		print(&qPtr->queue[i]);

	printf("\n");
} 
/*--------------------------------------------------------------------------------------
  �Լ����ױ�� : destroyQueue() - ť �Ҹ� �Լ�
  �������� : qPtr - ť ����ü�� �ּ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qPtr) 
{ 
	free(qPtr->queue);

	qPtr->queue = NULL;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->qSize = 0;
} 
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: isQueueEmpty() - ť�� ����ִ°� �˻�
  ��������: qPtr - ť ����ü�� �ּ�
  ���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qPtr)
{
	if (qPtr->front == qPtr->rear)
		return TRUE;
	else
		return FALSE;
}

int isQueueFull(const Queue *qPtr)
{
	if (qPtr->front == ((qPtr->rear + 1) % qPtr->qSize))
		return TRUE;
	else
		return FALSE;
}