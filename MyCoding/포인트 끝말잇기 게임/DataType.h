#pragma once
typedef struct _lastword
{
	char word[20];
}Lastword;

typedef  Lastword DataType;     // ��峻�� ������ ������ ���� ������ 

//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------
int compareWord(DataType *p1, DataType *p2);  // Person ����ü�� name����� ���ϴ� �Լ�
void printWord(DataType *p);  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
