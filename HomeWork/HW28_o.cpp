/*
	!! ���� ������ ī��Ʈ ���α׷�(getch()�Լ� �̿�)

	���� ������ Ű����� ���� �Է� �޾� ���� ���ڸ� �������� ī��Ʈ�Ͽ� ����Ͻÿ�.
	�Է� ���� ���� : ����(new line)���� EOF �Է� �� ���� ��

	@2017.01.08 pm1:49
*/

#if 0
#include <stdio.h>
#include <conio.h>

int main()
{
	char input;
	int textEnglish = 0, textNumber = 0, textBlank = 0, textRest = 0;

	while ((input = getchar()) != EOF)
	{
		if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
			textEnglish++;
		else if ((input >= 48 && input <= 57))
			textNumber++;
		else if (input == 9 || input == 10 || input == 32)
			textBlank++;
		else
			textRest++;	
	}

	printf("* ������ ��ҹ��� ���� : %d\n", textEnglish);
	printf("* ���ڹ��� ���� : %d\n", textNumber);
	printf("* ���鹮��(space, tab, enter) ���� : %d\n", textBlank);
	printf("* �� �� ��Ÿ���� ���� : %d\n", textRest);
	
}
#endif