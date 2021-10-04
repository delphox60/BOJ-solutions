#include <iostream>

int main()
{
    using namespace std;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int h, w, n;
        cin >> h >> w >> n;
        int xx;
        int yy;
        if (n % h == 0)
        {
            xx = n / h;
            yy = h;
        }
        else
        {
            xx = n / h + 1;
            yy = n % h;
        }

        cout << xx + yy * 100 << endl;
    }
    return 0;
}