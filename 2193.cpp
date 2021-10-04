//*1
//*10
//*101 100
//*1010 1001 1000
//*10101 10100 10010 10001 10000

#include <iostream>

using namespace std;

long ez[93];
long eo[93];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ez[1] = 0;
    eo[1] = 1;
    ez[2] = 1;
    eo[2] = 0;

    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        ez[i] = ez[i - 1] + eo[i - 1];
        eo[i] = ez[i - 1];
    }

    cout << ez[n] + eo[n] << "\n";
    return 0;
}