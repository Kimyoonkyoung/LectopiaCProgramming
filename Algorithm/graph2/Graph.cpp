#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX];  /* �湮�� ������ 1�� �̹湮 ������ 0���� ���� */
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: initGraph() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
                                �׷����� ���� ��Ĺ����� �ʱ�ȭ�ϴ� �Լ�
  ��������:  gm - �׷��� ���� ����ü�� �ּ�
             fileName - �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i,j,k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */

	fp=fopen(fileName, "rt");
	assert(fp!=NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* ������ ������ ������ �б� */

	for (i = 0; i < gm->vertexCnt; i++) {
		for (j = 0; j < gm->vertexCnt; j++) {
			gm->graph[i][j] = 0;
		}
	}

	for (i = 0; i < gm->edgeCnt; i++){
		fscanf(fp, "%c%c ", &vertex[0], &vertex[1]);

		gm->graph[vertex[0] - 'A'][vertex[1] - 'A']++;
		gm->graph[vertex[1] - 'A'][vertex[0] - 'A']++;
	}

	fclose(fp);
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: outputGraph() - �׷������� ������ ������ ���踦 ���� ��� ���·� ���
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i,j;         /* iterator */

	/* ������ ���ι��� ��� */
	printf("   ");
	for(i=0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;  // ���� ��ũ�� 

	for(i=0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for(j=0; j<gm->vertexCnt; j++)
				printf("%3d", gm->graph[i][j]);
		NEWL;
	}
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: DFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
                                   �ϱ� ���� �Լ�(�����)
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for(i=0; i<gm->vertexCnt; ++i)  /* ������ �湮���� ������ ������ check�迭 �ʱ�ȭ */
		check[i] = 0;
	for(i=0; i<gm->vertexCnt; ++i)
		if(check[i] == 0) 
			DFS_recursive(gm, i);
	return;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: DFS_recursive() - ����Ǿ��ִ� �ϳ��� �׷��� ���� ��� ������ 
                                    ���ȣ�������� �湮�ϴ� �Լ�
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
             vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_recursive(GraphMatrix *gm, int vNum)
{
	int i;

	check[vNum]++;
	printf("%c ", vNum + 'A');

	for (i = 0; i < gm->vertexCnt; i++) {
		if ((gm->graph[vNum][i] == 1) && (check[i] == 0)) {
			DFS_recursive(gm, i);
		}
	}
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: visit() - �湮�� ������ ó���ϴ� �Լ�(�� �Լ������� �湮�� ������ ��� ��)
  ��������: vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void visit(int vNum)
{
	printf("%3c", 'A'+vNum);
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: nrDFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
                                   �ϱ� ���� �Լ�(�� �����)
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����    
--------------------------------------------------------------------------------------*/
void nrDFS_Matrix(GraphMatrix *gm)
{
	//���� § �ڵ�
#if 01
	Stack visitingPoint;
	char check[100] = { 0, };
	int i, j, visitCount = 0;
	int startValue = 0;

	initStack(&visitingPoint);

	while (1) {
		for (i = 0; i < gm->vertexCnt; i++) {
			if (check[i] == 0)
				break;
		}
		push(&visitingPoint, i + 'A');
		check[i]++;
		pop(&visitingPoint, &i);
		printf("%c ", i);
		visitCount++;
		i -= 'A';

		if (visitCount >= gm->vertexCnt)
			break;

		while (1) {
			for (j = 0; j < gm->vertexCnt; j++) {
				if (check[j] == 1)
					continue;

				if (gm->graph[i][j] == 1) {
					push(&visitingPoint, j + 'A');
					check[j]++;
				}
			}
			pop(&visitingPoint, &i);
			printf("%c ", i);
			visitCount++;

			i -= 'A';

			if (isStackEmpty(&visitingPoint) == TRUE)
				break;
		}
	}
	destroyStack(&visitingPoint);
#endif

	//����� �ڵ�
#if 0
	int i, j;
	int popData; /* pop�� ������ ���� */
	Stack stack;
	initStack(&stack); /* ����� ó���� ���� ���� ���� �ʱ�ȭ */

	for (i = 0; i<gm->vertexCnt; ++i) /* ������ �湮���� ������ ������ check�迭 �ʱ�ȭ */
		check[i] = 0;

	for (i = 0; i<gm->vertexCnt; ++i) /* ���������� ������ �湮�� */
	{
		if (check[i] == 0) /* �湮���� ���� ������ �߰� �ϸ� */
		{
			push(&stack, i);
			check[i] = 1; /* �湮���¸� 1�� ���� */
			while (!isStackEmpty(&stack)) /* ������ ��� �� ���� ��ҿ� ���� ��ȸ�� �������� �ǹ��� */
			{
				pop(&stack, &popData);
				visit(popData); /* ���� �湮 */

				for (j = 0; j<gm->vertexCnt; ++j)
					if (gm->graph[popData][j] != 0 && check[j] == 0) /* (!!)pop�� ������ ����� j������ �ְ� j������ ���ÿ� ������� ������ */
					{
						push(&stack, j); /* j������ ���ÿ� �����ϰ� */
						check[j] = 1; /* �湮���¸� 1�� ���� */
					}
			}
		}
	}
	destroyStack(&stack);
	return;
#endif
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: nrBFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� �ʺ� �켱 Ž��
                                   �ϱ� ���� �Լ�(�� �����)
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void BFS_Matrix(GraphMatrix *gm)
{
	Queue visitingPoint;
	char check[100] = { 0, };
	int i, j, visitCount = 0;
	int startValue = 0;

	initQueue(&visitingPoint, gm->vertexCnt);;

	while (1) {
		if (visitCount >= gm->vertexCnt)
			break;

		for (i = 0; i < gm->vertexCnt; i++) {
			if (check[i] == 0)
				break;
		}
		enqueue(&visitingPoint, i + 'A');
		check[i]++;
		dequeue(&visitingPoint, &i);
		printf("%c ", i);
		visitCount++;
		i -= 'A';

		while (1) {
			for (j = 0; j < gm->vertexCnt; j++) {
				if (check[j] == 1)
					continue;

				if (gm->graph[i][j] == 1) {
					enqueue(&visitingPoint, j + 'A');
					check[j]++;
				}
			}
			dequeue(&visitingPoint, &i);
			printf("%c ", i);
			visitCount++;

			i -= 'A';

			if (isQueueEmpty(&visitingPoint) == TRUE)
				break;
		}
	}
	destroyQueue(&visitingPoint);
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: countGraphComponents() - ���� ��Ĺ����� ǥ��� �׷��� ���� ���� ��Һ��� 
                                           �������� ����ϰ� ���� ����� ���� ����
  ��������:  gm : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: �׷������� ���� ����� ����
--------------------------------------------------------------------------------------*/
int countGraphComponents(GraphMatrix *gm)
{
	int componetsCount=0;  /* �׷��� ���� ���� ��� ī��Ʈ ���� */
	
	Stack visitingPoint;
	char check[100] = { 0, };
	int i, j, visitCount = 0;
	int startValue = 0;

	initStack(&visitingPoint);

	while (1) {
		for (i = 0; i < gm->vertexCnt - 1; i++) {
			if (check[i] == 0) {
				push(&visitingPoint, i + 'A');
				check[i]++;
				break;
			}
		}
	
		for (i = 0; i < gm->vertexCnt; i++) {
			if (check[i] == 0)
				visitCount = FALSE;
			else
				visitCount = TRUE;
		}
		if (visitCount == TRUE)
			break;

		componetsCount++;
		printf("���� ��� %d :  ", componetsCount);
		while (!isStackEmpty(&visitingPoint)) {
			
			pop(&visitingPoint, &i);
			printf("%c ", i);
			i -= 'A';

			for (j = 0; j < gm->vertexCnt; j++) {
				if (check[j] == 1)
					continue;

				if (gm->graph[i][j] == 1) {
					push(&visitingPoint, j + 'A');
					check[j]++;
				}
			}
		}
		NEWL;
	}
	destroyStack(&visitingPoint);
	
	return componetsCount;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: initGraph_L() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
                                 �׷����� ���� ����Ʈ������ �ʱ�ȭ�ϴ� �Լ�
  ��������:  g : �׷��� ���� ����ü�� �ּ�
             fileName : �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initGraph_List(GraphList *g, char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i,j,k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */
	Node *pl1, *pl2, *nul;

	fp=fopen(fileName, "rt");
	assert(fp!=NULL);
	fscanf(fp, "%d %d\n", &g->vertexCnt, &g->edgeCnt);  /* ������ ������ ������ �б� */

	for (i = 0; i < g->vertexCnt; i++){
		g->graph[i] = (Node*)malloc(sizeof(Node));
		g->graph[i]->vertex = i;
		nul = (Node*)malloc(sizeof(Node));
		nul = NULL;

		g->graph[i]->next = nul;
	}

	for (i = 0; i < g->edgeCnt; i++){
		fscanf(fp, "%c%c ", &vertex[0], &vertex[1]);

		pl1 = (Node*)malloc(sizeof(Node));
		pl1->vertex = vertex[1] - 'A';
		pl2 = (Node*)malloc(sizeof(Node));
		pl2->vertex = vertex[0] - 'A';

		pl1->next = g->graph[vertex[0] - 'A']->next;
		g->graph[vertex[0] - 'A']->next = pl1;
		
		pl2->next = g->graph[vertex[1] - 'A']->next;
		g->graph[vertex[1] - 'A']->next = pl2;
		
		//printf("%c %c\n", g->graph[vertex[0] - 'A']->next->vertex + 'A', g->graph[vertex[1] - 'A']->next->vertex + 'A');
	}

	fclose(fp);
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: addNode() - �� ������ ���踦 ����Ʈ�� �����
  ��������:  g - �׷��� ���� ����ü�� �ּ�
			 vNum1 - ù��° ������ ��ȣ
			 vNum2 - �ι�° ������ ��ȣ
  ���ϰ�: ���� ����� �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int addNode(GraphList *g, int vNum1, int vNum2)
{

        // TODO
	return TRUE;
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: outputGraph_L() - �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ���
  ��������:  g : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph_List(GraphList *g)
{
	Node *out;
	int i;

	for (i = 0; i < g->vertexCnt; i++){
		out = g->graph[i]->next;

		printf("%c :   ", g->graph[i]->vertex + 'A');
		while (out->next != NULL){
			printf("%c ->  ", out->vertex + 'A');

			out = out->next;
		}
		printf("%c\n", out->vertex + 'A');
	}
}
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: destroyGraph_L() - �׷������� ���� ��� ��� ����
  ��������:  g : �׷��� ���� ����ü�� �ּ�
  ���ϰ�: ����
--------------------------------------------------------------------------------------*/
void destroyGraph_List(GraphList *g)
{
	int i;
	Node *fre;

	for (i = 0; i < g->vertexCnt; i++) {
		fre = g->graph[i]->next;

		while (fre != NULL)
		{
			g->graph[i]->next = fre->next;
			free(fre);
			fre = g->graph[i]->next;
		}
		free(fre);

		free(g->graph[i]);
	}
}