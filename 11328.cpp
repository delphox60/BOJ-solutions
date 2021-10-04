#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;

        int arr1[26], arr2[26];
        for (int i = 0; i < 26; i++)
        {
            arr1[i] = 0;
            arr2[i] = 0;
        }

        for (int i = 0; i < str1.length(); i++)
            arr1[(int)str1[i] - 97]++;
        for (int i = 0; i < str2.length(); i++)
            arr2[(int)str2[i] - 97]++;

        bool poss = 1;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                poss = false;
        }
        if (poss)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}