#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAXSIZE 20

typedef int ElemType;

typedef int Status;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

/*初始化链表*/
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	return OK;
}

/*  初始条件：顺序线性表 L 已存在。操作结果：若 L 为空表，则返回 TRUE，否则返回 FALSE
*/
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return OK;
}
/*	随机产生 n 个元素的值，建立带表头结点的单链线性表 L（头插法） */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;

	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}
/*	随机产生 n 个元素的值，建立带表头结点的单链线性表 L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;

	(*L) = (LinkList)malloc(sizeof(Node));
	r = (*L);
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
/*输出链表所有信息*/
void disFinc(LinkList L)
{
	LinkList p;
	p = L;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
/*初始条件:顺序线性.... L 已存在，*/
/*操作结呆:在 L 中第 i -1、位皇之前楠入新的数据元素 e . L 的长度加 1 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j=1;
	LinkList p,s;
	p = (*L);
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p->next||j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p,s;
	p = (*L);
	int j=1;
	while (p->next&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i)
		return ERROR;
	//s = (LinkList)malloc(sizeof(Node));
	s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	return OK;

}
Status GetElem(LinkList *L, int i, ElemType *e)
{
	LinkList p;
	p = (*L)->next;
	int j = 1;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	//p = p->next;
	*e = p->data;
	return OK;
}
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
int main()
{
	LinkList L;
	//Status i;
	/*i = InitList(&L);
	if (i)
		printf("成功创建\n");
	else
		printf("创建失败\n");
	i = ListEmpty(L);
	if (i)
		printf("空链表\n");
	else
		printf("非空链表\n");*/
	/*CreateListHead(&L, 10);
	disFinc(L);*/
	CreateListTail(&L,5);
	printf("--------------------------\n");
	disFinc(L);

	int s=ListInsert(&L, 6, 0);
	printf("--------------------------\n");
	printf("%d\n", s);
	disFinc(L);

	ElemType e;
	s = ListDelete(&L, 3, &e);
	printf("--------------------------\n");
	printf("%d\n", s);
	disFinc(L);

	s = GetElem(&L, 2, &e);
	printf("e = %d\n", e);


	s=ClearList(&L);
	printf("--------------------------\n");
	printf("s = %d\n", s);
	disFinc(L);
	system("pause");
	return 0;
}