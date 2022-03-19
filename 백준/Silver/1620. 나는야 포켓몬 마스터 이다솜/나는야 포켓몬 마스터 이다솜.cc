#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N, M;

string names[100001];
map<string, int> dex;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        names[i] = name;
        dex.insert(make_pair(name, i));
    }

    for (int i = 1; i <= M; i++)
    {
        string ip;
        cin >> ip;
        if (isdigit(ip[0]))
        {
            cout << names[stoi(ip)] << '\n';
            continue;
        }
        auto it = dex.find(ip);
        cout << it->second << '\n';
    }
}