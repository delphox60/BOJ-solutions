#include <iostream>

int main()
{
    using namespace std;
    int n;
    cin >> n;

    int Alist[n];
    int Blist[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Alist[i] >> Blist[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << Alist[i] + Blist[i] << endl;
    }
    return 0;
}