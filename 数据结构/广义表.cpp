#include <iostream>
typedef char ElemType;

typedef struct lnode {
	int tag;									//������ͱ�ʶ
	union {
		ElemType data;				//���ԭ��ֵ
		struct lnode * sublist;		//ָ���ӱ��ָ��
	}val;
	struct lnode *link;				//ָ����һ��Ԫ��
}GLNode;									//�����Ľ������

//�������㷨��Ʒ���1
//����1�ȴ���һ��Ԫ�أ��ٴ�����Ԫ��
void fun1(GLNode *g) {					//gΪ�����ͷ���
	GLNode *g1 = g->val.sublist;		//g1ָ���һ��Ԫ��
	while (g1 != NULL) {					//Ԫ��δ������ʱѭ��
		if (g1->tag == 1)						//Ϊ�ӱ�ʱ
			fun1(g1);								//�ݹ鴦���ӱ�
		else
			//ԭ�Ӵ������;						//ʵ��ԭ�Ӳ���
		g1 = g1->link;							//�����ֵ�
	}
}

//�������㷨��Ʒ���2
//����2�ȴ���data/sublist�򣬼�Ԫ�ز��֣��ٴ���link�򣬼��ֵܲ���
void fun2(GLNode *g) {			//gΪ�������ָ��
	if (g != NULL) {
		if (g->tag == 1)				//Ϊ�ӱ�ʱ
			fun2(g->val.sublist);	//�ݹ鴦����Ԫ��
		else									//Ϊԭ��ʱ
			//ԭ�Ӵ������;				//ʵ��ԭ�Ӳ���
		fun2(g->link);					//�ݹ鴦�����ֵ�
	}
}

//������ĳ���
int GLLength(GLNode *g) {		//������g�ĳ���
	int n = 0;								//�ۼ�Ԫ�ظ�������ʼֵΪ0
	GLNode *g1;
	g1 = g->val.sublist;				//g1ָ������ĵ�һ��Ԫ��
	while (g1 != NULL) {			//ɨ������Ԫ�ؽ��
		n++;									//Ԫ�ظ�����1
		g1 = g1->link;
	}
	return n;								//����Ԫ�ظ���
}

//����������
int GLDepth(GLNode *g) {
	GLNode *g1;
	int maxed = 0, dep;
	if (g->tag == 0)					//Ϊԭ��ʱ����0
		return 0;
	g1 = g->val.sublist;				//g1ָ���һ��Ԫ��
	if (g1 == NULL)					//Ϊ�ձ�ʱ����1
		return 1;
	while (g1 != NULL) {			//�������е�ÿһ��Ԫ��
		if (g1->tag == 1) {			//Ԫ��Ϊ�ӱ�����
			dep = GLDepth(g1);		//�ݹ��������ӱ�����
			if (dep > maxed)			//maxedΪͬһ����ӱ�����ȵ����ֵ
				maxed = dep;
		}
		g1 = g1->link;					//ʹg1ָ����һ��Ԫ��
	}
	return maxed + 1;				//���ر�����
}

//��������
void DispGL(GLNode *g) {
	if (g != NULL) {									//��Ϊ���ж�
		if (g->tag == 0)							//g��Ԫ��Ϊԭ��ʱ
			printf("%c", g->val.data);			//���ԭ��ֵ
		else {											//g��Ԫ��Ϊ�ӱ�ʱ
			printf("(");									//���  ' ( '
			if (g->val.sublist == NULL)		//Ϊ�ձ�ʱ
				printf("#");
			else											//Ϊ�ǿձ�ʱ
				DispGL(g->val.sublist);		//�ݹ�����ӱ�
			printf(")");									//���  ' ) '
		}
		if (g->link != NULL) {
			printf(",");
			DispGL(g->link);						//�ݹ����g���ֵ�
		}
	}
}