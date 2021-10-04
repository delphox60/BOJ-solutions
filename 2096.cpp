#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int tMp1 = 0;
    int tMp2 = 0;
    int tMp3 = 0;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int tmp1_ = a + min(tmp1, tmp2);
        int tmp2_ = b + min(tmp1, min(tmp2, tmp3));
        int tmp3_ = c + min(tmp2, tmp3);

        int tMp1_ = a + max(tMp1, tMp2);
        int tMp2_ = b + max(tMp1, max(tMp2, tMp3));
        int tMp3_ = c + max(tMp2, tMp3);

        tmp1 = tmp1_;
        tmp2 = tmp2_;
        tmp3 = tmp3_;
        tMp1 = tMp1_;
        tMp2 = tMp2_;
        tMp3 = tMp3_;
    }

    cout << max(tMp1, max(tMp2, tMp3)) << ' '
         << min(tmp1, min(tmp2, tmp3)) << '\n';
}