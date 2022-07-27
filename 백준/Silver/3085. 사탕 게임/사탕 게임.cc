#include <iostream>
#include <vector>

using namespace std;

int arr[51][51];
int maxval = 0;
int n;

void cnt(int x, int y)
{
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[x][i] == arr[x][i - 1])
            c++;
        else
        {
            maxval = max(maxval, c);
            c = 1;
        }
    }
    maxval = max(maxval, c);
    c = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i][y] == arr[i - 1][y])
            c++;
        else
        {
            maxval = max(maxval, c);
            c = 1;
        }
    }
    maxval = max(maxval, c);
}

int main()
{
    string ip;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ip;
        for (int j = 0; j < n; j++)
            arr[i][j] = ip[j];
    }
    for (int i = 0; i < n; i++)
        cnt(i, i);

    int nx, ny;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                nx = dx[k] + i;
                ny = dy[k] + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                swap(arr[i][j], arr[nx][ny]);
                cnt(i, j);
                cnt(nx, ny);
                swap(arr[i][j], arr[nx][ny]);
            }
        }
    cout << maxval;
}