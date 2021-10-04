#include <iostream>

using namespace std;

int score[305];
int stair[305][4];

int main()
{
    int k;
    cin >> k;

    for (int i = 1; i <= k; i++)
        cin >> score[i];

    stair[1][1] = score[1];
    stair[2][1] = score[2];
    stair[2][2] = score[1] + score[2];

    for (int i = 3; i <= k; i++)
    {
        stair[i][1] = max(stair[i - 2][1], stair[i - 2][2]) + score[i];
        stair[i][2] = stair[i - 1][1] + score[i];
    }

    cout << max(stair[k][1], stair[k][2]) << "\n";
    return 0;
}