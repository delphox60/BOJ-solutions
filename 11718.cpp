#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string ip;

    while (getline(cin, ip))
        cout << ip;
}