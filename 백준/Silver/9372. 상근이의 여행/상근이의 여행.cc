#include <iostream>

using namespace std;

int p[1001];

int find(int a)
{
    if (p[a] < 0)
        return a;
    return find(p[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    p[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n, m;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i <= n; i++)
            p[i] = -1;

        int result = 0;
        int a, b;

        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            if (find(a) != find(b))
            {
                merge(a, b);
                result++;
            }
        }

        cout << result << endl;
    }
}