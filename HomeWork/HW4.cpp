#include <stdio.h>

int main()
{
	double value = 365.2422;      // �־��� ��
	double oday = value;          // �Ͻú��� ��� �뵵
	int day, hour, minute;        // �Ͻú� ���� ����
	double second, sday;          // �� ���� ���� , ���� �� ���� ����

	sday = oday * 86400;          // ���� �ʷ� ��ȯ

	day = sday / 86400;           // �� ��� 
	sday = sday - (day * 86400);

	hour = sday / 3600;           // �� ���
	sday = sday - (hour * 3600);

	minute = sday / 60;           // �� ���
	sday = sday - (minute * 60);

	second = sday;                // ���� �� ����

	printf("%.4lf���� %d�� %d�ð� %d�� %.2lf�� �Դϴ�.", value, day, hour, minute, second);
}