#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */


typedef int Status;
typedef int QElemType; /* QElemType ���͸���ʵ������������������Ϊ int */

/*ѭ�����е�˳��洢�ṹ*/
typedef struct  
{
	QElemType data[MAXSIZE];
	int front;/*ͷָ��*/
	int rear;/*βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��*/
}SqQueue;

/* ��ʼ��һ���ն���Q*/
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/*��Q��Ϊ�ն���*/
Status ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return OK;
}

/*������QΪ�ն��У��򷵻�TRUE�����򷵻�FASLE*/
Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)/*���пյı�־*/
		return TRUE;
	else
		return FALSE;
}

/*����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����*/
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���� ERROR */
Status GetHead(SqQueue Q, QElemType *e)
{
	if (Q.front == Q.rear) /*���п�*/
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}


/*������δ���������Ԫ��eΪQ�µĶ�βԪ��*/
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)/*���������ж�*/
		return ERROR;
	Q->data[Q->rear] = e;				/*��Ԫ��e��ֵ����β*/
	Q->rear = (Q->rear + 1) % MAXSIZE;	/*rearָ�������һλ�ã�
										���������ת������ͷ��*/
	return OK;
}

/*�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ*/
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)/*���пյ��ж�*/
		return ERROR;
	*e = Q->data[Q->front];				/*����ͷԪ�ظ�ֵ��e*/
	Q->front = (Q->front + 1) % MAXSIZE;	/*frontָ�������һλ��
											���������ת������ͷ��*/
	return OK;
}

Status visit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

/*�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����*/
Status QueueTraverse(SqQueue Q)
{
	int i = Q.front;
	while ((i + Q.front) != Q.rear)
	{
		visit(Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");

	return OK;
}

int main()
{
	
	
	return 0;
}