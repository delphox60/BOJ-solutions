#include <iostream>

#define MAXPRIME 1299709

using namespace std;

int N;
bool isPrime[1300000];
int befPrime[1300000];

int nextPrime(int x)
{
    while (!isPrime[x] && x <= MAXPRIME)
        x++;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXPRIME; i++)
        isPrime[i] = true;

    int btmp;

    for (int i = 2; i <= MAXPRIME; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2; i * j <= MAXPRIME; j++)
                isPrime[i * j] = false;
            btmp = i;
        }
        befPrime[i] = btmp;
    }

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        if (isPrime[k])
            cout << 0 << '\n';
        else
            cout << nextPrime(k) - befPrime[k] << '\n';
    }

    return 0;
}