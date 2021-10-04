#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    while (1)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if (A == 0 || B == 0 || C == 0)
            break;
        A *= A;
        B *= B;
        C *= C;
        if (A + B == C || A + C == B || B + C == A)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}