#include <stdio.h>

int inputLength();
int hallEscapeDate(int);
void outputDate(int, int);

int main()
{
	int length, date;
	length = inputLength();

	date = hallEscapeDate(length);

	outputDate(length, date);
}

void outputDate(int length ,int date)
{
	double lengthD = length * 0.01;

	printf("%.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.", lengthD, date);
}

int hallEscapeDate(int length)
{
	int i, date = 0;
	

	while (1)
	{
		if (length == 0)
			break;

		for (i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				length -= 50;

				if (length <= 0)
				{
					date += 1;
					break;
				}
			}
			else
			{
				length += 20;

				if (length > 0)
					date += 1;
			}
		}
		if (length <= 0)
			break;
	}

	return date;
}

int inputLength()
{
	int input;

	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &input);

	return input;
}