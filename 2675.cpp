#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int repeat;
        string str;
        cin >> repeat >> str;
        for (int j = 0; j < str.length(); j++)
        {
            for (int k = 0; k < repeat; k++)
            {
                cout << str[j] << flush;
            }
        }
        cout << endl;
    }

    return 0;
}