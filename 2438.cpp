#include <iostream>

int main()
{
    using namespace std;
    int N;
    cin >> N;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*" << flush;
        }
        cout << endl;
    }
    return 0;
}