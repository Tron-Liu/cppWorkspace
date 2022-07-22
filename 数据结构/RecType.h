#include "Swap.h"

typedef int KeyType; //定义关键字类型为int
typedef int InfoType;
typedef struct //元素类型
{
	KeyType key;   //关键字项
	InfoType data; //其他数据项，类型为InfoType
} RecType;		   //排序元素的类型