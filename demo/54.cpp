#include <iostream>
#include <vector>
using namespace std;

int w[1002];
struct Goods {
	int weight;		//��Ʒ���� 
	int pos;				//��Ʒ���ĸ����� 
};

int main()
{
	for(int i = 0; i < 1002; i++)		//��ʼ��ȫ������ 
		w[i] = 100;
		
	int n;
	cin >> n;
	
	Goods goods[1002];
	for(int i = 0; i < n; i++)
		cin >> goods[i].weight;
	
	int i, j;
	for(i = 0; i < n; i++) {		//ѭ����Ʒ 
		for(j = 0; j < n; j++) {	//ѭ������ 
			if(w[j] >= goods[i].weight) {
				goods[i].pos = j;					//��Ʒ��λ 
				w[j] = w[j] - goods[i].weight;	//���Ӽ�ȥ���� 
				break;
			}
		}
	}
	
	int count = 0;
	while(w[count] < 100) count++;
		
	for(int j = 0; j < n; j++)
		cout << goods[j].weight << " " << goods[j].pos+1 << endl;

	cout << count;
	return 0;	
} 
