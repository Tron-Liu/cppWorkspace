#include <stdio.h>
#include <memory>

int main()
{
	std::shared_ptr<int> foo = std::make_shared<int> (10);

	return 0;
} 
