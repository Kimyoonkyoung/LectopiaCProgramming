#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
함수명및기능: initStack() - 지정된 크기의 스택을 생성하는 함수
전달인자: sPtr -  스택의 주소
sSize - 스택의 크기
리턴값: 없음
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr, int sSize)
{
	sPtr->stack = (DataType *)calloc(sSize , sizeof(DataType));  // 메모리 할당 & 0으로 초기화
	assert(sPtr->stack!=NULL);
	sPtr->sSize = sSize;
	sPtr->top = 0;
}
/*-----------------------------------------------------------------------------------
함수명 및 기능 : isStackFull() - 스택이 꽉 차있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 꽉 차있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sPtr)
{
	if(sPtr->top == (sPtr->sSize))
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------------------------
함수명 및 기능 : isStackEmpty() - 스택이 비어있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 비어있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr)
{ 
	if (sPtr->top == 0)
		return 1;
	else
		return 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: clearStack() - 스택 초기화 함수(모든 데이터 삭제 개념)
전달인자: sPtr - 스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------
void clearStack(Stack *sPtr)
{
    // TODO
}
*/
/*--------------------------------------------------------------------------------------
함수명및기능: push() - 스택에 데이터 하나를 저장함
전달인자: sPtr - 스택의 주소
inData - 스택에 저장할 데이터
리턴값: 성공적으로 저장하면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, DataType inData) /* stack에 데이터 저장하기 */
{
	if (isStackFull(sPtr) == 0)
	{
		sPtr->stack[sPtr->top] = inData;
		(sPtr->top)++;
		return 1;
	}
	else
		return 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: pop() - 스택에서 데이터 하나를 꺼냄
전달인자: sPtr - 스택의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
리턴값: 성공적으로 꺼내면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int pop(Stack * sPtr, DataType *popData)
{
	if (isStackEmpty(sPtr) == 0)
	{
		sPtr->top--;
		*popData = sPtr->stack[sPtr->top];
		return 1;
	}
	else
		return 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: printStack() - 스택의 모든 데이터를 출력 함
전달인자: sPtr -  스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sPtr, void (*print)(DataType *p))  //0번 방부터 찍어
{
	int i;

	if (sPtr->top == 0)
		printf("Stack이 비어 있습니다.\n");
	else
	{
		for (i = sPtr->top - 1; i >= 0; i--)
			printf("%d ", sPtr->stack[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
함수명및기능: destroyStack() -  스택 소멸 함수
전달인자: sPtr -  스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr)
{
	free(sPtr->stack);

	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = 0;

	
}

