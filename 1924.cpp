#include <iostream>
#include <cstring>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string yoil[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m, d;
    cin >> m >> d;

    int tot = 0;
    for (int i = 0; i < m; i++)
        tot += month[i];
    tot += d;
    cout << yoil[tot % 7] << '\n';
}
