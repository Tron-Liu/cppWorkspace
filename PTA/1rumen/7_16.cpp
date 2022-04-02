#include <iostream>
using namespace std;

int main()
{
	int start, arrive;
	cin >> start >> arrive;
	
	int start_hour, start_minute, arrive_hour, arrive_minute;	
	
	start_hour = start / 100;
	start_minute = start % 100;
	
	arrive_hour = arrive / 100;
	arrive_minute = arrive % 100;
	
	int hour, minute;
	if(arrive_minute < start_minute) {
		minute = arrive_minute - start_minute + 60;
		hour = arrive_hour - start_hour - 1;
	}
	else {
		minute = arrive_minute - start_minute;
		hour = arrive_hour - start_hour;
	}
	printf("%02d:%02d", hour, minute);
	
	return 0;
}
