#include <iostream>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; i++)
    {
        int ip;
        cin >> ip;
        if (ip < X)
            cout << ip << " " << flush;
    }
    cout << endl;
    return 0;
}