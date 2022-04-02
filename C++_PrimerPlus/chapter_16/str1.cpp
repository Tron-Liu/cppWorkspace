#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string one("Lottery Winner!");
    cout << one << endl;

    string two(20, '$');
    cout << two << endl;

    string three(one);
    cout << three;

    one += " Oops!";
    cout << one << endl;

}