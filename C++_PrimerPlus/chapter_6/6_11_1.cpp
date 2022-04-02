#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    cout << "Enter character; enter @ to quit:\n";
    cin >> ch;
    while(ch != '@') {
        if(islower(ch)) cout << (char)toupper(ch);
        else cout << (char)tolower(ch);
        cin >> ch;
    }
    return 0;
}