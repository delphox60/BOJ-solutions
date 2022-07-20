#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int, int>

using namespace std;

int score[200000];
int study[200000];

struct scoreset
{
    int study;
    int score;
    scoreset(int study, int score) : study(study), score(score) {}

    bool operator<(const scoreset s) const
    {
        return (((this->study + this->score) <= 100) ? this->study : 100 - this->score) < (((s.study + s.score) <= 100) ? s.study
                                                                                                                        : 100 - s.score);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
        cin >> score[i];

    for (int i = 0; i < m; i++)
        cin >> study[i];

    priority_queue<scoreset> pq;

    for (int i = 0; i < m; i++)
        pq.push(scoreset(study[i], score[i]));

    n *= 24;
    int result = 0;

    while (n > 0)
    {
        scoreset cur = pq.top();
        pq.pop();

        cur.score += cur.study;
        if (cur.score > 100)
            cur.score = 100;
        pq.push(cur);

        n--;
    }

    while (!pq.empty())
    {
        result += pq.top().score;
        pq.pop();
    }

    cout << result << endl;
}
