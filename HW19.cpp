#if 1
#include <stdio.h>

int input();
int yearCheck(int);
void outputYear(int, int);

int main()
{
	int year;

	printf("�⵵�� �Է��Ͻÿ� : ");
	year = input();

	outputYear(year, yearCheck(year));
}

int input()
{
	int ret;

	scanf("%d", &ret);

	return ret;
}

int yearCheck(int year)
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

void outputYear(int year, int result)
{
	if (result == 1)
		printf("%d���� ����(Leap year)�Դϴ�.", year);
	else
		printf("%d���� ���(Common year)�Դϴ�.", year);
}
#endif
