#include <iostream>
#include <string>

using namespace std;

const int MX = 10000 * 10;

const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
bool chk[MX];

int c2i(char c)
{
    return c - '0';
}

void init()
{
    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < 26; j++)
            nxt[i][j] = -1;
        chk[i] = false;
    }
    unused = 2;
}

bool insert(string s)
{
    int cur = ROOT;
    for (char c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
        if (chk[cur])
            return false;
    }
    chk[cur] = true;
    return (cur == (unused - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        int n;
        bool result = true;
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            if (!result)
                continue;
            if (!insert(s))
            {
                result = false;
            }
        }
        if (result)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}

// TODO when insert, check if end node has child or any ancestors has end node