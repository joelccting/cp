#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, q;
    map<unsigned long long, int> mp;
    unsigned long long key;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> key;
        mp.insert({key, i});
    }

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> key;
        auto it = mp.find(key);
        if (it != mp.end())
        {
            cout << mp[key] + 1 << "\n";
            mp.erase(key);
        }
        else
        {
            cout << "solved" << "\n";
        }

    }

    return 0;
}
