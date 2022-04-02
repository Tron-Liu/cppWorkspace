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

//��2.3 ɾ��˳�����ֵΪ x��Ԫ��  �ⷨһ  P39
void delNote1(Sqlist *&L, ElemType x)
{
	int k = 0;												//k��¼������x��Ԫ�صĸ�������Ҫ���뵽L�е�Ԫ�ظ��� 
	for(int i=0; i<L->length; i++) {       
		if(L->data[i] != x) {							//����ǰԪ�ز�Ϊx��������뵽L�� 
			L->data[k] = L->data[i];
			k++;												//����һ��Ԫ�أ�Ԫ�ظ���k��һ 
		}
	}
	L->length = k;										//L���ȵ���k 
}

 //��2.3  �ⷨ��  P39
void delNode2(Sqlist *&L, ElemType x)
{

	int k = 0;												//k��¼����x��Ԫ�ظ��� 
	for(int i=0; i<L->length; i++) {       
		if(L->data[i] == x)							//����ǰԪ�ص���x��k��һ 
			k++;
		else
			L->data[i-k] = L->data[i];			//�������ڣ�����λ��ǰ�� k��λ�� 
	}
	L->length = L->length - k;					//L���ȵ���ԭ�����ȼ�ȥ k 
}

//��2.4 p40  �ⷨһ 
int partition1(Sqlist *& L)
{
	int i=0, j=L->length-1;
	ElemType pivot = L->data[0];					//��data[0]Ϊ��׼ 
	while(i<j) {												//���������˽������м�ɨ�裬ֱ�� i=jΪֹ 
		while(i<j && L->data[i] <= pivot)		//��������ɨ�� ����һ������ pivot���� 
			i++;
		while(i<j && L->data[j] > pivot)			//��������ɨ�裬��һ��С�ڵ��� pivot���� 
			j--;
		if(i < j) 
			Swap(L->data[i], L->data[j]);			//�� L->data[i]�� L->data[j]���� 
	}
	Swap(L->data[i], pivot);							// �� L->data[i]�� L->data[0]���� 
 } 
 
//��2.4 p40  �ⷨ�� �˽ⷨ���� 
int partition2(Sqlist *&L)
{
	int i=0, j=L->length-1;
	ElemType pivot = L->data[0];					//��L->data[0]Ϊ��׼ 
	while(i<j) {												//���������˽������м�ɨ�裬ֱ�� i=jΪֹ
		while(i<j && L->data[j] > pivot)			//��������ɨ�裬��һ��С�ڵ��� pivot�� data[j] 
			j--;
		L->data[i] = L->data[j];						//�ҵ������� data[j],�ŵ� data[i]�� 
		while(i<j && L->data[i] <= pivot)		//��������ɨ�裬��һ������ pivot��data[i] 
			i++;
		L->data[j] = L->data[i];						//�ҵ������� data[i],�ŵ� data[j]�� 
	}
	L->data[i] = pivot;
}
 
//��2.5 �������Ƶ�ż��ǰ��   P42  �ⷨһ
void move1(Sqlist *&L)
{
	int i=0, j=L->length-1;
	while(i<j)
	{
		while(i<j && L->data[i] % 2 == 1) i++;			//��������ɨ�裬�ҵ�һ������Ԫ�� 
		while(i<j && L->data[j] % 2 == 0) j--;			//��������ɨ�裬�ҵ�һ��ż��Ԫ��
		if(i<j) Swap(L->data[i], L->data[j]);					//�� i<j,�� L->data[i]�� L->data[j]���� 
	}
}

//�ⷨ�� 
void move2(Sqlist *&L)
{
	int i=-1, j;
	for(j=0; j<=L->length-1; j++) {
		if(L->data[j] % 2 == 1) {								//j ָ������ʱ 
			i++;															//�������������һ 
			if(i!=j) Swap(L->data[i],L->data[j]);			//�� i������ j,�� L->data[i]�� L->data[j]����
		}
	}
} 
 
int main()
{
	Sqlist *L;
	ElemType e;
	printf("˳���Ļ����������£�\n");
	printf("  (1)��ʼ��˳���L\n");
	InitList(L);
	printf("  (2)���β���a,b,c,d,eԪ��\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("  (3)���˳���L:");
	DispList(L);
	printf("  (4)˳���L�ĳ���:%d\n", ListLength(L));
	printf("  (5)˳���LΪ:%s\n", (ListEmpty(L)?"��":"�ǿ�"));
	GetElem(L, 3, e);
	printf("  (6)˳���L�ĵ�3��Ԫ��:%c\n", e);
	printf("  (7)Ԫ��a��λ��:%d\n", LocateElem(L,'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(L, 4, 'f');
	printf("  (9)���˳���L��"); DispList(L);
	printf("  (10)ɾ��L�ĵ�3��Ԫ��\n");
	ListDelete(L, 3, e);
	printf("  (11)���˳���L��"); DispList(L);
	printf("  (12)�ͷ�˳���L\n"); 
	DestroyList(L);
	system("pause");
	return 1;
 }