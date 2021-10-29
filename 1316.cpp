#include <iostream>
#include <string>

using namespace std;

bool visited[200];

void setV()
{
    for (int i = 0; i < 200; i++)
        visited[i] = false;
    return;
}

bool check(string s)
{
    setV();
    for (int i = 0; i < s.size(); i++)
    {
        if (i > 0 && s[i] == s[i - 1])
            continue;
        if (visited[s[i]])
            return false;
        visited[s[i]] = true;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (check(s))
            answer++;
    }
    cout << answer;
    return 0;
}
