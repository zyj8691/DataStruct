#include"stdio.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */

typedef int Status;	/* Status �Ǻ���������,��ֵ�Ǻ������״̬���룬��
					OK �� */
typedef int ElemType;	/* ElemType ���͸���ʵ������������������Ϊ int
						*/
typedef struct
{
	ElemType data[MAXSIZE];	/*  ���飬�洢����Ԫ�� */
	int length;	/*  ���Ա�ǰ���� */
}SqList;

Status InitList(SqList*L)
{
	L->length = 0;
	return OK;
}
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}
Status GetElem(SqList L, int i, ElemType *e)
{
	if (i > L.length||L.length==0||i<1)//���������Ҫ���ǵ�
		return FALSE;
	*e = L.data[i-1];
	return OK;
}
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i]==e)
			break;
	}
	if (i>L.length)
		return 0;
	return i + 1;
}

Status Listlnsert(SqList*L, int i, ElemType e)
{

}

int main()
{
	printf("hello world\n");
	
	return 0;
}