#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;

typedef struct node
{
    ElemType data;
    struct node * lchild;
    struct node * rchild;
}BTNode;

void CreateBTNode(BTNode *&b, char * str) {
    BTNode * St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL)
                b = p;
            else {
                switch (k) {
                    case 1:
                        St[top]->lchild = p;
                        break;
                    case 2:
                        St[top]->rchild = p;
                        break;
                    default:
                        break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

void DispBTNode(BTNode *b)
{
    if(b != NULL) {
        printf("%c", b->data);
        if(b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTNode(b->lchild);
            if(b->rchild != NULL) printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}

void DestroyBTNode(BTNode *&b)
{
    if(b != NULL) {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}

bool Ancestor(BTNode *b, char x, char path[], int &d)
{
    if(b == NULL)
        return false;
    if(b->data == x) {
        d++;
        path[d] = x;
        return true;
    }
    else if (Ancestor(b->lchild,x,path,d) || Ancestor(b->rchild,x,path,d)) {
        d++;
        path[d] = b->data;
        return true;
    }
    else return false;
}

int main()
{
    BTNode *b;
    char x = 'G';
    char path[MaxSize];
    int d = -1, i;
    char a[] = "A(B(D(,G)),C(E,F))";
    CreateBTNode(b, a);
    printf("二叉树 b: "); DispBTNode(b); printf("\n");
    if(Ancestor(b,x,path,d)) {
        printf("在 b 中找到值为 %c 的结点\n", x);
        printf("从根节点到 %c 的路径: ", x);
        for(i=d; i>=0; i--)
            printf(" %c ", path[i]);
        printf("\n");
    }
    else printf("在 b 中没有找到值为 %c 的结点\n", x);
    printf("销毁树 b\n");
    DestroyBTNode(b);
    return 0;
}