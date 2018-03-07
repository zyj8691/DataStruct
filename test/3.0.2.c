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
*�ڵ㣺
*�����������ָ����
*/
typedef struct Node
{
	ElemType data;	
	struct Node *next;//�����ַ
}Node;
typedef struct Node *LinkList;//LinkList ���� Node*����¼ͷ����ַ����Ϊͷָ��
/**
*ͷ��㣺��������Բ������κ���Ϣ���ɸ������Ա�ĳ��ȣ�
*ͷ����ָ����洢ָ���һ���ڵ��ָ��
*���Ա����һ���ڵ��ָ����Ϊ��(NULL)
*ͷָ�룺ָ�����Ա�ĵ�һ���ڵ㣨ͷ��㣩;
*/
/*��ʼ������*/
Status InitList(LinkList *L)//LinkList����Ϊ���Ա��ͷָ�룬�����β�Ϊָ����ʽ���������Ըı䴫���ʵ��
{
	/*(*L)ͷָ�룬Lָ��ͷָ��ĵ�ַ*/
	*L = (LinkList)malloc(sizeof(Node));/*  ����ͷ���,��ʹ L ָ���ͷ��� */
	if (!(*L)) /* �洢����ʧ��,��(*L)ͷָ��δ�����ɹ���������L��ָ��ͷָ��ĵ�ַΪδ�����ɹ� */
		return ERROR;
	(*L)->next = NULL;//ָ����Ϊ��
	return OK;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��ڡ������������ L Ϊ�ձ��򷵻� TRUE�����򷵻� FALSE
*/
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return OK;
}
/*	������� n ��Ԫ�ص�ֵ����������ͷ���ĵ������Ա� L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n)
{
	LinkList p;//����һ�����������ڵ�
	//�����ʼ��
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		p->next = (*L)->next;
		(*L)->next = p;//ָ��ڵ�P�������ǽڵ�������򣬼�����(*L)->next = p->data
	}

}
/*	������� n ��Ԫ�ص�ֵ����������ͷ���ĵ������Ա� L��β�巨�� */
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	//��ʼ������
	(*L) = (LinkList)malloc(sizeof(Node));
	//β�ڵ㸳ֵ
	r = (*L);
	for (int i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i + 1;
		//��������β��
		r->next = p;
		//�ƶ�β�ڵ�
		r = p;
	}
	r->next = NULL;
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
/*��ʼ����:˳������.... L �Ѵ��ڣ�*/
/*�������:�� L �е� i -1��λ��֮ǰ����µ�����Ԫ�� e . L �ĳ��ȼ� 1 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j=1;
	LinkList p,s;
	p = (*L);/*ͷ���*/
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p->next||j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));/*��Ϊs�ǲ�����½ڵ㣬����ҪΪ�������ڴ�ռ䣬������
	������������ʱ�ڵ㣬��ʱ�ڵ㲻��Ҫ����ռ�*/
	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p,s;
	p = (*L);/*ͷ���*/
	int j=1;
	/*��ΪpΪҪɾ���ڵ��ǰһ�ڵ㣬������Ҫ��p->next�ж��Ƿ񳬳�����Χ*/
	while (p->next&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i)
		return ERROR;
	//s = (LinkList)malloc(sizeof(Node));/*��ʱ�ڵ㣬����Ҫ�����ڴ�*/
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
	if (!p || j>i)/*ò�Ƴ��ֲ���j>i�������������������Χʱ��p=NUll*/
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
//		printf("�ɹ�����\n");
//	else
//		printf("����ʧ��\n");
//	i = ListEmpty(L);
//	if (i)
//		printf("������\n");
//	else
//		printf("�ǿ�����\n");
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
