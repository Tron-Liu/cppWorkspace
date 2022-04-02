#include "Sqlist.h"
#include "SqlistInit.h"
#include "SqlistInsert.h"
#include "Swap.h"
#include "SqlistDestroy.h"
#include "SqlistDisp.h"
#include "SqlistLength.h"
#include "SqlistEmpty.h"
#include "SqlistCreate.h"
#include "SqlistLocateElem.h"
#include "SqlistGetElem.h"
#include "SqlistDelete.h"

//例2.3 删除顺序表中值为 x的元素  解法一  P39
void delNote1(Sqlist *&L, ElemType x)
{
	int k = 0;												//k记录不等于x的元素的个数，即要插入到L中的元素个数 
	for(int i=0; i<L->length; i++) {       
		if(L->data[i] != x) {							//若当前元素不为x，将其插入到L中 
			L->data[k] = L->data[i];
			k++;												//插入一个元素，元素个数k加一 
		}
	}
	L->length = k;										//L长度等于k 
}

 //例2.3  解法二  P39
void delNode2(Sqlist *&L, ElemType x)
{

	int k = 0;												//k记录等于x的元素个数 
	for(int i=0; i<L->length; i++) {       
		if(L->data[i] == x)							//若当前元素等于x，k加一 
			k++;
		else
			L->data[i-k] = L->data[i];			//若不等于，将其位置前移 k的位置 
	}
	L->length = L->length - k;					//L长度等于原来长度减去 k 
}

//例2.4 p40  解法一 
int partition1(Sqlist *& L)
{
	int i=0, j=L->length-1;
	ElemType pivot = L->data[0];					//以data[0]为基准 
	while(i<j) {												//从区间两端交替向中间扫描，直到 i=j为止 
		while(i<j && L->data[i] <= pivot)		//从左向右扫描 ，找一个大于 pivot的数 
			i++;
		while(i<j && L->data[j] > pivot)			//从右向左扫描，找一个小于等于 pivot的数 
			j--;
		if(i < j) 
			Swap(L->data[i], L->data[j]);			//将 L->data[i]和 L->data[j]交换 
	}
	Swap(L->data[i], pivot);							// 将 L->data[i]和 L->data[0]交换 
 } 
 
//例2.4 p40  解法二 此解法更优 
int partition2(Sqlist *&L)
{
	int i=0, j=L->length-1;
	ElemType pivot = L->data[0];					//以L->data[0]为基准 
	while(i<j) {												//从区间两端交替向中间扫描，直到 i=j为止
		while(i<j && L->data[j] > pivot)			//从右向左扫描，找一个小于等于 pivot的 data[j] 
			j--;
		L->data[i] = L->data[j];						//找到这样的 data[j],放到 data[i]处 
		while(i<j && L->data[i] <= pivot)		//从左向右扫描，找一个大于 pivot的data[i] 
			i++;
		L->data[j] = L->data[i];						//找到这样的 data[i],放到 data[j]处 
	}
	L->data[i] = pivot;
}
 
//例2.5 将奇数移到偶数前面   P42  解法一
void move1(Sqlist *&L)
{
	int i=0, j=L->length-1;
	while(i<j)
	{
		while(i<j && L->data[i] % 2 == 1) i++;			//从右向左扫描，找到一个奇数元素 
		while(i<j && L->data[j] % 2 == 0) j--;			//从左向右扫描，找到一个偶数元素
		if(i<j) Swap(L->data[i], L->data[j]);					//若 i<j,将 L->data[i]和 L->data[j]互换 
	}
}

//解法二 
void move2(Sqlist *&L)
{
	int i=-1, j;
	for(j=0; j<=L->length-1; j++) {
		if(L->data[j] % 2 == 1) {								//j 指向奇数时 
			i++;															//奇数区间个数加一 
			if(i!=j) Swap(L->data[i],L->data[j]);			//若 i不等于 j,将 L->data[i]和 L->data[j]交换
		}
	}
} 
 
int main()
{
	Sqlist *L;
	ElemType e;
	printf("顺序表的基本运算如下：\n");
	printf("  (1)初始化顺序表L\n");
	InitList(L);
	printf("  (2)依次插入a,b,c,d,e元素\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("  (3)输出顺序表L:");
	DispList(L);
	printf("  (4)顺序表L的长度:%d\n", ListLength(L));
	printf("  (5)顺序表L为:%s\n", (ListEmpty(L)?"空":"非空"));
	GetElem(L, 3, e);
	printf("  (6)顺序表L的第3个元素:%c\n", e);
	printf("  (7)元素a的位置:%d\n", LocateElem(L,'a'));
	printf("  (8)在第4个元素位置上插入f元素\n");
	ListInsert(L, 4, 'f');
	printf("  (9)输出顺序表L："); DispList(L);
	printf("  (10)删除L的第3个元素\n");
	ListDelete(L, 3, e);
	printf("  (11)输出顺序表L："); DispList(L);
	printf("  (12)释放顺序表L\n"); 
	DestroyList(L);
	system("pause");
	return 1;
 }