#include"stdio.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /*  存储空间初始分配量 */

typedef int Status;	/* Status 是函数的类型,其值是函数结果状态代码，如
					OK 等 */
typedef int ElemType;	/* ElemType 类型根据实际情况而定，这里假设为 int
						*/
typedef struct
{
	ElemType data[MAXSIZE];	/*  数组，存储数据元素 */
	int length;	/*  线性表当前长度 */
}SqList;

/*  初始化顺序线性表 */
Status InitList(SqList*L)
{
	L->length = 0;
	return OK;
}

/*  初始条件：顺序线性表 L 已存在。操作结果：若 L 为空表，则返回 TRUE，否则 返回 FALSE */
Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

/*  初始条件：顺序线性表 L 已存在。操作结果：将 L 重置为空表 */
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/*  初始条件：顺序线性表 L 已存在，1≤i≤ListLength(L) */
/*  操作结果：用 e 返回 L 中第 i 个数据元素的值,注意 i 是指位置，第 1 个位置的数 组是从 0 开始 */
Status GetElem(SqList L, int i, ElemType *e)
{
	if (i > L.length||L.length==0||i<1)//三种情况都要考虑到
		return FALSE;
	*e = L.data[i-1];
	return OK;
}

/*  初始条件：顺序线性表 L 已存在 */
/*  操作结果：返回 L 中第 1 个与 e 满足关系的数据元素的位序。 */
/*  若这样的数据元素不存在，则返回值为 0 */
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
*插入算法的思路：
*1、如果插入位置不合理，抛出异常；
*2、如果线性表长度大于等于数组长度，则抛出异常或动态增加容量；
*3、从最后一个元素开始向前遍历得到第i个位置，分别将它们都向后移动一个位置；
*4、将要插入元素填入i处；
*5、表长加1；
*/
/*  初始条件：顺序线性表 L 已存在,1≤i≤ListLength(L)， */
/*  操作结果：在 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1 */
Status Listlnsert(SqList*L, int i, ElemType e)
{
	if (L->length >= MAXSIZE)/*  顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length + 1)/*i不在范围*/
		return ERROR;
	if (i <= L->length)/*  若插入数据位置不在表尾 */
	{
		for (int k = L->length - 1; k >= i - 1; k--)/*从线性表末尾开始，一直到第i个位置的数据往后移动一个单位*/
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}
/**
*删除算法的思路：
*1、如果删除位置不合理，抛出异常；
*2、取出删除元素；
*3、从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置；
*4、表长减1；
*/
/*  初始条件：顺序线性表 L 已存在，1≤i≤ListLength(L) */
/*  操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1 */
Status ListDelete(SqList *L, int i, ElemType *e)
{
	if (L->length == 0)/*线性表为零*/
		return ERROR;
	if (i<1 || i>L->length)/*删除位置不正确*/
		return ERROR;
	if (i < L->length)/*如果删除位置不在最后位置*/
	{
		for (int k = i; k < L->length; k++)/*从第i个位置开始，一直到数据末尾前一个的数据等于该位置后一个的数据*/
			L->data[k - 1] = L->data[k];
	}
	L->length--;/*若删除位置在线性表末尾，则利用线性表长度将次省略了，此处不牵扯动态内存问题*/
	return OK;
}

/*  初始条件：顺序线性表 L 已存在。操作结果：返回 L 中数据元素个数 */
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
			Listlnsert(La, ++La_len, e);/*La_len先++再进入函数，将e插入到La末尾*/
	}
}
int main()
{
	/*自己写验证*/
	
	return 0;
}