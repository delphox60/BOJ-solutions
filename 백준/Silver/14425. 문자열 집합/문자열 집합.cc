#include <iostream>
#include <string>

using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 5000000;
int nxt[MX][26];
bool chk[MX];

int c2i(char c)
{
    return c - 'a';
}

void insert(string s)
{
    int cur = ROOT;
    for (char c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string s)
{
    int cur = ROOT;

    for (char c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    int n, m;
    string s;
    int result = 0;
    cin >> n >> m;
    while (n--)
    {
        cin >> s;
        insert(s);
    }
    while (m--)
    {
        cin >> s;
        if (find(s))
            result++;
    }
    cout << result;
}