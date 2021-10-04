#include <iostream>
#include <cmath>

using namespace std;

int brd[2][2] = {
    {0, 1},
    {2, 3}};

int Z(int r, int c, int n)
{
    if (n == 1)
        return brd[r][c];
    int low = pow(2, n - 1);
    int dr = r / low;
    int dc = c / low;

    return Z(r % low, c % low, n - 1) + pow(low, 2) * (2 * dr + dc);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, N;

    cin >> N >> r >> c;

    cout << Z(r, c, N) << "\n";
    return 0;
}