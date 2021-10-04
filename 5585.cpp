#include <iostream>

int main()
{
    using namespace std;
    int price;
    cin >> price;
    int change = 1000 - price;
    int n_coin = 0;
    if (change >= 500)
    {
        n_coin += change / 500;
        change %= 500;
    }
    if (change >= 100)
    {
        n_coin += change / 100;
        change %= 100;
    }
    if (change >= 50)
    {
        n_coin += change / 50;
        change %= 50;
    }
    if (change >= 10)
    {
        n_coin += change / 10;
        change %= 10;
    }
    if (change >= 5)
    {
        n_coin += change / 5;
        change %= 5;
    }
    if (change >= 1)
    {
        n_coin += change / 1;
        change %= 1;
    }
    cout << n_coin << endl;
    return 0;
}