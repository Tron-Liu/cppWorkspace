#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> v;

    for(i = 1; i < 4; i++) {
        v.push_back(i);
    }   

    cout << v.size() << endl;
    auto start = v.begin();
    auto end = v.end() - 1;

    cout << *start << '\t' << *end << endl;
    start++;
    printf("%d\n", start);
    printf("%d\n", v.begin());
    start++;
    printf("%d\n", start);
    printf("%p\n", v.begin());
    printf("%d\n", sizeof(int));
    printf("%p\n", start-2);
    //cout << static_cast (start) << '\t' << static_cast(end) << endl;
    return 0;
} 