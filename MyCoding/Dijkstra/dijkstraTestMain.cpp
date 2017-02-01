#include<stdio.h>
#include<malloc.h>
#include "graph.h"
void displayTitle(char *message);
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent);
void printWeightArray(int *weightArray, int vNum, int vCnt);
void printParent(int *parent, int vCnt);
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum);

/*----------------------------------------------------------------------------------
�Լ��� : main() 
----------------------------------------------------------------------------------*/
int main()
{
	GraphMatrix g;
	int weightArray[MAX_VERTEX];  /* ����ġ�� ���������� �����ϴ� �迭 */
	int parent[MAX_VERTEX];      /* �θ� ���� ���� �迭*/
	int i;

	initGraph(&g, "c:\\data\\graphData2.txt");/* �׷��� �ʱ�ȭ */

	displayTitle("[���� �׷����� ���� ��� ���]");
	outputGraph(&g);   /* �׷��� ���� �� ����ġ ���� ���*/        
	NEWL; NEWL;

	/* ���ͽ�Ʈ�� �˰��� ���� */

	displayTitle("[����ġ ��ȭ ���� ���]");
	dijkstra(&g, 5, weightArray, parent);  /* 5���� �ش��ϴ� ������ �������� ���ͽ�Ʈ�� �˰��� ���� */

	displayTitle("[�������� �θ�, �ڽİ��� ���]");
	printParent(parent, g.vertexCnt);  /* parent �迭 ��� */

	/* ���� ����(F-5�� ����)�� ���� �׷������� ��� ����(A~K)������ ��� �� ����ġ ��� */
	displayTitle("[F(5�� ����)�������� �� ���������� path ����ϱ�]");
	for(i=0; i<g.vertexCnt; ++i)
		pathPrint(parent, weightArray, 5, i);

	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: displayTitle() - ���޵� �޽����� ��� �� 
��������:  message - ����� �޽���
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void displayTitle(char *message)
{
	printf("\n----------------------------------------\n");
	printf(" %s\n", message);
	printf("----------------------------------------\n");
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: dijkstra() - ���޵� �׷������� ���õ� �������� ���� ������ ���������� 
			�ּ� ����ġ�� ����ϰ� �θ��ڽ� ���踦 ������
��������:  g - �׷��� ���� ����ü�� �ּ�
			vNum - ���õ� ���� ��ȣ
			weightArray - ����ġ�� ������ �迭�� �����ּ�
			parent - �������� �θ��ڽİ��踦 ������ �迭�� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent)
{
	int check[100];
	int i, j, k;
	int standard, standardIndex, saveWeight, compare;
	//���� �ʱ�ȭ, �θ� ��� �ʱ�ȭ
	for (i = 0; i < g->vertexCnt; i++) {
		check[i] = 0;
		parent[i] = vNum;
	}
	parent[vNum] = -1;
	check[vNum] = 1;
	standardIndex = vNum;
	//����ġ �ʱ�ȭ
	for (i = 0; i < g->vertexCnt; i++) {
		weightArray[i] = g->graph[standardIndex][i];
	}
	printWeightArray(weightArray, standardIndex, g->vertexCnt);
	//����ġ ����
	for (j = 0; j < g->vertexCnt - 1; j++) {
		standard = 1000;
		//���� ���� ����ġ�� ���� ���� ��������
		for (i = 0; i < g->vertexCnt; i++) {
			if (weightArray[i] < standard && check[i] != 1) {
				standard = weightArray[i];
				standardIndex = i;
			}
		}
		check[standardIndex]++;
		//����ġ ����
		for (i = 0; i < g->vertexCnt; i++) {
			if (g->graph[standardIndex][i] != 1000) {
				if (i == vNum)
					continue;

				saveWeight = weightArray[standardIndex] + g->graph[standardIndex][i];
				if (saveWeight < weightArray[i]) {
					weightArray[i] = saveWeight;
					parent[i] = standardIndex;
				}
			}
		}
		printWeightArray(weightArray, standardIndex, g->vertexCnt);
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: printWeightArray() - weight�迭�� ��� ��
��������:  weightArray - ����ġ ���� �迭�� �����ּ�
           vNum - ���� ���� ��ȣ
           vCnt - ����� ������ ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printWeightArray(int *weightArray, int vNum, int vCnt)
{
	int i;
	printf("%3c : ", 'A'+vNum);
	for(i=0; i<vCnt; ++i)
		printf("%5d", weightArray[i]);

	NEWL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: printParent() - �θ�, �ڽ� ��带 ǥ���ϴ� �迭 ���
��������:  parent - �θ�, �ڽ� ��� ǥ�� �迭�� �����ּ�
			vCnt - ����� ������ ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printParent(int *parent, int vCnt)
{
	int i;
	printf("\n---------------------------------------------------------\n");
	printf("child :  ");
	for(i=0; i<vCnt; ++i)
		printf("%3c", i+'A');
	NEWL;
	printf("Parent : ");
	for(i=0; i<vCnt; ++i)
		if(parent[i]==-1) printf("  *");
		else printf("%3c", parent[i]+'A');
		printf("\n--------------------------------------------------------\n");
		NEWL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: pathPrint() - ���� ����->�� ���������� path �� ����ġ ���
��������:  parent - �θ�, �ڽİ��踦 ������ �迭�� �����ּ�
			weightArray - ����ġ ���� �迭�� �����ּ�
			startVNum - ���� ���� ��ȣ
			endVNum - ���� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum)
{
	int i, count = 0;
	char save[1000];

	printf("%c ", startVNum + 'A');

	if (endVNum != startVNum) {
		i = endVNum;
		do {
			save[count++] = i;
			i = parent[i];
		} while (i != startVNum);

		for (i = count - 1; i > -1; i--) {
			printf("->   %c", save[i] + 'A');
		}
	}
	printf("   (weight : %d)\n", weightArray[endVNum]);
}

/*======================================================================================================
[ ��� ��� ]
----------------------------------------
[���� �׷����� ���� ��� ���]
----------------------------------------
A  B  C  D  E  F  G  H  I  J  K
A  0  4  1  2  3 �� �� �� �� �� ��
B  4  0 �� �� ��  4 �� �� �� �� ��
C  1 ��  0  2 �� �� �� �� �� �� ��
D  2 ��  2  0 ��  4  4 �� �� �� ��
E  3 �� �� ��  0  4 �� �� �� �� ��
F ��  4 ��  4  4  0 �� �� ��  2  4
G �� �� ��  4 �� ��  0  3  3  4 ��
H �� �� �� �� �� ��  3  0  2 �� ��
I �� �� �� �� �� ��  3  2  0  2 ��
J �� �� �� �� ��  2  4 ��  2  0  1
K �� �� �� �� ��  4 �� �� ��  1  0

�� : 1000������ ����

----------------------------------------
[����ġ ��ȭ ���� ���]
----------------------------------------
F :  1000    4 1000    4    4    0 1000 1000 1000    2    4
J :  1000    4 1000    4    4    0    6 1000    4    2    3
K :  1000    4 1000    4    4    0    6 1000    4    2    3
B :     8    4 1000    4    4    0    6 1000    4    2    3
D :     6    4    6    4    4    0    6 1000    4    2    3
E :     6    4    6    4    4    0    6 1000    4    2    3
I :     6    4    6    4    4    0    6    6    4    2    3
A :     6    4    6    4    4    0    6    6    4    2    3
C :     6    4    6    4    4    0    6    6    4    2    3
G :     6    4    6    4    4    0    6    6    4    2    3
H :     6    4    6    4    4    0    6    6    4    2    3

----------------------------------------
[�������� �θ�, �ڽİ��� ���]
----------------------------------------
child :    A  B  C  D  E  F  G  H  I  J  K
Parent :   D  F  D  F  F  *  J  I  J  F  J

----------------------------------------
[F���� �� ���������� path ���]
----------------------------------------
F ->   D ->   A  (weight: 6)
F ->   B  (weight: 4)
F ->   D ->   C  (weight: 6)
F ->   D  (weight: 4)
F ->   E  (weight: 4)
F  (weight: 0)
F ->   J ->   G  (weight: 6)
F ->   J ->   I ->   H  (weight: 6)
F ->   J ->   I  (weight: 4)
F ->   J  (weight: 2)
F ->   J ->   K  (weight: 3)

*/