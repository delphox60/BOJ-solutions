#include <iostream>
#include <vector>
#include <math.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;
    ll minVal = min(a, b);
    vector<ll> v;
    ll result = 1;

    for (int i = 2; i < sqrt(minVal); i++)
    {
        while (!(minVal % i) && minVal > 1)
        {
            v.push_back(i);
            v.push_back(minVal / i);
            minVal /= i;
        }
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        ll cur = *it;
        if (!(a % cur) && !(b % cur))
            result *= cur;
    }
    cout << result << '\n';
}
