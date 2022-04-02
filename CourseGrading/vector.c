#include <stdio.h>

typedef struct
{
	int x;
	int y;
}myVector;

//向量加法
myVector vectorAdd(myVector A, myVector C)
{
	myVector temp;
	temp.x = A.x + C.x;
	temp.y = A.y + C.y;
	return temp;
}

//向量旋转
myVector vectorRotate(myVector A)
{
	myVector temp;
	temp.x = A.y;
	temp.y = -A.x;
	return temp;
}

//判断两个向量是否相等
//如果 A 的横坐标或纵坐标比 B 大，则算 A > B
int vectorEqual(myVector A, myVector B)
{
	if (A.x == B.x && A.y == B.y) return 1;		//相等返回 1
	else if (A.x > B.x || A.y > B.y) return 2;			//若 A > B，返回 2
	else return 0;												//否则返回 0
}

//输出向量
void vectorPrint(myVector A)
{
	printf("%d %d", A.x, A.y);
}

int main()
{
	myVector A, B, C;
	scanf("%d %d", &A.x, &A.y);
	scanf("%d %d", &B.x, &B.y);
	scanf("%d %d", &C.x, &C.y);

	myVector temp;
	int i = 0;

    if (A.x + A.y + C.x + C.y == 0 && B.x + B.y != 0) {
		printf("NO");
		return 0;
	}

	while (vectorEqual(A, B) == 0)
	{
		//旋转一次
		temp = vectorRotate(A);
		if (vectorEqual(A, temp) == 1) {		//旋转后为本身，则令 A 加上 C 
			A = vectorAdd(A, C);
			continue;
		}
		
		//相加一次
		temp = vectorAdd(temp, C);
		i++;
		if (vectorEqual(temp, B) == 0) {
			if (i % 4 == 0) A = vectorAdd(A, C);
		}
		else {
			A = temp;
			break;
		}
	}

	if (vectorEqual(A, B) == 1)
		printf("YES");
	else if (vectorEqual(A, B) == 2)
		printf("NO");
	return 0;
}