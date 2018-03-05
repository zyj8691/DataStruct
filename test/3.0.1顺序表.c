#include"stdio.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  �洢�ռ��ʼ������ */

typedef int Status;	/* Status �Ǻ���������,��ֵ�Ǻ������״̬���룬��
					OK �� */
typedef int ElemType;	/* ElemType ���͸���ʵ������������������Ϊ int
						*/
typedef struct
{
	ElemType data[MAXSIZE];	/*  ���飬�洢����Ԫ�� */
	int length;	/*  ���Ա�ǰ���� */
}SqList;

/*  ��ʼ��˳�����Ա� */
Status InitList(SqList*L)
{
	L->length = 0;
	return OK;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��ڡ������������ L Ϊ�ձ��򷵻� TRUE������ ���� FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��ڡ������������ L ����Ϊ�ձ� */
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��ڣ�1��i��ListLength(L) */
/*  ����������� e ���� L �е� i ������Ԫ�ص�ֵ,ע�� i ��ָλ�ã��� 1 ��λ�õ��� ���Ǵ� 0 ��ʼ */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (i > L.length||L.length==0||i<1)//���������Ҫ���ǵ�
		return FALSE;
	*e = L.data[i-1];
	return OK;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��� */
/*  ������������� L �е� 1 ���� e �����ϵ������Ԫ�ص�λ�� */
/*  ������������Ԫ�ز����ڣ��򷵻�ֵΪ 0 */
int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i]==e)
			break;
	}
	if (i>L.length)
		return 0;
	return i + 1;
}
/**
*�����㷨��˼·��
*1���������λ�ò������׳��쳣��
*2��������Ա��ȴ��ڵ������鳤�ȣ����׳��쳣��̬����������
*3�������һ��Ԫ�ؿ�ʼ��ǰ�����õ���i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ�ã�
*4����Ҫ����Ԫ������i����
*5������1��
*/
/*  ��ʼ������˳�����Ա� L �Ѵ���,1��i��ListLength(L)�� */
/*  ����������� L �е� i ��λ��֮ǰ�����µ�����Ԫ�� e��L �ĳ��ȼ� 1 */
Status Listlnsert(SqList*L, int i, ElemType e)
{
	if (L->length >= MAXSIZE)/*  ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length + 1)/*i���ڷ�Χ*/
		return ERROR;
	if (i <= L->length)/*  ����������λ�ò��ڱ�β */
	{
		for (int k = L->length - 1; k >= i - 1; k--)/*�����Ա�ĩβ��ʼ��һֱ����i��λ�õ����������ƶ�һ����λ*/
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}
/**
*ɾ���㷨��˼·��
*1�����ɾ��λ�ò������׳��쳣��
*2��ȡ��ɾ��Ԫ�أ�
*3����ɾ��Ԫ��λ�ÿ�ʼ���������һ��Ԫ��λ�ã��ֱ����Ƕ���ǰ�ƶ�һ��λ�ã�
*4������1��
*/
/*  ��ʼ������˳�����Ա� L �Ѵ��ڣ�1��i��ListLength(L) */
/*  ���������ɾ�� L �ĵ� i ������Ԫ�أ����� e ������ֵ��L �ĳ��ȼ� 1 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
	if (L->length == 0)/*���Ա�Ϊ��*/
		return ERROR;
	if (i<1 || i>L->length)/*ɾ��λ�ò���ȷ*/
		return ERROR;
	if (i < L->length)/*���ɾ��λ�ò������λ��*/
	{
		for (int k = i; k < L->length; k++)/*�ӵ�i��λ�ÿ�ʼ��һֱ������ĩβǰһ�������ݵ��ڸ�λ�ú�һ��������*/
			L->data[k - 1] = L->data[k];
	}
	L->length--;/*��ɾ��λ�������Ա�ĩβ�����������Ա��Ƚ���ʡ���ˣ��˴���ǣ����̬�ڴ�����*/
	return OK;
}

/*  ��ʼ������˳�����Ա� L �Ѵ��ڡ�������������� L ������Ԫ�ظ��� */
int ListLength(SqList L)
{
	return L.length;
}
void unionL(SqList*La, SqList Lb)
{
	int La_len, Lb_len;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (int i = 0; i < Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
			Listlnsert(La, ++La_len, e);/*La_len��++�ٽ��뺯������e���뵽Laĩβ*/
	}
}
int main()
{
	/*�Լ�д��֤*/
	
	return 0;
}