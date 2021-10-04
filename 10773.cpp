#include <stack>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    stack<int> S;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        if (input == 0 && !S.empty())
            S.pop();
        else
            S.push(input);
    }

    if (S.empty())
        cout << 0 << "\n";
    else
        cout << S.top() << "\n";
    return 0;
}