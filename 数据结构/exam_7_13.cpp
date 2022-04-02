/*������������ö������洢�ṹ�����һ���㷨������� b �н��ֵΪ x �Ľ��Ĳ��*/

#include "BTree.h"
#include "CreateBTree.h"
#include "DispBTree.h"
#include "DestroyBTree.h"
int Level(BTNode *b, ElemType x, int h) {
	int l;
	if (b == NULL) return 0;
	else if (b->data == x) return h;
	else {
		l = Level(b->lchild, x, h + 1);
		if (l != 0) return l;
		else
			return (Level(b->rchild, x, h + 1));
	}
}

int main()
{
	BTNode *b;
	int h;
	ElemType x;
	CreateBTree(b, "A(B(D(,G)),C(E,F))");
	printf("b: "); DispBTree(b); printf("\n");
	printf("���ֵ: ");
	scanf("%c", &x);
	h = Level(b, x, 1);
	if (h == 0)  printf("b�в�����%c���\n", x);
	else printf("��b��%c���Ĳ��Ϊ%d\n", x, h);
	DestroyBTree(b);
	system("pause");
	return 1;
}