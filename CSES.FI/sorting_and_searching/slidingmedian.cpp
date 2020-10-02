#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <class T> using oset = tree <pair <T, T>, null_type, less <pair <T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
 
void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
 
int main()
{
    usaco();
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    oset <int> s;
    int l = a[0];
    for (int i = 0; i < k; ++i) s.insert(make_pair(a[i], i));
    cout << (*s.find_by_order((k-1)/2)).first << " ";
    int idx = k;
    for (int i = k; i < n; ++i)
    {
        s.erase({a[idx-k], idx-k});
        s.insert({a[idx], idx});
        cout << (*s.find_by_order((k-1)/2)).first << " ";
        ++idx;
    }
    cout << '\n';
}
