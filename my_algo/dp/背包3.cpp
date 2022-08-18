#include <iostream>
#include <vector>
using namespace std;

int w[1002];
struct Goods {
	int weight;		//物品重量 
	int pos;				//物品在哪个箱子 
};

int main()
{
	for(int i = 0; i < 1002; i++)		//初始化全局数组 
		w[i] = 100;
		
	int n;
	cin >> n;
	
	Goods goods[1002];
	for(int i = 0; i < n; i++)
		cin >> goods[i].weight;
	
	int i, j;
	for(i = 0; i < n; i++) {		//循环物品 
		for(j = 0; j < n; j++) {	//循环箱子 
			if(w[j] >= goods[i].weight) {
				goods[i].pos = j;					//物品定位 
				w[j] = w[j] - goods[i].weight;	//箱子减去重量 
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
