#pragma once
#include "����.h"
//��4.3
void Repl(LinkStrNode *&s) {
	LinkStrNode *p = s->next, *q;
	bool find = false;
	while (p != NULL && p->next != NULL && !find) {		//����'ab'�Ӵ�
		if (p->data == 'a'&&p->next->data == 'b') {				//�ҵ�ʱ
			p->data = 'x';															//�滻
			p->next->data = 'z';
			q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = true;
		}
		else							//��δ�ҵ�ʱ��������
			p = p->next;
	}
}
