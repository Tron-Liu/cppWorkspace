#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct snode {
	char data;						//����ַ�
	struct snode *next;		//ָ����һ�����ָ��
}LinkStrNode;					//�����Ľ������

//���ɴ�
void StrAssign(LinkStrNode *&s, char cstr[]) {
	int i;
	LinkStrNode *r, *p;
	s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = s;								//rʼ��ָ��β���
	for (i = 0; cstr[i] != '/0'; i++) {
		p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;				//β����next����Ϊ��
}

//���ٴ�
void DestroyStr(LinkStrNode *&s) {
	LinkStrNode *pre = s, *p = s->next;		//preָ����p��ǰ�����
	while (p != NULL) {									//ɨ������
		free(pre);												//�ͷ�pre���
		pre = p;												//pre��pͬ������һ�����
		p = pre->next;
	}
	free(pre);						//ѭ������ʱpΪNULL��preָ��β��㣬�ͷ���
}

//���ĸ���
void StrCopy(LinkStrNode *&s, LinkStrNode *t) {
	LinkStrNode *p = t->next, *q, *r;
	s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = s;								//rʼ��ָ��β���
	while (p != NULL) {			//ɨ������t�����н��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;		//��p��㸴�Ƶ�q���
		r->next = q;					//��q������ӵ�����s��ĩβ
		r = q;
		p = p->next;
	}
	r->next = NULL;				//β����next����Ϊ��
}

//�жϴ����
bool StrEqual(LinkStrNode *s, LinkStrNode*t) {
	LinkStrNode *p = s->next, *q = t->next;		//p,q�ֱ�ɨ������s��t�����ݽ��
	while (p != NULL && q != NULL && p->data == q->data) {
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL)			//s��t�ĳ�������Ҷ�Ӧλ�õ��ַ������
		return true;
	else
		return false;
}

//�󴮳�
int StrLength(LinkStrNode *s) {
	int i = 0;									//i�����ۼ����ݽ��ĸ���
	LinkStrNode *p = s->next;		//pָ������s���׽��
	while (p != NULL) {					//ɨ���������ݽ��
		i++;
		p = p->next;
	}
	return i;
}

//��������
LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t) {
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = str;								//rָ��������β���
	while (p != NULL) {			//p����ɨ��s���������ݽ��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;		//��p��㸴�Ƶ�q�����
		r->next = q;					//��q������ӵ�str��ĩβ
		r = q;
		p = p->next;
	}
	p = t->next;	
	while (p != NULL) {			//p����ɨ��t���������ݽ��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;		//��p��㸴�Ƶ�q�����
		r->next = q;					//��q������ӵ�str��ĩβ
		r = q;
		p = p->next;
	}
	r->next = NULL;				//β����next����Ϊ��
	return str;							//���ؽ����
}

//���Ӵ�
LinkStrNode *SubStr(LinkStrNode *s, int i, int j) {
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL;				//�ý����strΪ�մ�
	r = str;									//rָ��str��β���
	if (i<=0 || i>StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;							//��������ȷʱ���ؿմ�
	for (k = 1; k < i; k++)			//pָ������s�ĵ�i�����ݽ��
		p = p->next;
	for (k = 1; k <= j; k++) {		//��s�Ĵӵ�i����㿪ʼ��j����㸴�Ƶ�str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;					//β����next���ÿ�
	return str;
}

//�Ӵ��Ĳ���
LinkStrNode *InsStr(LinkStrNode *s, int i, LinkStrNode *t) {
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL;						//�ý����strΪ�մ�
	r = str;											//rָ��str��β���
	if (i<=0 || i>(StrLength(s) + 1))		//��������ȷʱ���ؿմ�
		return str;
	for (k = 1; k < i; k++) {					//��s��ǰi����㸴�Ƶ������str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	while (p1 != NULL) {					//��t�����н�㸴�Ƶ�str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL) {						//��s��ʣ�µĽ�㸴�Ƶ�str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;							//β����next����Ϊ��
	return str;
}

//�Ӵ���ɾ��
LinkStrNode *DelStr(LinkStrNode*s, int i, int j) {
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL;				//�ý����strΪ�մ�
	r = str;									//rָ��������β���
	if (i<=0 || i>StrLength(s) || j<0 || i + j - 1 > StrLength(s))
		return str;							//�������󷵻ؿմ�
	for (k = 1; k < i-1; k++) {		//��s��ǰi-1����㸴�Ƶ�str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)			//��p��next��j�����
		p = p->next;
	while (p != NULL) {				//��p��㼰���Ľ�㸴�Ƶ�str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;					//β����next���ÿ�
	return str;
}

//�Ӵ������
LinkStrNode *RepStr(LinkStrNode *s, int i, int j, LinkStrNode *t) {
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL;					//����strΪ�մ�
	r = str;										//rָ������str��β���
	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;								//��������ȷʱ���ؿմ�
	for (k = 0; k < i - 1; i++) {		//��s��ǰi-1�����ݽ�㸴�Ƶ�str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)				//��p��next��j�����
		p = p->next;
	while (p1 != NULL) {				//��t�����н�㸴�Ƶ�str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL) {					//��s��ʣ�µĽ�㸴�Ƶ�str��
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;						//β����next����Ϊ��
	return str;
}

//�����
void DisStr(LinkStrNode *s) {
	LinkStrNode *p = s->next;		//pָ��s���׽��
	while (p != NULL) {					//��pɨ������s���������ݽ��
		printf("%c", p->data);			//���p���ֵ
		p = p->next;
	}
	printf("\n");
}