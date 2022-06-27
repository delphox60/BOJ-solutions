#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A(1000);
vector<int> D(1000, 1);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i])
            {
                D[i] = max(D[i], D[j] + 1);
            }
        }

    cout << *max_element(D.begin(), D.end()) << '\n';
}