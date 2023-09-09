#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long h, w, n, m;
    cin >> h >> w >> n >> m;

    cout << (h / (n + 1) + (h % (n + 1) ? 1 : 0)) * (w / (m + 1) + (w % (m + 1) ? 1 : 0));
}