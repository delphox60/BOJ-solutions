#include <iostream>

int main()
{
    using namespace std;
    int x[9];
    for (int i = 0; i < 9; i++)
        cin >> x[i];
    int max = 0;
    int max_idx;
    for (int i = 0; i < 9; i++)
    {
        if (x[i] >= max)
        {
            max = x[i];
            max_idx = i;
        }
    }
    cout << max << endl;
    cout << max_idx + 1 << endl;
    return 0;
}