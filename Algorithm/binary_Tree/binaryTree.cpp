#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

/* -------------------------------------------------------------------------------------
�Լ��� : initTree - Ʈ�� ���� ����ü�� �ʱ�ȭ �ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
���� �� : ����
--------------------------------------------------------------------------------------*/
void initTree(Tree *tr)
{
	tr->root = NULL;
	tr->nodeCnt = 0;
}
/* --------------------------------------------------------------------------------------
�Լ��� : makeNode - �� ��带 ����� �� ����� �ּҸ� �����ϴ� �Լ�
�������� : data - �� ��忡 ����� ��(������)
left - �� ����� left ��� ��
right - �� ����� right ��� ��
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer 
---------------------------------------------------------------------------------------*/
Node * makeNode(DataType *data, Node * left, Node *right)
{
	Node *np;
	np = (Node *)malloc(sizeof(Node));
	if (np != NULL) {
		np->data = *data;
		np->left = left;
		np->right = right;
	}
	return np;
}

/* --------------------------------------------------------------------------------------
�Լ��� : addNode - ��带 �����ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
data - �� ��忡 ����� ������ ���� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer
---------------------------------------------------------------------------------------*/
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *tp, *prt;

	if (tr->root == NULL)
	{
		prt = makeNode(data, NULL, NULL);
		if (prt == NULL)
			return NULL;

		tr->root = prt;
		tr->nodeCnt++;
	}
	else
	{
		tp = tr->root;
		prt = makeNode(data, NULL, NULL);
		if (prt == NULL)
			return NULL;
		
		while (!(tp->left == prt || tp->right == prt)){
			if (compare(&(tp->data), data) == 1){
				if (tp->left == NULL){
					tp->left = prt;
					tr->nodeCnt++;
				}
				else
					tp = tp->left;
			}
			else{
				if (tp->right == NULL){
					tp->right = prt;
					tr->nodeCnt++;
				}
				else
					tp = tp->right;
			}
		}
	}

	return prt;
}
/* --------------------------------------------------------------------------------------
�Լ��� : inorderTraverse - ������ȸ(���� ������ ���)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void inorderTraverse(Node *np, void(*print)(DataType *))
{
	if (np != NULL) {
		inorderTraverse(np->left, print);
		print(&np->data);
		inorderTraverse(np->right, print);
	}
}

/* --------------------------------------------------------------------------------------
�Լ��� : preorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void preorderTraverse(Node *np, void(*print)(DataType *))
{
     // TODO	
}
/* --------------------------------------------------------------------------------------
�Լ��� : postorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderTraverse(Node *np, void(*print)(DataType *))
{
     // TODO	
}
/* --------------------------------------------------------------------------------------
�Լ��� : searchNode - data�� �ش��ϴ� ��� �˻�
�������� : tr - Tree ����ü�� �ּ�
data - �˻��� ������ ���� ������ �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ã�� ����� �ּ� / ��ã���� NULL pointer
---------------------------------------------------------------------------------------*/
Node * searchNode(Tree *tr, DataType  *data, int(*compare)(DataType *, DataType *))
{
	Node *tp, *prt;

	tp = tr->root;
	prt = makeNode(data, NULL, NULL);

	while (!(tp->left == prt || tp->right == prt)){
		if (compare(&(tp->data), data) == 1){
			if (tp->left == NULL)
				break;
			tp = tp->left;
		}
		else {
			if (tp->right == NULL)
				break;
			tp = tp->right;
		}
	}
	if (compare(&(tp->data), data) == 0)
		return tp;
	

	return NULL;
}

/* --------------------------------------------------------------------------------------
�Լ��� : deleteNode - data�� �ش��ϴ� ��� ����
�������� : tr - Tree ����ü�� �ּ�
data - ������ �������� �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ������ ����� parent ����� �ּ� / ��ã����(���� ���� ��) NULL pointer
---------------------------------------------------------------------------------------*/
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *dele = NULL, *prt, *tp;

	tp = tr->root;

	while (dele == NULL)
	{
		if (compare(&(tp->data), data) == 1) {
			if (tp->left == NULL)
				return NULL;
			if (tp->left->data == *data)
			{	
				dele = tp->left;
				break;
			}
			tp = tp->left;
		}
		else {
			if (tp->right == NULL)
				return NULL;
			if (tp->right->data == *data)
			{
				dele = tp->right;
				break;
			}
			tp = tp->right;
		}
	}

	if (dele->right == NULL)
	{
		if (compare(&(tp->data), &(dele->data)) == 1)
			tp->left = dele->left;
		else
			tp->right = dele->left;

		free(dele);
	}
	else if (dele->right->left == NULL)
	{
		tp->left = dele->right;
		tp->left->left = dele->left;

		free(dele);
	}
	else
	{

	}
	// ����1 : ������ ����� ������ �ڽ��� ���� ���-������ ����� ���� �ڽ��� son����
	
	// ����2 : ������ ����� ������ �ڽ��� ���� �ڽ��� ���� ���-������ ����� ������ �ڽ��� son����
	
	// ����3 : �׿� ��� ���-������ ����� ������ ����Ʈ������ ������ �����Ϳ� ���� ����� ���� ã��
	
	// ������ ��� ��� �ڽ�(son) ������ �� ��带 ��ġ��Ŵ
	return tp;
}
/* --------------------------------------------------------------------------------------
�Լ��� : destroyTree - tree ���� ��� ��� ����(tree �Ҹ�)
�������� : tr - Tree ����ü�� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);  // ������ ���� ��ȸ �ϸ� ����
	tr->root = NULL;
	tr->nodeCnt = 0;
}

/* --------------------------------------------------------------------------------------
�Լ��� : postorderDelete - postorder(���� ��ȸ)����� ��� ����(���ȣ�� �Լ�)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderDelete(Node *np, void(*print)(DataType *))
{

}
