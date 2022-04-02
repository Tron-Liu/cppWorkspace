#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	int rabbit = 0, tor = 0; 
	while(t) {
		if(t >= 10) { 					//剩余时间大于十分钟，
			if(rabbit <= tor) {			//兔子没有超过乌龟 
				rabbit += 10 * 9;
				tor += 10 * 3;
				t -= 10;
			}
			else{						//兔子超过乌龟, 兔子休息30分钟 
				if(t >= 30) {			//剩余时间大于30分钟 
					tor += 3 * 30;
					t -= 30; 
				}
				else {					//剩余时间少于30分钟 
					tor += 3 * t;
					t = 0;
				}
			}
		} 
		else {							//剩余时间小于十分钟 
			if(rabbit <= tor) {			//兔子没有超过乌龟 
				rabbit += t * 9;
				tor += t * 3;
			}
			else{						//兔子超过乌龟 
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
