/*
	!!���� ���ϴ� ���α׷�

	��,��� ���α׷� �̿��� ��, ��, �� �Է��ϸ� ������ ����ϴ� ���α׷��� �ۼ� �Ͻÿ�.
	�ݺ� �����ϰ� ����� �Է� �� �ϳ��� ���ڰ� ������ ���� �Ͻÿ�.
	���� �����Ͱ� �ԷµǸ� ���Է��� �䱸�� ��(2013 13 7, 2011 2 29, 2016 -7 30 ...)

	@2017.01.12 pm05:24
*/
#if 0
#include <stdio.h>

int yearCheck(int);
int inputYMD(int*, int*, int*);
int checkYMD(int*, int*, int*, int*);
int changeYMD(int *, int*, int*, int*);
void outputDay(int*, int*, int*, int);

int main()
{
	int monthD[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;
	int ret, sumDay;

	while (1)
	{
		ret =inputYMD(&year, &month, &day);
		if (ret == -1)
			break;

		ret = checkYMD(&year, &month, &day, monthD);

		if (ret == 1)
		{
			sumDay = changeYMD(&year, &month, &day, monthD);

			outputDay(&year, &month, &day, sumDay);
		}
	}
}

void outputDay(int *year, int *month, int *day, int sumDay)
{
	int result;
	result = (sumDay % 7);

	switch (result)
	{
	case 0:
		printf("%d�� %d�� %d���� �Ͽ����Դϴ�.\n\n", *year, *month, *day);
		break;
	case 1:
		printf("%d�� %d�� %d���� �������Դϴ�.\n\n", *year, *month, *day);
		break;
	case 2:
		printf("%d�� %d�� %d���� ȭ�����Դϴ�.\n\n", *year, *month, *day);
		break;
	case 3:
		printf("%d�� %d�� %d���� �������Դϴ�.\n\n", *year, *month, *day);
		break;
	case 4:
		printf("%d�� %d�� %d���� ������Դϴ�.\n\n", *year, *month, *day);
		break;
	case 5:
		printf("%d�� %d�� %d���� �ݿ����Դϴ�.\n\n", *year, *month, *day);
		break;
	case 6:
		printf("%d�� %d�� %d���� ������Դϴ�.\n\n", *year, *month, *day);
		break;
	}
}

int changeYMD(int *year, int *month, int *day, int *monthD)
{
	int sumDay = 0, i;

	if (*year > 1900)
	{
		for (i = 1900; i < *year; i++)
		{
			if (yearCheck(i) == 1)
				sumDay += 366;
			else
				sumDay += 365;
		}
	}

	if (*month > 1)
	{
		for (i = 0; i < (*month - 1); i++)
		{

			if (yearCheck(*year) == 1)
			{
				if (i == 1)
					sumDay += 29;
				else
					sumDay += monthD[i];
			}
			else
				sumDay += monthD[i];
		}
	}

	for (i = 1; i <= *day; i++)
		sumDay++;

	return sumDay;
}

int checkYMD(int *year, int *month, int *day, int *monthD)
{
	if (yearCheck(*year) == 1)
		monthD[1] = 29;
	else
		monthD[1] = 28;

	if ((*month > 0 && *month < 13) && (*year >= 1900))
	{
		if ((*day >= 1) && (*day <= monthD[*month - 1]))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int inputYMD(int *year, int *month, int *day) 
{
	printf("* �� �� ���� �Է��Ͻÿ� : ");
	scanf("%d %d %d", year, month, day);

	if (getchar() != '\n')
	{
		return -1;
	}
}

int yearCheck(int year) //����(29) == 1, ��� == 0
{
	int result;

	if ((year % 4) != 0)
		return 0;
	else if ((year % 100) != 0)
		return 1;
	else if ((year % 400) != 0)
		return 0;
	else
		return 1;
}
#endif