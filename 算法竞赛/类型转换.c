#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
void to_string(string &result, const T &t)
{
	ostringstream oss;
	oss << t;
	result = oss.str();
}

template <class out_type, class in_value>
out_type convert(const in_value &t)
{
	stringstream stream;

	stream << t;
	out_type result;
	stream >> result;

	return result;
}

int main()
{
	string s1, s2, s3;

	to_string(s1, 10.5);
	to_string(s2, 123);
	to_string(s3, true);
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl;

	double d;
	string salary;
	string s = "12.56";

	d = convert<double>(s);
	salary = convert<string>(9000.0);

	cout << d << endl
		 << salary << endl;

	return 0;
}