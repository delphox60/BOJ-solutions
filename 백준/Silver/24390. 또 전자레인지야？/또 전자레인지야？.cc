#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s;
    string time;
    cin >> time;

    m = (time[0] - '0') * 10 + (time[1] - '0');
    s = (time[3] - '0') * 10 + (time[4] - '0');

    s = m * 60 + s;

    int result1 = 1;
    int tmp = s - 30;

    if (tmp < 0)
    {
        int result2 = 1;
        tmp = s;

        while (tmp > 0)
        {
            if (tmp - 600 < 0)
                break;
            tmp -= 600;
            result2++;
        }

        while (tmp > 0)
        {
            if (tmp - 60 < 0)
                break;
            tmp -= 60;
            result2++;
        }

        while (tmp > 0)
        {
            if (tmp - 10 < 0)
                break;
            tmp -= 10;
            result2++;
        }

        cout << result2;
        return 0;
    }

    while (tmp > 0)
    {
        if (tmp - 600 < 0)
            break;
        tmp -= 600;
        result1++;
    }

    while (tmp > 0)
    {
        if (tmp - 60 < 0)
            break;
        tmp -= 60;
        result1++;
    }

    while (tmp > 0)
    {
        if (tmp - 30 < 0)
            break;
        tmp -= 30;
        result1++;
    }

    while (tmp > 0)
    {
        if (tmp - 10 < 0)
            break;
        tmp -= 10;
        result1++;
    }

    int result2 = 1;
    tmp = s;

    while (tmp > 0)
    {
        if (tmp - 600 < 0)
            break;
        tmp -= 600;
        result2++;
    }

    while (tmp > 0)
    {
        if (tmp - 60 < 0)
            break;
        tmp -= 60;
        result2++;
    }

    while (tmp > 0)
    {
        if (tmp - 10 < 0)
            break;
        tmp -= 10;
        result2++;
    }

    cout << min(result1, result2);
}