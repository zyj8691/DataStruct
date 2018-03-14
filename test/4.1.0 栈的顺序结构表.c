#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*存储空间初始分配量*/

typedef int Status;
typedef int SElemType;/*SElemType 类型根据实际情况而定，这里假设为int*/
/*顺序栈结构*/
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /*用于栈顶指针*/
}SqStack;

/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)/*栈满*/
		return ERROR;
	S->top++;				/*栈顶指针增加一*/
	S->data[S->top] = e;	/*将新插入元素赋值给栈顶空间*/
	return OK;
}
/*若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/*将要删除的栈顶元素赋值给e*/
	S->top--;				/*栈顶指针减一*/
	return OK;
}
/*两栈共享空间*/
typedef struct  
{
	SElemType data[MAXSIZE];
	int top1;	/*栈1栈顶指针*/
	int top2;	/*栈2栈顶指针*/

}SqDoubleStack;

/*插入元素e为新的栈顶元素*/
Status PushD(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (stackNumber == 1)	/*栈1元素进栈*/
	{
		S->data[++S->top1] = e;/*若栈1则先top1+1后给数组元素赋值*/
	}
	else if (stackNumber==2)	/*栈2元素进栈*/
	{
		S->data[--S->top2] = e;/*若栈2则先top2+1后给数组元素赋值*/
	}
	return OK;
}
Status PopD(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)		/*说明栈1已经是空栈，溢出*/
			return ERROR;
		*e = S->data[S->top1--];/*将栈1的栈顶元素出栈，再移动top指针*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)/*说明栈2已经是空栈，溢出*/
			return ERROR;
		*e = S->data[S->top2++];/*将栈2的栈顶元素出栈，再移动top指针*/
	}
	return OK;
}
int main()
{
	
	
	return 0;
}