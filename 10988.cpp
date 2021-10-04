#include <iostream>
#include <string.h>

int main()
{
    using namespace std;

    string str;
    int isnotpel = 0;

    cin >> str;

    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
            isnotpel++;
    }
    if (isnotpel)
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return 0;
}