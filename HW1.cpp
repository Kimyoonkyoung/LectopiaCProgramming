#if 0
#include <stdio.h>

void printAge(int outA);
void printHeight(double outH);

int main()
{
	char name[20] = "������";
	int age = 25;
	double height = 173.2;

	printf("���� : %s \n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int outA)
{
	printf("���� : %d \n", outA);
}

void printHeight(double outH)
{
	printf("Ű : %f \n", outH);
}
#endif