#include <iostream>

int find_tens_of(int N)
{
    return (N - (N % 10)) / 10;
}

int find_ones_of(int N)
{
    return N % 10;
}

int main()
{
    using namespace std;
    int N;
    cin >> N;

    int cur = N;
    int cycle = 0;
    while (1)
    {
        int tens_cur = find_ones_of(cur);
        int ones_cur = find_ones_of(find_tens_of(cur) + find_ones_of(cur));
        cur = 10 * tens_cur + ones_cur;
        cycle++;
        if (cur == N)
        {
            cout << cycle << endl;
            break;
        }
    }
    return 0;
}