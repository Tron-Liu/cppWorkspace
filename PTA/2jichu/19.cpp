#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//计算时长 
int calcu_time(int h1, int m1, int h2, int m2);

struct Record		//借书与还书记录 
{
	int book_id;	//书号 
	char key[2];	//键值 
	int h;			//小时 
	int m;			//分钟 
};

int main()
{
	int n;
	cin >> n;
	
	int days = 0;		
	int time[11] = {0};		//时长 
	int count[11] = {0};	//借书次数 
	Record b;
	vector<Record> v;
	
	do {
		scanf("%d %s %d:%d", &b.book_id, &b.key, &b.h, &b.m);
		if(b.book_id)
		{
			if(!strcmp(b.key, "S"))		//借书 
			{
				vector<Record>::iterator it;
				it = v.begin();
				for(it; it != v.end(); it++)
				{
					if(it->book_id == b.book_id)
					{
						it->book_id = 1001;			//重置 
					}
				}
				v.push_back(b);
			}
			else						//还书 
			{
				vector<Record>::iterator it;
				it = v.begin();
				for(it; it != v.end(); it++)
				{
					if(it->book_id == b.book_id)
					{
						time[days] += calcu_time(it->h, it->m, b.h, b.m);
						count[days]++;
						it->book_id = 1001;			//表示已经计算 
					}
				}
			}
		}
		else				//一天结束 
		{
			v.clear();
			days++; 
		}
	}while(days < n);
	
	for(int i = 0; i < n; i++)
	{
		if(count[i])
			cout << count[i] << " " << (int)(1.0*time[i] / count[i] + 0.5) << endl;
		else
			cout << count[i] << " " << time[i] << endl;
	}
	return 0;
}

int calcu_time(int h1, int m1, int h2, int m2)
{
	int time1 = h1 * 60 + m1;
	int time2 = h2 * 60 + m2;
	
	return time2 - time1;
}
