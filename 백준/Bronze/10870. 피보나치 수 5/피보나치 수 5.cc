#include <iostream>

using namespace std;
long long arr[100];

int main()
{
    long long x;
    cin >> x;
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= x; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    cout << arr[x];
}