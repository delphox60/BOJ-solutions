#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    string input;
    while (input != "0")
    {
        cin >> input;
        if (input == "0")
            break;
        int length = input.length();
        int ispal = 1;
        for (int i = 0; i < length / 2; i++)
        {
            if (input[i] != input[length - 1 - i])
                ispal = 0;
        }
        if (ispal)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}