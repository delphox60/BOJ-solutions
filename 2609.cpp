#include <iostream>

int main()
{
    using namespace std;

    int A, B, max_d, min_m;

    cin >> A >> B;

    int A_ = A;
    int B_ = B;

    if (A == B)
        max_d = A;
    else if (A < B)
    {
        for (int i = A; i > 0; i--)
        {
            if (A % i == 0 && B % i == 0)
            {
                max_d = i;
                break;
            }
        }
    }
    else if (A > B)
    {
        for (int i = B; i > 0; i--)
        {
            if (A % i == 0 && B % i == 0)
            {
                max_d = i;
                break;
            }
        }
    }

    while (1)
    {
        if (A_ == B_)
        {
            min_m = A_;
            break;
        }
        else if (A_ > B_)
            B_ += B;
        else if (A_ < B_)
            A_ += A;
    }
    cout << max_d << endl
         << min_m << endl;
    return 0;
}