#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	char name[1000], sex;
	double height;

	printf("# ���� �Է� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &height);

	getchar();

	printf("# �����Է�(M/F) : ");
	scanf("%c", &sex);

	if (sex == 'M' || sex == 'm')
		printf("%s���� Ű�� %.2lf�̰� �����Դϴ�.", name, height);
	else
		printf("%s���� Ű�� %.2lf�̰� �����Դϴ�.", name, height);
}