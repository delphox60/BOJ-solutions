#include <iostream>

int main()
{
    using namespace std;
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
        cout << N << " * " << i << " = " << N * i << endl;
    return 0;
}