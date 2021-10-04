#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

vector<ll> points;

ll N;
ll arr[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
        points.push_back(arr[i]);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    for (ll i = 0; i < N; i++)
    {
        ll op = lower_bound(points.begin(), points.end(), arr[i]) - points.begin();
        cout << op << " ";
    }
    return 0;
}