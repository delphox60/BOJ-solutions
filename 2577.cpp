#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int num = a * b * c;

    string strnum = to_string(num);

    int numbers[10];
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;

    for (int i = 0; i < strnum.length(); i++)
    {
        numbers[(int)strnum[i] - 48]++;
    }

    for (int i = 0; i < 10; i++)
        cout << numbers[i] << '\n';
    return 0;
}