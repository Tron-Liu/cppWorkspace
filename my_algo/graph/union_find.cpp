/**
* @file: union_find.cpp
* @author: Tron-Liu (Tron-Liu@foxmail.com)
* @brief: a algorithm program about union find 
* @date: 2022-08-12 20:40
**/

#include <iostream>

int my_find(int a, int b); 
void my_union(int a, int b); 

int main()
{
	vector<int> node(10, 0);
	for (int i = 0; i < node.size(); i++)
		node[i] = i;

  return 0;
}

int my_find(int num, const vector<int>& node) {
	int root = num;
	while (node[num] != root) {
		root = node[root];
	}

	return root;
}

void my_union(int a, int b) {
}
