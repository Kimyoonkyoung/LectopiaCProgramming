#include <stdio.h>
#include <string.h>
#pragma waning(disable : 4996);

int main()
{
	char nameFirst[1000], nameLast[1000];
	int getLengthF, getLengthL;

	printf("#���� �Է��Ͻÿ� : ");
	scanf("%s", nameFirst);
	printf("#�̸��� �Է��Ͻÿ� : ");
	scanf("%s", nameLast);

	getLengthF = strlen(nameFirst);
	getLengthL = strlen(nameLast);

	printf("%s %s\n", nameFirst, nameLast);
	printf("%*d %*d", getLengthF, getLengthF, getLengthL, getLengthL);
}

