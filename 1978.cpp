#include <iostream>

int isprime(int x)
{
    if (x == 1)
        return 0;
    else
    {
        for (int i = 2; i < x; i++)
            if (x % i == 0)
                return 0;
    }
    return 1;
}

int main()
{
    using namespace std;

    int N;
    cin >> N;

    int test_list[N];
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        test_list[i] = x;
    }

    int n_prime = 0;

    for (int i = 0; i < N; i++)
    {
        n_prime += isprime(test_list[i]);
    }
    cout << n_prime << endl;
    return 0;
}