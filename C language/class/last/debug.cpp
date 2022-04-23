#include <iostream>
#include <string.h>
using namespace std;

bool isLetter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    else
        return false;
}

char toUpper(char c)
{
    c = c - 32;
    return c;
}

void firstUpper(char *s)
{
    if (isLetter(s[0]) == true)
        s[0] = toUpper(s[0]);

    for (int i = 1; i < strlen(s); i++)
        if (isLetter(s[i]) == true && isLetter(s[i - 1]) == false)
            s[i] = toUpper(s[i]);
}

int main()
{
    char s[] = "33abc,,efg  r  ";
    firstUpper(s);
    cout << s << endl;
    return 0;
}