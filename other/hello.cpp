#include <iostream>

int max(int x, int y) {
	return x >= y ? x : y;
}

int main ()
{
	int weight[] = {4, 3, 1};		// 物品的重量
	int value[] = {300, 200, 150};	// 物品的价值
	int capacity = 4;				// 背包的容量
	int* dp = new int[capacity + 1]();

	for(int i = 0; i < 3; i++) {
		for(int j = 1; j <= capacity; j++) {
			if(j >= weight[i])
				dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}
	std::cout << dp[capacity] << std::endl;
	return 0;
}

