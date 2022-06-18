#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[4] = "23";
    // const char *b = "10\0";
    cout << strlen(a) << endl;
    cout << sizeof(a) << endl;
    // cout << strlen(b) << endl;
    // cout << sizeof(b) << endl;
}