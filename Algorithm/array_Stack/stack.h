#pragma once
#pragma warning(disable:4996)
#include "datatype.h"

typedef struct _stack{ // stack���� ����ü
	DataType *stack;       // stack���� ���Ǵ� �迭�� ����Ű�� ������ ����
	int sSize;             // ������ ũ��
	int top;               // ������ ��,�ⱸ ��ġ���� ����
}Stack;

void initStack(Stack *, int);     //���� �޸� �Ҵ� �� �ʱ�ȭ �Լ� top�� ��ġ�� 0�� �ʱ�ȭ
//void clearStack(Stack *);         // ���� ���� �Լ�
int push(Stack *, DataType);           // ���ÿ� ������ �����ϴ� �Լ�#
int pop(Stack *, DataType *);          // ���ÿ��� �����͸� ������ �Լ�#
void printStack(const Stack *sPtr, void(*print)(DataType *p));    // ���� ���� ��� �����͸� ����ϴ� �Լ�#
void destroyStack(Stack *);       // ���� �޸� ���� �Լ�#
int isStackFull(Stack *sPtr);     // ������ �� ���ִ��� �˻�#push����
int isStackEmpty(Stack *sPtr);    // ������ ����ִ��� �˻�#pop����