#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	int rabbit = 0, tor = 0; 
	while(t) {
		if(t >= 10) { 					//ʣ��ʱ�����ʮ���ӣ�
			if(rabbit <= tor) {			//����û�г����ڹ� 
				rabbit += 10 * 9;
				tor += 10 * 3;
				t -= 10;
			}
			else{						//���ӳ����ڹ�, ������Ϣ30���� 
				if(t >= 30) {			//ʣ��ʱ�����30���� 
					tor += 3 * 30;
					t -= 30; 
				}
				else {					//ʣ��ʱ������30���� 
					tor += 3 * t;
					t = 0;
				}
			}
		} 
		else {							//ʣ��ʱ��С��ʮ���� 
			if(rabbit <= tor) {			//����û�г����ڹ� 
				rabbit += t * 9;
				tor += t * 3;
			}
			else{						//���ӳ����ڹ� 
				tor += t * 3; 
			}
			t = 0; 
		}
	}
	if(rabbit > tor) printf("^_^ %d", rabbit);
	else if(rabbit < tor) printf("@_@ %d", tor);
	else printf("-_- %d", tor);
	return 0; 
}
