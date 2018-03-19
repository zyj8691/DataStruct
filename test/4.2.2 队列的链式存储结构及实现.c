#include"stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */

typedef int Status;
typedef int QElemType; /* QElemType ���͸���ʵ������������������Ϊ int */

typedef struct QNode/*���ṹ*/
{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct/*���е�����ṹ*/
{
	QueuePtr front, rear;/*��ͷ����βָ��*/
}LinkQueue;

/*����һ���ն���Q*/
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(0);
	Q->front->next = NULL;
	return OK;
}

/*���ٶ���*/
Status DestoryQueue(LinkQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

/*��Q��Ϊ�ն���*/
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

/*��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE*/
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/*����еĳ���*/
int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (p != Q.rear)
	{
		i++;
		p = p->next;
	}
	return i;
}

/*�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR*/
Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

/*����Ԫ��eΪQ���µĶ�βԪ��*/
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)				/* �洢����ʧ��*/
		return ERROR;
	s->data = e;	/*���s��ֵ*/
	s->next = NULL;
	Q->rear->next = s;/*��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��*/
	Q->rear = s;/*�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s*/
	return OK;
}

/*�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;/*����ɾ���Ķ�ͷ����ݴ��p*/
	*e = p->data;/*����ɾ���Ķ�ͷ����ֵ��ֵ��e*/
	Q->front->next = p->next;/*��ԭ��ͷ�����p->next��ֵ��ͷ�����
								��ֻ��һ�����ʱ��p->nextָ��null*/
	if (Q->rear == p)/*����ͷ�Ƕ�β����ɾ����rearָ��ͷ���*/
		Q->rear = Q->front;
	free(p);
	return OK;
}

Status visit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����*/
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p; p = Q.front->next; while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	
	
	return 0;
}