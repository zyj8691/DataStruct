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
/**
*节点：
*包括数据域和指针域
*/
typedef struct Node
{
	ElemType data;	
	struct Node *next;//储存地址
}Node;
typedef struct Node *LinkList;//LinkList 代替 Node*，记录头结点地址，即为头指针
/**
*头结点：数据域可以不储存任何信息，可附加线性表的长度，
*头结点的指针域存储指向第一个节点的指针
*线性表最后一个节点的指针域为空(NULL)
*头指针：指向线性表的第一个节点（头结点）;
*/
/*初始化链表*/
Status InitList(LinkList *L)//LinkList变量为线性表的头指针，这里形参为指针形式，则函数可以改变传入的实参
{
	/*(*L)头指针，L指向头指针的地址*/
	*L = (LinkList)malloc(sizeof(Node));/*  产生头结点,并使 L 指向此头结点 */
	if (!(*L)) /* 存储分配失败,是(*L)头指针未创建成功，而不是L，指向头指针的地址为未创建成功 */
		return ERROR;
	(*L)->next = NULL;//指针域为空
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
	LinkList p;//创建一个新链表，单节点
	//链表初始化
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;//指向节点P，而不是节点的数据域，即不是(*L)->next = p->data
	}

}
/*	随机产生 n 个元素的值，建立带表头结点的单链线性表 L（尾插法） */
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	//初始化链表
	(*L) = (LinkList)malloc(sizeof(Node));
	//尾节点赋值
	r = (*L);
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		//插入链表尾部
		r->next = p;
		//移动尾节点
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
	p = (*L);/*头结点*/
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p->next||j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));/*因为s是插入的新节点，所以要为它分配内存空间，区别于
	其他函数的临时节点，临时节点不需要分配空间*/
	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p,s;
	p = (*L);/*头结点*/
	int j=1;
	/*因为p为要删除节点的前一节点，所以需要用p->next判断是否超出链表范围*/
	while (p->next&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i)
		return ERROR;
	//s = (LinkList)malloc(sizeof(Node));/*临时节点，不需要分配内存*/
	s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	return OK;
}
Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p;
	p = (*L)->next;
	int j = 1;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)/*貌似出现不了j>i的情况。。。；超出范围时，p=NUll*/
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

//int main()
//{
//	LinkList L;
//	//Status i;
//	/*
//	i = InitList(&L);
//	if (i)
//		printf("成功创建\n");
//	else
//		printf("创建失败\n");
//	i = ListEmpty(L);
//	if (i)
//		printf("空链表\n");
//	else
//		printf("非空链表\n");
//	*/
//	/*
//	CreateListHead(&L, 10);
//	disFinc(L);
//	*/
//	CreateListTail(&L,5);
//	printf("--------------------------\n");
//	disFinc(L);
//
//	int s=ListInsert(&L, 6, 0);
//	printf("--------------------------\n");
//	printf("%d\n", s);
//	disFinc(L);
//
//	ElemType e;
//	s = ListDelete(&L, 3, &e);
//	printf("--------------------------\n");
//	printf("%d\n", s);
//	disFinc(L);
//
//	s = GetElem(L, 2, &e);
//	printf("e = %d\n", e);
//
//
//	s=ClearList(&L);
//	printf("--------------------------\n");
//	printf("s = %d\n", s);
//	disFinc(L);
//	system("pause");
//	return 0;
//}
