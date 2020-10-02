#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ld long double
 
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
 
int32_t main()
{
    usaco();
    ll n, k, ans = 0;
    cin >> n >> k;
    vector <ll> a(n);
    oset <ll> s;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < k; ++i) s.insert({a[i], i});
    ll mid = (*s.find_by_order((k+1)/2-1)).first;
    for (ll i = 0; i < k; ++i) ans += abs(mid-a[i]);
    cout << ans << " ";
    for (ll i = k; i < n; ++i)
    {
        int premid = mid;
        ans -= abs(mid-a[i-k]);
        s.erase({a[i-k], i-k});
        s.insert({a[i], i});
        mid = (*s.find_by_order((k+1)/2-1)).first;
        ans += abs(mid-a[i]);
        if (k&1^1) ans -= mid-premid;
        cout << ans << " ";
    }
}
