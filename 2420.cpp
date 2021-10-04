#include <iostream>

int main()
{
    using namespace std;
    long N, M;
    cin >> N >> M;
    long dif = N - M > 0 ? N - M : M - N;
    cout << fixed << dif << endl;
    return 0;
}