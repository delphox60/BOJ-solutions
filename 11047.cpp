#include <iostream>

int main()
{
    using namespace std;
    int N, K;
    int n_used = 0;

    cin >> N >> K;

    int coin_list[N];
    for (int i = 0; i < N; i++)
    {
        cin >> coin_list[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (K >= coin_list[N - 1 - i])
        {
            n_used += (K - (K % coin_list[N - 1 - i])) / coin_list[N - 1 - i];
            K %= coin_list[N - 1 - i];
            if (K == 0)
                break;
        }
    }

    cout << n_used << endl;
    return 0;
}