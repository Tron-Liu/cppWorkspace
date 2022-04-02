#include <stdio.h>

void disp(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

//�ݹ�
void BubbleSort(int a[], int n, int i)
{
    int j, tmp;
    bool exchange;
    if(i == n-1) return;                        //����ݹ��������
    else {
        exchange = false;                       //�� exchange Ϊ false
        for (j = n-1; j > i; j--)   
        {
            if(a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                exchange = true;
            }
        }
       if (exchange == false) return;
       else BubbleSort(a, n, i+1);
    }
}

int main()
{
    int n = 10;
    int a[] = {1,2,5,5,7,10,6,9,4,3,8};
    printf("����ǰ: ");
    disp(a,n);
    printf("�����: ");
    BubbleSort(a, n, 0);
    disp(a,n);
}