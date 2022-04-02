#include <stdio.h>
#define threshold 0.01 		 //阈值

double fun(double a3, double a2, double a1, double a0, double x);

int main()
{
	double a3, a2, a1, a0;	//系数
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);

	double a, b;			//区间端点
	scanf("%lf %lf", &a, &b);

	double len = b - a; 	//区间长度

	double fa, fb, fc, c;
	while(len >= threshold) {
		fa = fun(a3, a2, a1, a0, a);
		fb = fun(a3, a2, a1, a0, b);

        if(fa == 0) {
            printf("%.2f", a);
            return 0;
        }
        
        if(fb == 0) {
            printf("%.2f", b);
            return 0;
        }
        
		c = (a + b) / 2;
		if(fa * fb < 0) {
			fc = fun(a3, a2, a1, a0, c);
            if(fc == 0) {
                printf("%.2f", c);
                return 0;
            }
			else if(fa * fc > 0) a = c;
			else b = c;
		}
        len = b - a;
	}
	c = (a + b) / 2;
	printf("%.2f", c);
	return 0;
}

double fun(double a3, double a2, double a1, double a0, double x) {
	double result = a3 * x * x * x + a2 * x * x + a1 * x + a0;
	return result;
}


