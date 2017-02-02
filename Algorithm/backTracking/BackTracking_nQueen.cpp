#if 01
#pragma warning(disable: 4996)
#include <stdio.h>
#define CHECK (1)
#define MAX_CNT 15
int columnChk[MAX_CNT+1];             // column üũ �迭 (0���� ��� ����)
int incDiagonalLineChk[MAX_CNT*2+1];  // ������ �����ϴ� �밢�� üũ �迭 (0���� ��� ����)
int decDiagonalLineChk[MAX_CNT*2+1];  // ������ �����ϴ� �밢�� üũ �迭 (0���� ��� ����)
int placementCnt;                     // ���� ���ݸ��ϰ� ��ġ ������ ����� �� ī��Ʈ ����
int n;                                // queen�� ��(���� ��,���� ��) ���庯��

void nQueen(int row);

int main()
{
	while(1)  // ���� ������ 1~MAX_CNT �� ������ �ƴϸ� ���Է�
	{
		printf("���� ������ �Է� �Ͻÿ� : ");
		scanf("%d", &n);
		if(n>0 && n<=MAX_CNT) 
			break;
	}
	placementCnt = 0;
	nQueen(1);
	printf("��ġ ������ ����� �� : %d\n\n", placementCnt);	
	return 0;
}
/*------------------------------------------------------------------
  �Լ��� �� ���: nQueen() - n���� queen�� ��ġ�ϱ� ���� ���ȣ�� �Լ�
  �������� : row - ü������ ���ȣ(0���� ��� ����)
  ���ϰ�: ����
------------------------------------------------------------------*/
void nQueen(int row)
{
	//���� § �ڵ�
#if 01
	int col;

	if (row == n + 1)
		placementCnt++;

	for (col = 1; col <= n; col++) {
		if ((columnChk[col] != CHECK) && (incDiagonalLineChk[row + col] != CHECK) && (decDiagonalLineChk[n + (row - col)] != CHECK)) {
			columnChk[col] = incDiagonalLineChk[row + col] = decDiagonalLineChk[n + (row - col)] = CHECK;

			nQueen(row + 1);

			incDiagonalLineChk[row + col] = decDiagonalLineChk[n + (row - col)] = columnChk[col] = 0;
		}
	}
#endif

#if 0
	int i;


	if (row>n) // �ప�� n�� �ʰ��ϸ� ���� ���� ���ݸ��ϰ� ��ġ�ϴ� �۾��� 1ȸ ���� ���̹Ƿ� 
	{
		placementCnt++; // ��ġ ī��Ʈ�� ������Ű��
		return; // backtrack
	}


	for (i = 1; i <= n; ++i)
	{
		if (!columnChk[i] && !incDiagonalLineChk[row + i] && !decDiagonalLineChk[n + (row - i)])
		{
			columnChk[i] = incDiagonalLineChk[row + i] = decDiagonalLineChk[n + (row - i)] = CHECK; // �� ��ġ
			nQueen(row + 1); // ���� ���� �����ϹǷ� ���� ���� �˻��ϱ� ���� ���ȣ�� ��
			columnChk[i] = incDiagonalLineChk[row + i] = decDiagonalLineChk[n + (row - i)] = 0; // backtrack �� üũ�ߴ� ���� ���� 
		}
	}
	return;
#endif
}
#endif
