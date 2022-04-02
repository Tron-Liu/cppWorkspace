#include <iostream>
#define MaxSize 102
using namespace std;

int main()
{
	int A[MaxSize][MaxSize] = {0};
	int B[MaxSize][MaxSize] = {0};

	int Ra, Ca, Rb, Cb;
	cin >> Ra >> Ca;
	
	int i, j, k;
	for(i = 0; i < Ra; i++) {
		for(j = 0; j < Ca; j++) {
			cin >> A[i][j];
		}
	}
	
	cin >> Rb >> Cb;
	for(i = 0; i < Rb; i++) {
		for(j = 0; j < Cb; j++) {
			cin >> B[i][j];
		}
	}
	
	if(Ca != Rb) {
		cout << "Error: " << Ca << " != " << Rb;
		return 0;
	}
	
	int C[MaxSize][MaxSize] = {0};
	for(i = 0; i < Ra; i++) {
		for(j = 0; j < Cb; j++) {
			for(k = 0; k < Ca; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	cout << Ra << " " << Cb << endl;
	for(i = 0; i < Ra; i++) {
		for(j = 0; j < Cb; j++) {
			printf("%d", C[i][j]);
			if(j != Cb-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
