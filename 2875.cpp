#include <iostream>

using namespace std;

int comb(int m, int n)
{
    return min(m / 2, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int answer = 0;

    for (int i = 0; i <= K; i++)
    {
        answer = max(answer, comb(N - i, M - (K - i)));
    }
    cout << answer;
    return 0;
}