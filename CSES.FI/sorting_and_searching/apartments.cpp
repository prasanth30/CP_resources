#include <bits/stdc++.h>
using namespace std;
//actual solution is at bottom//
////<pbds>////
/*OPTIONAL
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>; 
// change null_type for map
#define ook order_of_key
#define fbo find_by_order
*/
///</pbds>///

#define int long long int
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()

///<constants>///
const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};
///</constants>///

///<IO>/// 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        // cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;
///</IO>///

///<execution-time>///
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
/*example for clock usage
    clock_t z = clock();
    debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
*/
///</execution-time>///

inline void google(int i){
    cout<<"Case #"<<i<<" :";
}
signed main(){
    setIO("");
    int n,m,k;cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++){
    	/*int x;cin>>x;
    	a.pb(x);*/
    	cin>>a[i];
    }
   // vector<int> b;
    multiset <int> b;
    for(int i=0;i<m;i++){
    	int x;cin>>x;
    	/*b.pb(x);*/
    	b.insert(x);
    }
    int ans=0;
 //   sort(b.begin(), b.end());
  //  sort(a.begin(), a.end());
    sort(a,a+n);
    for(int i=0;i<n;i++){
    	//int x=lower_bound(b.begin(), b.end(),a[i]-k)-b.begin();
    	auto x=b.lower_bound(max(a[i]-k,0LL));
    	if(x!=b.end())
    	if(*x<=a[i]+k){
    		ans++;
    		b.erase(x);
    	}
    }
    cout<<ans<<"\n";
    return 0;
}
/* stuff you should look for
    * check whether you have read the problem correctly
    * int overflow, array bounds
    * special cases (n=1?), slow multiset operations
    * do smth instead of nothing and stay organized
*/
/*
change log-1:
	submitted code got tle
	changes needed:
		vector -> multiset 
		lower_bound to ms.lower_bound()
changes made
change log-2:
	got rte in few cases maybe poor handling of pointers
*/