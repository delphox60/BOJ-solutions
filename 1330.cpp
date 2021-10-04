#include <iostream>

int main()
{
    using namespace std;
    int A, B;
    cin >> A >> B;
    if (A < B)
        cout << "<" << endl;
    if (A == B)
        cout << "==" << endl;
    if (A > B)
        cout << ">" << endl;
}