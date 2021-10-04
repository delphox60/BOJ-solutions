#include <iostream>
#include <string>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string omr;
        cin >> omr;
        int stack = 0;
        int score = 0;
        for (int j = 0; j < omr.length(); j++)
        {
            if (omr[j] == 'O')
            {
                stack++;
                score += stack;
            }
            else if (omr[j] == 'X')
                stack = 0;
        }
        cout << score << endl;
    }
    return 0;
}