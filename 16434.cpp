#include <iostream>

using namespace std;

int N;
long long atk;
short rooms1[123460];
int rooms2[123460];
int rooms3[123460];

bool go(long long maxHP)
{
    long long curHP = maxHP;
    long long curATK = atk;

    for (int i = 0; i < N; i++)
    {
        if (rooms1[i] == 1)
        {
            long long monsterATK = rooms2[i];
            long long monsterHP = rooms3[i];

            long long curCost = monsterHP % curATK == 0 ? monsterHP / curATK
                                                        : monsterHP / curATK + 1;
            long long monsterCost = curHP % monsterATK == 0 ? curHP / monsterATK
                                                            : curHP / monsterATK + 1;

            if (curCost <= monsterCost)
            {
                curHP -= (curCost - 1) * monsterATK;
            }
            else if (curCost > monsterCost)
                return false;
        }
        else if (rooms1[i] == 2)
        {
            curATK += rooms2[i];
            curHP += rooms3[i];
            if (curHP > maxHP)
                curHP = maxHP;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> atk;

    for (int i = 0; i < N; i++)
    {
        cin >> rooms1[i];
        cin >> rooms2[i];
        cin >> rooms3[i];
    }

    long long high = 2234560000000000000;
    long long low = 0;
    long long mid;

    while (high - 1 != low)
    {
        mid = (high + low) / 2;

        if (go(mid))
            high = mid;
        else
            low = mid;
    }
    if (high <= 0)
        high = 1;

    cout << high << '\n';
    return 0;
}