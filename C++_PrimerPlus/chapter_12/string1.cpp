#include <cstring>
#include "string1.h"

using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char(len + 1);
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const String &);
String & operator=(const char *);
char & operator[](int i);
const char & operator[](int i) const;

friend bool operator<(const String &st, const String &st2);
friend bool operator>(const String &st1, const String &st2);
friend bool operator==(const String &st, const String &st2);
friend ostream & operator<<(ostream &os, const String & st);
friend istream & operator>>(istream &is, String & st);