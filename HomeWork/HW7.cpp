#include <stdio.h>

int main()
{
	double km, kmH, second;
	int hour, minute;

	printf("* �Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf_s("%lf", &km);
	printf("* �ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf_s("%lf", &kmH);

	hour = (int)(km / kmH);
	minute = (int)(((km / kmH) - hour) * 60);
	second = ((((km / kmH) - hour) * 60) - minute) * 60;
	
	printf("%.3lfkm = >%d�ð� %d�� %.3lf�� �ҿ��", km, hour, minute, second);
}