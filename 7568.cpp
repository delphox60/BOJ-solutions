#include <iostream>

using namespace std;

int h[55];
int w[55];
int n;

bool is_less(int n1, int n2)
{
    if (h[n1] < h[n2] && w[n1] < w[n2])
        return true;
    else
        return false;
}

int get_rank(int n1)
{
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != n1 && is_less(n1, i))
            rank++;
    }
    return rank;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
        cout << get_rank(i) << ' ';
    cout << '\n';
    return 0;
}