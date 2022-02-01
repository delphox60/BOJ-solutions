#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<bool>> pal(2002, vector<bool>(2002, false));
int arr[2002];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        int b, e;
        b = e = i;
        while (b > 0 && e <= n)
        {
            if (arr[b] == arr[e])
                pal[b][e] = true;
            else
                break;
            b--;
            e++;
        }
        if (i != n && arr[i] == arr[i + 1])
        {
            int b, e;
            b = i;
            e = i + 1;
            while (b > 0 && e <= n)
            {
                if (arr[b] == arr[e])
                    pal[b][e] = true;
                else
                    break;
                b--;
                e++;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << pal[a][b] << '\n';
    }
}
