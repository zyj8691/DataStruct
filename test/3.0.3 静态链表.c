#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /*  �洢�ռ��ʼ������ */

typedef int Status;	/* Status �Ǻ���������,��ֵ�Ǻ������״̬���룬�� OK �� */
typedef char ElemType;	/* ElemType ���͸���ʵ������������������Ϊ char */
typedef struct
{
	ElemType data;
	int cur;	/*  �α�(Cursor)  ��Ϊ 0 ʱ��ʾ��ָ�� */
} Component, StaticLinkList[MAXSIZE];
/*  ��һά���� space �и���������һ����������space[0].cur Ϊͷָ�룬"0"��ʾ��ָ�� */ 
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0; /* Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص� cur Ϊ 0 */
	return OK;

}
/*���ؾ�̬����ĳ���*/
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
/*  ��ʼ��������̬���� L �Ѵ��ڡ�������������� L ������Ԫ�ظ��� */
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
/*  �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻� 0 */
int Malloc_SSL(StaticLinkList space)
{
	int i;
	i = space[0].cur;/*  ��ǰ�����һ��Ԫ�ص� cur ���ֵ */
					/*  ����Ҫ���صĵ�һ�����ÿ��е��±�*/
	if (space[0].cur)//�±����
		space[0].cur = space[i].cur;/*  ����Ҫ�ó�һ��������ʹ���ˣ� */
									/*  �������Ǿ͵ð�������һ�� */
									/*  �������������� */
	return i;
}

/*�� L �е� i ��Ԫ��֮ǰ�����µ�����Ԫ��e*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int k = MAXSIZE - 1;/*  ע�� k ���������һ��Ԫ�ص��±� */
	if (i<i || i>ListLength(L) + 1)//i>ListLength(L) + 1������м�δ�洢�ı�����
		return ERROR;
	int j = Malloc_SSL(L);
	j = Malloc_SSL(L);	/*  ��ÿ��з������±� */
	if (j)
	{
		L[j].data = e;	/*  �����ݸ�ֵ���˷����� data */
		for (int l = 1; l <= i - 1; l++)/* �ҵ��� i ��Ԫ��֮ǰ��λ�� */
		k = L[k].cur;
		L[j].cur = L[k].cur;/* �ѵ�i��Ԫ��֮ǰ��cur ��ֵ����Ԫ�ص�cur */
		L[k].cur = j;/* ����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur */
		return OK;
	}
	return ERROR;

}
/*���±�Ϊk�Ŀ��н����յ��������� */
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;    /*  �ѵ�һ��Ԫ�ص� cur ֵ����Ҫɾ���ķ��� cur */
	space[0].cur = k;   /*  ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص� cur */
}
/*  ɾ���� L �е� i ������Ԫ��    */
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