#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
}Node;

//根据a，创建链表 
void create(int *a, Node *head)
{
	int i = 0;
	Node *q;
	q = head;
	while (a[i] != -1) {
		Node *p = (Node *)malloc(sizeof(node));
		p->val = a[i];

		q->next = p;
		q = p;
		i++;
	}
	q->next = NULL;
}

void destroy(Node *head)
{
	Node *p;
	p = head->next;
	while (p != NULL) {
		free(head);
		head = p;
		p = head->next;
	}
	free(head);
}

void interSect(Node *S1, Node *S2)
{
	Node *p1, *p2;
	p1 = S1->next;
	p2 = S2->next;

	Node *q = S1;

	Node *pre;
	while (p1 != NULL && p2 != NULL) {
		if (p1->val != p2->val) {
			if (p1->val < p2->val) {
				pre = p1;
				p1 = p1->next;
				free(pre);
			}
			else {
				pre = p2;
				p2 = p2->next;
				free(pre);
			}
		}
		else {
			q->next = p1;
			q = q->next;
            
            p1 = p1->next;
			pre = p2;
			p2 = p2->next;
			free(pre);
		}
	}

	if (p1 != NULL) destroy(p1);
	if (p2 != NULL) destroy(p2);

	q->next = NULL;
	free(S2);
}

void print(Node *head)
{
	if (head->next == NULL) {
		printf("NULL");
		return;
	}
	Node * p;
	p = head->next;
	while (p != NULL) {
		printf("%d", p->val);
		if (p->next != NULL) printf(" ");
		p = p->next;
	}
}

int a[10000000];

int main()
{
	int x, i = 0;
	scanf("%d", &x);
	while (x != -1) {
		a[i] = x;
		i++;
		scanf("%d", &x);
	}
	a[i] = -1;
	Node* S1 = (Node *)malloc(sizeof(Node));
	S1->next = NULL;
	create(a, S1);

	scanf("%d", &x);
	i = 0;
	while (x != -1) {
		a[i] = x;
		i++;
		scanf("%d", &x);
	}
	a[i] = -1;
	Node* S2 = (Node *)malloc(sizeof(Node));
	S2->next = NULL;
	create(a, S2);

	interSect(S1, S2);
	print(S1);

	destroy(S1);
	return 0;
}
