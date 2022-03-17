#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[51];
vector<int> c[51];
vector<int> c_cost[51];
vector<int> cost(51, -1);

int set_tree(int n)
{
    int &ret = cost[n];
    if (ret > 0)
        return ret;

    if (c[n].size() == 0)
        return ret = 0;

    for (int child : c[n])
        c_cost[n].push_back(set_tree(child));

    sort(c_cost[n].begin(), c_cost[n].end());

    int co = c_cost[n].size();
    for (int i = 0; i < c_cost[n].size(); i++)
    {
        c_cost[n][i] += co;
        co--;
    }
    return ret = *max_element(c_cost[n].begin(), c_cost[n].end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, root;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int pe;
        cin >> pe;
        if (pe < 0)
        {
            root = i;
            continue;
        }
        p[i] = pe;
        c[pe].push_back(i);
    }
    cout << set_tree(root);
    cout << endl;
}