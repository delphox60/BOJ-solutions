#include <iostream>

using namespace std;

void draw(int n, int k)
{
    if (!(k % 2))
        cout << ' ';
    for (int i = 0; i < n; i++)
    {
        cout << '*';
        cout << ' ';
    }
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        draw(n, i);
}