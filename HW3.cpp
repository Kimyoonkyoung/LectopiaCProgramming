#include <stdio.h>

int main()
{
	int value = 54321;
	int time = value;

	int hour;
	int minute;
	int second;

	hour = time / 3600;
	time = time - (hour * 3600);

	minute = time / 60;
	time = time - (minute * 60);

	second = time;

	printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.", value, hour, minute, second);
}