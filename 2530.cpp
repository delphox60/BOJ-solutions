#include <iostream>

int main()
{
    using namespace std;
    int hour, min, sec, ntime;
    cin >> hour >> min >> sec >> ntime;
    sec += ntime;
    ntime = sec / 60;
    sec %= 60;
    min += ntime;
    ntime = min / 60;
    min %= 60;
    hour += ntime;
    hour %= 24;
    cout << hour << " " << min << " " << sec << endl;
    return 0;
}