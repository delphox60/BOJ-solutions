#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int list[4];
    list[0] = x;
    list[1] = y;
    list[2] = w - x;
    list[3] = h - y;
    sort(list, list + 4);
    cout << list[0] << endl;
    return 0;
}