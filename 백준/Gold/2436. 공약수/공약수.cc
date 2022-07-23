#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>
#include <stack>

#define mp make_pair
#define MOD 86400
#define INF 0x7fffffff
#define MAX_SIZE (int)1e5
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<pll>
#define vb vector<bool>

using namespace std;

int get_gcd(int a, int b)
{
    return b ? get_gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int gcd, lcm;
    cin >> gcd >> lcm;

    int t = lcm / gcd;

    int l = 0, r = 0;

    for (int i = 1; i * i <= t; i++)
    {
        if (t % i == 0)
        {
            if (get_gcd(i, t / i) == 1)
            {
                l = i;
                r = t / i;
            }
        }
    }

    if (l > r)
        swap(l, r);

    cout << l * gcd << ' ' << r * gcd;

    return 0;
}
