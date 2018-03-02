#include"stdio.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  存储空间初始分配量 */

typedef int Status;	/* Status 是函数的类型,其值是函数结果状态代码，如
					OK 等 */
typedef int ElemType;	/* ElemType 类型根据实际情况而定，这里假设为 int
						*/
typedef struct
{
	ElemType data[MAXSIZE];	/*  数组，存储数据元素 */
	int length;	/*  线性表当前长度 */
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
	if (i > L.length||L.length==0||i<1)//三种情况都要考虑到
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