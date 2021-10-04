#include <iostream>

int minimum(int *x, int N)
{
    int minval = 1001;
    int mindex;
    for (int i = 0; i < N; i++)
    {
        int element = x[i];
        if (element < minval)
        {
            minval = element;
            mindex = i;
        }
    }
    return mindex;
}

int main()
{
    using namespace std;
    int N;
    cin >> N;

    int list[N];
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        list[i] = x;
    }
    int sorted_list[N];
    for (int i = 0; i < N; i++)
    {
        sorted_list[i] = list[minimum(list, N)];
        list[minimum(list, N)] = 1001;
    }
    int sum = 0;
    for (int i; i < N; i++)
    {
        sum += sorted_list[i] * (N - i);
    }

    cout << sum << endl;
    return 0;
}