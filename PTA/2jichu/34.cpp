#include <iostream>
using namespace std;

int main()
{
	char arr[10][10] = {'0'};
	int n;
	cin >> n;
	
	int i, j;						//输入盘面 
	for(i = 0; i < 2 * n; i++)
		for(j = 0; j < 2 * n; j++)
			cin >> arr[i][j];
	
	int k;							//玩家输入 
	cin >> k;
	
	int x1, y1, x2, y2;
	int false_count = 0;					//错误次数 
	int true_count = 0;
	while(k--) {
		if(false_count == 3) {			//出错达到三次 
			cout << "Game Over";
			return 0;
		}
		
		cin >> x1 >> y1 >> x2 >> y2;
		if(arr[x1-1][y1-1] == arr[x2-1][y2-1] && arr[x1-1][y1-1] != '*') {	//正确 
			arr[x1-1][y1-1] = '*';
			arr[x2-1][y2-1] = '*';
			
			true_count++;
			if(true_count == 2 * n * n) {
				cout << "Congratulations!";
				return 0;
			}
			for(i = 0; i < 2 * n; i++) {
				for(j = 0; j < 2 * n; j++) {
					if(!j) cout << arr[i][j];
					else cout << " " << arr[i][j];
				}
				cout << endl;
			}
			
		}
		else {
			cout << "Uh-oh" << endl;
			false_count++;
		}
	} 

	return 0;
}
