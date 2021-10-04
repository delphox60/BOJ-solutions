#include <iostream>

double maxof(double *x, int n)
{
    double max_val = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > max_val)
            max_val = x[i];
    }
    return max_val;
}

double minof(double *x, int n)
{
    double min_val = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] < min_val)
            min_val = x[i];
    }
    return min_val;
}

int main()
{
    using namespace std;

    double N;
    cin >> N;

    double c1[6];
    cin >> c1[0] >> c1[1] >> c1[2] >> c1[3] >> c1[4] >> c1[5];

    if (N == 1)
    {
        double returnval = 0;
        for (int i = 0; i < 6; i++)
        {
            returnval += c1[i];
        }
        returnval -= maxof(c1, 6);
        cout << returnval << endl;
    }

    else
    {
        double c2[12];
        c2[0] = c1[0] + c1[1];
        c2[1] = c1[0] + c1[2];
        c2[2] = c1[0] + c1[3];
        c2[3] = c1[0] + c1[4];
        c2[4] = c1[1] + c1[2];
        c2[5] = c1[1] + c1[3];
        c2[6] = c1[1] + c1[5];
        c2[7] = c1[2] + c1[4];
        c2[8] = c1[2] + c1[5];
        c2[9] = c1[3] + c1[4];
        c2[10] = c1[3] + c1[5];
        c2[11] = c1[4] + c1[5];

        double c3[8];
        c3[0] = c1[0] + c1[1] + c1[2];
        c3[1] = c1[0] + c1[1] + c1[3];
        c3[2] = c1[0] + c1[4] + c1[2];
        c3[3] = c1[0] + c1[4] + c1[3];
        c3[4] = c1[5] + c1[1] + c1[2];
        c3[5] = c1[5] + c1[1] + c1[3];
        c3[6] = c1[5] + c1[4] + c1[2];
        c3[7] = c1[5] + c1[4] + c1[3];

        double c1min = minof(c1, 6);
        double c2min = minof(c2, 12);
        double c3min = minof(c3, 8);

        double returnval = (N - 2) * (5 * N - 6) * c1min + ((2 * N - 3) * 4) * c2min + 4 * c3min;

        cout << fixed;
        cout.precision(0);
        cout << returnval << endl;
    }
    return 0;
}