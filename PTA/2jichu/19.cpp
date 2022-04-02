#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//����ʱ�� 
int calcu_time(int h1, int m1, int h2, int m2);

struct Record		//�����뻹���¼ 
{
	int book_id;	//��� 
	char key[2];	//��ֵ 
	int h;			//Сʱ 
	int m;			//���� 
};

int main()
{
	int n;
	cin >> n;
	
	int days = 0;		
	int time[11] = {0};		//ʱ�� 
	int count[11] = {0};	//������� 
	Record b;
	vector<Record> v;
	
	do {
		scanf("%d %s %d:%d", &b.book_id, &b.key, &b.h, &b.m);
		if(b.book_id)
		{
			if(!strcmp(b.key, "S"))		//���� 
			{
				vector<Record>::iterator it;
				it = v.begin();
				for(it; it != v.end(); it++)
				{
					if(it->book_id == b.book_id)
					{
						it->book_id = 1001;			//���� 
					}
				}
				v.push_back(b);
			}
			else						//���� 
			{
				vector<Record>::iterator it;
				it = v.begin();
				for(it; it != v.end(); it++)
				{
					if(it->book_id == b.book_id)
					{
						time[days] += calcu_time(it->h, it->m, b.h, b.m);
						count[days]++;
						it->book_id = 1001;			//��ʾ�Ѿ����� 
					}
				}
			}
		}
		else				//һ����� 
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
