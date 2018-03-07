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
typedef struct Node* LinkList;

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	return OK;
}
void CreateListHead(LinkList *L, int n)
{
	LinkList p; int i;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	r = (*L);
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
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
}
Status GetElem(LinkList L, int i, ElemType *e)/*�Լ�д�Ŀ�������*/
{
	LinkList p;
	int j = 1;
	p = L->next;
	while (p)
	{
		if (j < i)
		{
			p = p->next;
			j++;
		}
		else{
			*e = p->data;
			return OK;
		}
	}
	return FALSE;

}
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;
	LinkList p, s;
	p = (*L);
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));/*��Ϊs�ǲ�����½ڵ㣬����ҪΪ�������ڴ�ռ䣬������
									   ������������ʱ�ڵ㣬��ʱ�ڵ㲻��Ҫ����ռ�*/
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/*�������������Ϣ*/
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
int main()
{
	LinkList L;
	CreateListTail(&L, 10);
	disFinc(L);
	/*ClearList(&L);
	printf("-------------\n");
	disFinc(L);*/
	ElemType e;
	int s = GetElem(L, 11, &e);
	if (s)
		printf("e = %d\n", e);
	else
		printf("cant find\n");
	e = 666;
	ListInsert(&L, 2, e);
	disFinc(L);
	return 0;
}