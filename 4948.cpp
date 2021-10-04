#include <iostream>

using namespace std;

bool isprime[255555];
int n_prime[255555];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> N;

        if (!N)
            break;

        for (int i = 1; i <= 255555; i++)
            isprime[i] = true;
        isprime[1] = false;
        int cnt = 0;

        for (int i = 2; i <= 2 * N; i++)
        {
            if (isprime[i])
                for (int j = 1; i * j <= 2 * N; j++)
                {
                    isprime[i * j] = false;
                    cnt++;
                }
            n_prime[i] = cnt;
        }

        cout << n_prime[2 * N] - n_prime[N] << "\n";
    }

    return 0;
}