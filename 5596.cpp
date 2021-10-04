#include <iostream>
int main()
{
    using namespace std;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        sum1 += x;
    }
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        sum2 += x;
    }
    int sum = sum1 >= sum2 ? sum1 : sum2;
    cout << sum << endl;
    return 0;
}