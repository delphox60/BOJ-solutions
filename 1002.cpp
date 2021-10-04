#include <iostream>
#include <cmath>

double distance(int x1, int y1, int x2, int y2)
{
    double returnval = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return returnval;
}
int main()
{
    using namespace std;
    int n_test;
    cin >> n_test;

    int x1[n_test];
    int y1[n_test];
    int r1[n_test];
    int x2[n_test];
    int y2[n_test];
    int r2[n_test];

    for (int i = 0; i < n_test; i++)
    {
        cin >> x1[i] >> y1[i] >> r1[i] >> x2[i] >> y2[i] >> r2[i];
    }
    for (int i = 0; i < n_test; i++)
    {
        if (r1[i] + r2[i] < distance(x1[i], y1[i], x2[i], y2[i]) || r1[i] > r2[i] + distance(x1[i], y1[i], x2[i], y2[i]) || r2[i] > r1[i] + distance(x1[i], y1[i], x2[i], y2[i]))
            cout << 0 << endl;
        else if (x1[i] == x2[i] && y1[i] == y2[i] && r1[i] == r2[i])
            cout << -1 << endl;
        else if (r1[i] + r2[i] == distance(x1[i], y1[i], x2[i], y2[i]) || r1[i] == r2[i] + distance(x1[i], y1[i], x2[i], y2[i]) || r2[i] == r1[i] + distance(x1[i], y1[i], x2[i], y2[i]))
            cout << 1 << endl;
        else if (r1[i] + r2[i] > distance(x1[i], y1[i], x2[i], y2[i]))
            cout << 2 << endl;
    }
    return 0;
}