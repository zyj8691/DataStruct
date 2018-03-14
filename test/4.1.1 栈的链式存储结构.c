#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */


typedef int Status;
typedef int SElemType; /* SElemType ���͸���ʵ������������������Ϊ int */

typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

/*����һ����ջS*/
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}
/*��S��Ϊ��ջ*/
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE*/
Status StackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else

		return FALSE;
}

/* ����S��Ԫ�ظ���,��ջ�ĳ���*/
int StackLength(LinkStack S)
{
	return S.count;
}

/* ��ջ���գ����� e ���� S ��ջ��Ԫ�أ������� OK�����򷵻� ERROR */
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
}

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr n = (LinkStackPtr)malloc(sizeof(StackNode));
	n->data = e;
	n->next = S->top;/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�� */ 
	S->top = n;		/* ���µĽ��n��ֵ��ջ��ָ�� */
	S->count++;
	return OK;
}
/*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;	/*��ջ����㸳ֵ��p*/
	S->top = S->top->next;	/*ʹ��ջ��ָ������һλ��ָ���һ���*/
	free(p);	/*�ͷŽ��p*/
	S->count--;
	return OK;
}

int main()
{
	
	
	return 0;
}