#include <stdio.h>

int inputTime();
int calculatorGlossPay(int);
int calculatorTexes(int);
void outputResult(int, int);

int main()
{
	int time, glossPay, taxes;

	time = inputTime();

	glossPay = calculatorGlossPay(time);

	taxes = calculatorTexes(glossPay);

	outputResult(glossPay, taxes);
}

int inputTime()
{
	int ret;

	printf("* 1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
	scanf("%d", &ret);

	return ret;
}

int calculatorGlossPay(int time)
{
	int pay;

	if (time > 40)
	{	
		pay = 40 * 3000;
		pay += (time - 40) * 3000 * 1.5;
	}
	else
		pay = time * 3000;

	return pay;
}

int calculatorTexes(int glossPay)
{
	int texes = 0;

	if (glossPay <= 100000)
		texes = glossPay * 0.15;
	else
	{
		texes = 100000 * 0.15;
		texes += (glossPay - 100000) * 0.25;
	}

	return texes;
}

void outputResult(int gloss, int tax)
{
	printf("# �Ѽ��� : %d��\n", gloss);
	printf("# ��  �� : %6d��\n", tax);
	printf("# �Ǽ��� : %d��\n", gloss - tax);
}