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
	cout << "(����" << size << "������)" << endl;
	for (int i = 0; i < size; i++) {
		cout << "  ��" << i + 1 << "������:";
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
	cout << "����һ���ַ�����";
	ac.setvalue();
	cout << "  �����������:";
	ac.dispvalue();
	Array<int>ad(3);
	cout << "����һ����������";
	ad.setvalue();
	cout << "  �����������:";
	ad.dispvalue();
	system("pause");
	return 1;
}