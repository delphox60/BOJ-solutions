#include <iostream>

int main()
{
    using namespace std;
    int list[8];

    for (int i = 0; i < 8; i++)
        cin >> list[i];

    int order = 0;

    for (int i = 1; i < 8; i++)
    {
        if (list[i] == list[i - 1] + 1)
            order++;
        else if (list[i] == list[i - 1] - 1)
            order--;
    }

    if (order == 7)
        cout << "ascending" << endl;
    else if (order == -7)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;
    return 0;
}