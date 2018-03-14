#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /*  存储空间初始分配量 */

typedef int Status;	/* Status 是函数的类型,其值是函数结果状态代码，如 OK 等 */
typedef char ElemType;	/* ElemType 类型根据实际情况而定，这里假设为 char */
typedef struct
{
	ElemType data;
	int cur;	/*  游标(Cursor)  ，为 0 时表示无指向 */
} Component, StaticLinkList[MAXSIZE];
/*  将一维数组 space 中各分量链成一个备用链表，space[0].cur 为头指针，"0"表示空指针 */ 
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0; /* 目前静态链表为空，最后一个元素的 cur 为 0 */
	return OK;

}
/*返回静态链表的长度*/
int ListLength_zixie(StaticLinkList L)
{
	int i;
	for (i = 0; i < MAXSIZE - 1;i++)
	{
		if (L[i].cur==0)
			break;
	}
	return i;
}
/*  初始条件：静态链表 L 已存在。操作结果：返回 L 中数据元素个数 */
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
/*  若备用空间链表非空，则返回分配的结点下标，否则返回 0 */
int Malloc_SSL(StaticLinkList space)
{
	int i;
	i = space[0].cur;/*  当前数组第一个元素的 cur 存的值 */
					/*  就是要返回的第一个备用空闲的下标*/
	if (space[0].cur)//下标非零
		space[0].cur = space[i].cur;/*  由于要拿出一个分量来使用了， */
									/*  所以我们就得把它的下一个 */
									/*  分量用来做备用 */
	return i;
}

/*在 L 中第 i 个元素之前插入新的数据元素e*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int k = MAXSIZE - 1;/*  注意 k 首先是最后一个元素的下标 */
	if (i<i || i>ListLength(L) + 1)//i>ListLength(L) + 1会出现中间未存储的变量。
		return ERROR;
	int j = Malloc_SSL(L);
	j = Malloc_SSL(L);	/*  获得空闲分量的下标 */
	if (j)
	{
		L[j].data = e;	/*  将数据赋值给此分量的 data */
		for (int l = 1; l <= i - 1; l++)/* 找到第 i 个元素之前的位置 */
		k = L[k].cur;
		L[j].cur = L[k].cur;/* 把第i个元素之前的cur 赋值给新元素的cur */
		L[k].cur = j;/* 把新元素的下标赋值给第i个元素之前元素的cur */
		return OK;
	}
	return ERROR;

}
/*将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;    /*  把第一个元素的 cur 值赋给要删除的分量 cur */
	space[0].cur = k;   /*  把要删除的分量下标赋值给第一个元素的 cur */
}
/*  删除在 L 中第 i 个数据元素    */
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i < 1 || i > ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	Free_SSL(L, j);
	return OK;
}
int main()
{
	StaticLinkList L;
	
	return 0;
}