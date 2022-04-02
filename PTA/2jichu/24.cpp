#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
struct people{
	char name[8];
	int num;
};

typedef struct people Person;
int main()
{
	int N;
	scanf("%d", &N);
	
	Person *p = (Person *)malloc(sizeof(Person) * N);
	
	int sum = 0;
	for(int i = 0; i < N; i++) {
		scanf("%s %d", (p+i)->name, &(p+i)->num);
		sum += (p+i)->num;
	}
	
	double ave = (double)sum / N / 2;
	//printf("%lf\n", ave);
	
	double min = 200.0;					//记录最小的差值 
	int j = 0;						//记录最小的 
	for(int i = 0; i < N; i++) {
		//printf("%d\n", abs((p+i)->num - ave));
		if(min > fabs((p+i)->num - ave)) {
			
			min = fabs((p+i)->num - ave);
			j = i;
		}
	}
	
	printf("%d %s", (int)ave, (p+j)->name);
	free(p);
	return 0;
}
