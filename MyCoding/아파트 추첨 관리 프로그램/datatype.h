#pragma once

typedef  struct _information DataType;     // ��峻�� ������ ������ ���� ������ 

struct _information
{
	char name[20];
	char phone[20];
	int since;
};

int exchangeInt(char *, int); // ���ڿ��� ���� ������� ������ ����
int tenCalcu(int);  // 10�� n��
void printWinner(DataType *); // Queue Data ���
int random(int ); // ��÷�� ����