#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, tmp, q;
    cin >> n;
    set<int> st;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        st.insert(tmp);
    }

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> tmp;
        auto it = st.lower_bound(tmp);
        auto b = st.begin();

        if (tmp < *b)
        {
            cout << "NO" << "\n";
        }
        else
        {
            if (*it != tmp)
            {
                --it;
            }

            cout << *it << "\n";
        }
    }

    return 0;
}
