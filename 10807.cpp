#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, v;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    cin >> v;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (nums[i] == v)
            count++;
    }
    cout << count;
    return 0;
}