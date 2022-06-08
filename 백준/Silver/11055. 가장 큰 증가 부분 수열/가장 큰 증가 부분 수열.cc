#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D(1005, 0);
vector<int> A(1005);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        D[i] = A[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
                D[i] = max(D[i], D[j] + A[i]);
        }
    }

    cout << *max_element(D.begin(), D.end()) << '\n';
}