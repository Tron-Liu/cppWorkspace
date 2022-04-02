#pragma once
#include "Á´´®.h"
//Àý4.3
void Repl(LinkStrNode *&s) {
	LinkStrNode *p = s->next, *q;
	bool find = false;
	while (p != NULL && p->next != NULL && !find) {		//²éÕÒ'ab'×Ó´®
		if (p->data == 'a'&&p->next->data == 'b') {				//ÕÒµ½Ê±
			p->data = 'x';															//Ìæ»»
			p->next->data = 'z';
			q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = true;
		}
		else							//ÉÐÎ´ÕÒµ½Ê±¼ÌÐø²éÕÒ
			p = p->next;
	}
}
