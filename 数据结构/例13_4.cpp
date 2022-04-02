#include <iostream>
using namespace std;
template <typename T>
class Array
{
	int size;
	T *data;
public:
	Array(int);
	~Array();
	void setvalue();
	void dispvalue();
};
template <typename T>
Array<T>::Array(int n)
{
	size = n;
	data = new T[n];
}

template <typename T>
Array<T>::~Array()
{
	delete [] data;
}

template<typename T>
void Array<T>::setvalue()
{
	cout << "(输入" << size << "个数据)" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  第" << i + 1 << "个数据:";
		cin >> data[i];
	}
}

template<typename T>
void Array<T>::dispvalue()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

int main()
{
	Array <char> ac(2);
	cout << "建立一个字符数组";
	ac.setvalue();
	cout << "  数组的内容是:";
	ac.dispvalue();
	Array<int>ad(3);
	cout << "建立一个整数数组";
	ad.setvalue();
	cout << "  数组的内容是:";
	ad.dispvalue();
	system("pause");
	return 1;
}