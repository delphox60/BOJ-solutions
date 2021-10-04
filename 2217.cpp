#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;

    int n;
    cin >> n;

    int list[n];
    for (int i = 0; i < n; i++)
        cin >> list[i];
    sort(list, list + n);

    int max_val = 0;

    for (int i = 0; i < n; i++)
    {
        if (max_val < list[i] * (n - i))
            max_val = list[i] * (n - i);
    }
    cout << max_val << endl;
    return 0;
}