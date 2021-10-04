#include <iostream>
#include <string>

int main()
{
    using namespace std;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        int notvps = 0;
        int wrong = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '(')
                notvps += 1;
            else if (str[j] == ')')
                notvps -= 1;
            if (notvps < 0)
                wrong = 1;
        }
        if (notvps == 0 && !wrong)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}