/*
	!!������� ����� ���� ���α׷�

	-�� �޴� = i-�Ա�, o-���, q-����(�� �޴� �̿��� ���� �Է½� ���Է� �䱸)
	-���� �ܾ� 0��
	-�ܾ׺��� ����� ������ "�ܾ��� �����մϴ�." -> �ָ޴���
	-����ݾ� �Է� �� ���� �� �Է½� "�߸� �Է��ϼ̽��ϴ�." ��� �� �ݾ� ���Է� �䱸
	-����ݾ� �Է½� ���� �Է½� "�߸� �Է��ϼ̽��ϴ�." ��� �� �ݾ� ���Է� �䱸

	1.menu() : �޴� ��� �� ����ڰ� ������ �޴� ���ڸ� ���� �ϴ� �Լ� �޴� ����(i, o, q)�� ���� �Է� �� ���Է� �䱸
	2.inputInt(string) : �������ڷ� ���� ���ڿ��� ����ϰ�, ����(��,���)�� �Է� �޾� ���� �ϴ� �Լ�(���� �Է� �� ���Է� �䱸)
	3.deposit() : �Ա�ó�� �Լ�
	4.withdraw() : ���ó�� �Լ�

	@2017.01.07 pm07:35
*/

// inputInt()���� ���� �Է½� ���� ���°� ����
#if 0
#include <stdio.h>

char menu();
int inputInt(char*);
void deposit(int*, int*);
void withdraw(int*, int*);
void myflush();

int main()
{
	int balanceMoney = 0, inputMoney;
	char inputMenu;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balanceMoney);

	while ((inputMenu = menu()) != 'q')
	{
		switch (inputMenu)
		{
		case 'i':
			inputMoney = inputInt("# �Աݾ��� �Է��ϼ��� : ");
			deposit(&balanceMoney, &inputMoney);
			break;
		case 'o':
			inputMoney = inputInt("# ��ݾ��� �Է��ϼ��� : ");
			withdraw(&balanceMoney, &inputMoney);
			break;
		}
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balanceMoney);
	}
}

void withdraw(int *balanceMoney, int *withdrowMoney)
{
	*balanceMoney -= *withdrowMoney;
}

void deposit(int *balanceMoney, int *depositMoney)
{
	*balanceMoney += *depositMoney;
}

int inputInt(char *outMessage)
{
	int inputMoney;

	printf("%s", outMessage);

	while (1)
	{
		scanf("%d", &inputMoney);

		if (inputMoney > 0)
			break;

		printf("*1 �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");

		
	}

	myflush();
	return inputMoney;
}

char menu()
{
	char inputMenu	;

	while (1)
	{
		printf("# �޴��� �Է��Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf("%c", &inputMenu);

		if (inputMenu == 'i' | inputMenu == 'o' | inputMenu == 'q')
			break;
		else
			printf("*�߸� �Է� �߽��ϴ�.\n\n");

		getchar();
	}

	return inputMenu;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif