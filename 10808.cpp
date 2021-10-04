#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int freq[26];

    for (int i = 0; i < 26; i++)
        freq[i] = 0;
    for (int i = 0; i < input.length(); i++)
    {
        freq[input[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << freq[i] << " ";
    return 0;
}