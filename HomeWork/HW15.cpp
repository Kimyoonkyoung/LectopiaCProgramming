#if 0
#include <stdio.h>

double input();
double bmiCalculator(double, double);
void output(double);

int main()
{
	double height, bmiV;
	int weight;

	printf("�����Ը� �Է��ϼ���(kg) : ");
	weight = input();

	printf("Ű�� �Է��ϼ���(m) : ");
	height = input();

	bmiV = bmiCalculator(weight, height);

	output(bmiV);
}

double input()
{
	double input;

	scanf("%lf", &input);

	return input;
}

double bmiCalculator(double a, double b)
{
	double bm;

	bm = a / (b * b);

	return bm;
}

void output(double out)
{
	if (out < 18.5)
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�.", out);
	else if (out < 25.0)
		printf("����� BMI�� %.1lf���� ����ü�� �Դϴ�.", out);
	else if (out < 30.0)
		printf("����� BMI�� %.1lf���� ��ü�� �Դϴ�.", out);
	else if (out < 40.0)
		printf("����� BMI�� %.1lf���� �� �Դϴ�.", out);
	else
		printf("����� BMI�� %.1;f���� ���� �Դϴ�.", out);
}
#endif
