#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 32767
#define W 5
#define FILEN 20
#define MAXK 5

typedef struct {
	int no;
	int tag;
	int num;
	char fn[10];
}FInfo;

FILE * fp[FILEN];
int m;
int k;

int Partition(int a[], int s, int t) {
    int i = s, j = t;
    int tmp = a[s];
    while (i != j)
    {
        while (j > i && a[j] >= tmp)
            j--;
        a[i] = a[j];
        while (i < j && a[i] <= tmp)
            i++;
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort(int a[], int s, int t) {
	int i;
    if (s < t)
    {
        i = Partition(a, s, t);
        QuickSort(a, s, i-1);
        QuickSort(a, i+1, t);
    }
}

int Partition1(FInfo a[], int s, int t) {
    int i = s, j = t;
    FInfo tmp = a[s];
    while (i != j)
    {
        while (j > i && a[j].num >= tmp.num)
            j--;
        a[i] = a[j];
        while (i < j && a[i].num <= tmp.num)
            i++;
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort1(FInfo a[], int s, int t) {
	int i;
    if (s < t)
    {
        i = Partition1(a, s, t);
        QuickSort1(a, s, i-1);
        QuickSort1(a, i+1, t);
    }
}

void CreateFilename(char * fname, int i) {
	char fno[3];
	itoa(i, fno, 10);
	strcpy(fname, "F");
	strcat(fname, fno);
	strcat(fname, ".dat");
}

void CreateFile(int a[], int n) {
	int i, e = INF;
	FILE * ifp;
	ifp = fopen("Fin.dat", "wb");
	for(i = 0; i < n; i++)
		fwrite(&a[i], sizeof(int), 1, ifp);
	fclose(ifp);
}

void CreateInitFile(FInfo fi[], int n) {
	FILE * ifp;
	int i, j, e = INF;
	int b[W];
	char fname[10];
	ifp = fopen("Fin.dat", "rb");
	m = 0;
	for (i = 0; i < (n/W); i++)	{
		fread(b, sizeof(int), W, ifp);
		QuickSort(b, 0, W-1);
		CreateFilename(fname, i);
		fp[i] = fopen(fname, "wb");
		fwrite(b, sizeof(int), W, fp[i]);
		fwrite(&e, sizeof(int), W, fp[i]);
		fclose(fp[i]);
		fi[m].num = W; fi[m].tag = 0;
		fi[m].no = m; strcpy(fi[m].fn, fname);
		m++;
	}
	j = n - m * W;
	if(j > 0) {
        fread(b, sizeof(int), j, ifp);
        QuickSort(b, 0, j-1);
        CreateFilename(fname, i);
        fp[i] = fopen(fname, "wb");
        fwrite(b, sizeof(int), j, fp[i]);
        fwrite(&e, sizeof(int), 1, fp[i]);
        fclose(fp[i]);
        fi[m].num = j; fi[m].tag = 0;
		fi[m].no = m; strcpy(fi[m].fn, fname);
		m++;
    }
    printf("(1)生成的初始归并段个数 = %d, 段号从 0 ~ %d\n", m, m-1);
    for (i = 0; i < m; i++) {
        printf("\t段号: %d, 记录个数: %d\n", fi[i].no, fi[i].num);
    }
    fclose(ifp);
}

int Min(int a[], int &minv) {
    int i, minno;
    minv = a[0]; minno = 0;
    for (i = 1; i < k; i++) {
        if (a[i] < minv) {
            minv = a[i];
            minno = i;
        }
    }
    return minno;
}

void Insert(FInfo fi[], char * fname, int length) {         //将新归并段信息有序插入到 fi 中
    int i = 0, j;
    while (i < m && fi[i].num < length) {
        i++;
    }
    for (j = m; j >= i; j--) {
        fi[j+1] = fi[j];
    }
    fi[i].num = length; fi[i].no = m;
    fi[i].tag = 0; strcpy(fi[i].fn, fname);
    m++;
}

void Merge(FInfo mergek[], FInfo fi[]) {
    FILE * nfp;
    int i, minno, minv = 0, length = 0, e = INF;
    bool stop;
    int a[MAXK];
    char fname[10];
    CreateFilename(fname, m);
    nfp = fopen(fname, "wb");
    for(i = 0; i < k; i++) {
        fp[i] = fopen(mergek[i].fn, "rb");
        length += mergek[i].num;
    }
    for (i = 0; i < k; i++) {
        fread(&a[i], sizeof(int), 1, fp[i]);
    }
    while (true)
    {
        stop = true;
        for (i = 0; i < k; i++) {
            if(a[i] != INF) {
                stop = false;
                break;
            }
        }
        if(!stop) {
            minno = Min(a, minv);
            fwrite(&minv, sizeof(int), 1, nfp);
            fread(&a[minno], sizeof(int), 1, fp[minno]);
        }
        else break;
    }
    
}