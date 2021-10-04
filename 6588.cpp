#include <iostream>

using namespace std;

bool isPrime[1000005];

void func(int k)
{
    for (int i = 3; i <= k / 2; i += 2)
    {
        if (isPrime[i] && isPrime[k - i])
        {
            cout << k << " = " << i << " + " << k - i << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 1000000; i++)
        isPrime[i] = true;

    for (int i = 2; i <= 1000000; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2; i * j <= 1000000; j++)
                isPrime[i * j] = false;
        }
    }

    while (true)
    {
        int N;
        cin >> N;

        if (!N)
            break;

        func(N);
    }
    return 0;
}