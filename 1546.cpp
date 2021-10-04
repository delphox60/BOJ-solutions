#include <iostream>
#include <algorithm>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    double scores[n];
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
    sort(scores, scores + n);
    double max_score = scores[n - 1];
    double mean = 0;
    for (int i = 0; i < n; i++)
    {
        scores[i] /= max_score;
        scores[i] *= 100;
        mean += scores[i];
    }
    mean /= n;
    cout << mean << endl;
    return 0;
}