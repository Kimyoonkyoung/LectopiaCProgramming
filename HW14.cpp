#pragma waning(disable : 4996);
#include <stdio.h>
#include <string.h>

int main()
{
	char input[1000];
	int inLength, outLength, i;
	
	printf("*���ڿ� �Է� : ");
	scanf("%s", input);

	inLength = strlen(input);
	outLength = inLength / 2;

	printf("[%*.*s...]", inLength, outLength, input);
}