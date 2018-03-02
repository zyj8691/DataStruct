#include "stdio.h"

#define MAXSIZE 20

typedef int ElemType;

typedef int Status;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return OK;
	else
		return FALSE;
}

int main()
{
	printf("hello world\n");
	
	return 0;
}