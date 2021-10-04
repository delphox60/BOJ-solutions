#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    using namespace std;
    int n;
    cin >> n;

    string stars = "*";

    for (int i = 0; i < n; i++)
    {
        cout << setw(n) << stars << endl;
        stars += "*";
    }
}