#include <iostream>

int main()
{
    using namespace std;
    int n, m;
    cin >> n >> m;
    int com = 1;
    for (int i = 0; i < m; i++)
        com *= (n - i);
    for (int i = 1; i < m + 1; i++)
        com /= i;
    cout << com << endl;
    return 0;
}