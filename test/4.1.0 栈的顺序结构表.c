#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*�洢�ռ��ʼ������*/

typedef int Status;
typedef int SElemType;/*SElemType ���͸���ʵ������������������Ϊint*/
/*˳��ջ�ṹ*/
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /*����ջ��ָ��*/
}SqStack;

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)/*ջ��*/
		return ERROR;
	S->top++;				/*ջ��ָ������һ*/
	S->data[S->top] = e;	/*���²���Ԫ�ظ�ֵ��ջ���ռ�*/
	return OK;
}
/*��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/*��Ҫɾ����ջ��Ԫ�ظ�ֵ��e*/
	S->top--;				/*ջ��ָ���һ*/
	return OK;
}
/*��ջ����ռ�*/
typedef struct  
{
	SElemType data[MAXSIZE];
	int top1;	/*ջ1ջ��ָ��*/
	int top2;	/*ջ2ջ��ָ��*/

}SqDoubleStack;

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status PushD(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (stackNumber == 1)	/*ջ1Ԫ�ؽ�ջ*/
	{
		S->data[++S->top1] = e;/*��ջ1����top1+1�������Ԫ�ظ�ֵ*/
	}
	else if (stackNumber==2)	/*ջ2Ԫ�ؽ�ջ*/
	{
		S->data[--S->top2] = e;/*��ջ2����top2+1�������Ԫ�ظ�ֵ*/
	}
	return OK;
}
Status PopD(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)		/*˵��ջ1�Ѿ��ǿ�ջ�����*/
			return ERROR;
		*e = S->data[S->top1--];/*��ջ1��ջ��Ԫ�س�ջ�����ƶ�topָ��*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)/*˵��ջ2�Ѿ��ǿ�ջ�����*/
			return ERROR;
		*e = S->data[S->top2++];/*��ջ2��ջ��Ԫ�س�ջ�����ƶ�topָ��*/
	}
	return OK;
}
int main()
{
	
	
	return 0;
}