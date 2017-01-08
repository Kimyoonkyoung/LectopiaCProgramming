/*
	!!ȯǳ�� ���� ���α׷�

	�� 8���� ȯǳ�� ����(ON, OFF)���� �ý��� ����
	1. Ư�� Ȯǳ�� ���� ON�ϴ� ���
	2. Ư�� ȯǳ�� ���� OFF�ϴ� ���
	3. ��ü ȯǳ�� ���¸� �����ϴ� ���
	4. ó�� ���ۻ��´� ��� ȯǳ���� ���� ����

	@2017.01.08  am10:29
*/

#if 0
#include <stdio.h>

int menu();
char openFan(unsigned char);
char offFan(unsigned char);
char reverseFan(unsigned char);
void displayFan(unsigned char);

void myflush();
int inputInt();
void selectM(int, unsigned char*);
void outputBinary(unsigned char);

int main()
{
	unsigned char numberFan = 0x00, select;

	while (1)
	{
		select = menu();
		if (select == 4)
			break;

		selectM(select, &numberFan);
		displayFan(numberFan);
	}
}

int menu()
{
	int ret;

	while (1)
	{
		printf("\n1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		ret = inputInt();
		printf("-------------------------------------------------------------\n");

		if (ret >= 1 && ret <= 4)
			return ret;

		myflush();
		printf("\n");
	}
}

void displayFan(unsigned char num)
{
	printf("8��FAN  7��FAN  6��FAN  5��FAN  4��FAN  3��FAN  2��FAN  1��FAN\n");
	outputBinary(num);
	printf("\n-------------------------------------------------------------\n\n");
}

char reverseFan(unsigned char num)
{
	printf("                Fan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("-------------------------------------------------------------\n");
	printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");
	printf("-------------------------------------------------------------\n");

	num = ~num;

	return num;
}

char offFan(unsigned char num)
{
	unsigned char calculator = 0x7f;
	int fanNumber;

	printf("                Fan �ݱ� �۾� ���� ȭ��\n");
	printf("-------------------------------------------------------------\n");
	while (1)
	{
		printf("* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		fanNumber = inputInt();

		if (fanNumber >= 1 && fanNumber <= 8)
			break;

		myflush();
	}
	printf("-------------------------------------------------------------\n");

	calculator = (calculator >> (8 - fanNumber) | (calculator << (fanNumber)));
	//calculator = calculator >> (8 - fanNumber);

	num = num & calculator;

	return num;
}

char openFan(unsigned char num)
{
	unsigned char calculator = 0x80;
	int fanNumber;

	printf("                Fan ���� �۾� ���� ȭ��\n");
	printf("-------------------------------------------------------------\n");
	while (1)
	{
		printf("* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		fanNumber = inputInt();

		if (fanNumber >= 1 && fanNumber <= 8)
			break;

		myflush();
	}
	printf("-------------------------------------------------------------\n");

	calculator = calculator >> (8 - fanNumber);

	num = num | calculator;

	return num;
}

int inputInt()
{
	int inputValue;


	scanf("%d", &inputValue);
	/*while (1)
	{
		scanf("%d", &inputValue);

		if (getchar() == '\n')
			break;

		myflush();
	}*/

	return inputValue;
}

void myflush()
{
	while (getchar() != '\n')
		;
}

void outputBinary(unsigned char num)
{
	unsigned char calculator = 0x80, result;
	int i;

	for (i = 0; i <= 7; i++)
	{
		result = (num & calculator) >> (7 - i);

		if (result == 1)
			printf("  ON\t");
		else
			printf("  OFF\t");

		calculator = calculator >> 1;
	}
}

void selectM(int number, unsigned char *numberFan)
{
	switch (number)
	{
	case 1:
		*numberFan = openFan(*numberFan);
		break;
	case 2:
		*numberFan = offFan(*numberFan);
		break;
	case 3:
		*numberFan = reverseFan(*numberFan);
		break;
	}
}
#endif