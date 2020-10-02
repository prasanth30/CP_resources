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
//LETS TRY THE PROBLEM
//WE CAN USE PREFIX SUMS TO MAKE IT EASY
//MAX PREF - MIN PREF
int n,m,k;
signed main(){
    setIO("");
    int t;cin>>t;
    while(t--){
    	int n,m,k;cin>>n>>m>>k;
    	int a[n+1][m+1];
    	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    	int pref[n+1][m+1]={0};//for(int i=1;i<=n;i++)pref[i][m]=a[i][m];
    	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    	pref[i][j]=pref[i][j-1]+a[i][j];
///debug1////fine
//  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<pref[i][j]<<" ";cout<<"\n";}

    	int dp1[n+1][m+1][k+1]={0};
    	/*base case
    	its pretty messed up and wanna code it again for 
		writing a clean code
    	so coded it again 
    	//i==1
    	for(int j=1;j<=m;j++)for(int kk=1;kk<=k;kk++)
    			dp1[1][j][kk]=pref[1][j];//on the top row

    	for(int i=2;i<=n;i++){
    	for(int j=1;j<=m;j++){
    	for(int l=1;l<=k;l++){
    		if(j==1||k==0)dp1[i][j][l]=dp1[i-1][j][k]+pref[i][j];
    		else dp1[i][j][l]=pref[i][j]
    			//obvious transition
    			+max(dp1[i-1][j][l],dp1[i-1][j-1][l-1]);

    			}
    		}
    	}*/
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			for(int l=0;l<=k;l++){
    				if(i==1){//base case
    					dp1[1][j][l]=pref[1][j];
    				}
    				else if(l==0||j==1){//either no more spl moves available
    									//or spl move leads it to out of the grid
    					dp1[i][j][l]=pref[i][j]+dp1[i-1][j][l];
    				}
    				else{//normal transition
    					dp1[i][j][l]=max(dp1[i-1][j][l],dp1[i-1][j-1][l-1]);
    					dp1[i][j][l]+=pref[i][j];
    				}
    			}
    		}
    	}
    	int dp2[n+2][m+2][k+1]={0};
    	/*for(int j=1;j<=m;j++)
    		for(int kk=1;kk<=k;kk++)
    			dp2[1][j][kk]=pref[1][j]-a[1][j];//on the bottom row
    	
    	for(int i=2;i<=n;i++){
    		for(int j=1;j<=m;j++){
    				for(int l=0;l<=k;l++){
    					//if(j==1){dp2[i][j][l]=0;continue;}
    					if(l==0||j==1)
    						dp2[i][j][l]=pref[i][j]+dp2[i-1][j][l]-a[i][j];

    					else dp2[i][j][l]=pref[i][j]-a[i][j]+
    					//obviously two possible moves
    					  min(dp2[i-1][j][l],dp2[i-1][j-1][l-1]);
    			}
    		}
    	}*/
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			for(int l=0;l<=k;l++){
    				if(i==1)//base case
    					dp2[i][j][l]=pref[i][j];
    				else if(l==0||j==1)//I wont type it again
    					dp2[i][j][l]=dp2[i-1][j][l]+pref[i][j];
    				else 
    					dp2[i][j][l]=min(dp2[i-1][j][l],dp2[i-1][j-1][l-1])
    								 +pref[i][j];
    				dp2[i][j][l]-=a[i][j];
    				//subtracting a[i][j] cause we add it to the score so subtracting it here
    			}
    		}
    	}
 //debug2-idk whether its okay yea its fine
//for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<"[ ";for(int kk=1;kk<=k;kk++)cout<<dp1[i][j][kk]<<" ";cout<<"] ";}cout<<"\n";}
    	int ans=-INF;//cerr<<ans<<"\n";
    	for(int i=1;i<=m;i++){
    		for(int j=i+1+k;j<=m;j++){
    				//if(abs(j-i)>=k+1)
    				//as per the main logic max-min will give maximum answer :-)
    				ans=max(ans,dp1[n][j][k]-dp2[n][i][k]);
    			//	cout<<dp1[n][j][k]<<" "<<dp2[n][i][k]<<"\n";
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}
/* stuff you should look for
    * check whether you have read the problem correctly
    * int overflow, array bounds
    * special cases (n=1?), slow multiset operations
    * do smth instead of nothing and stay organized
    idea-1
    	umm say dp1(i,j,k) is the sum of all values to 
    	the right side of the path such that it reaches i,j 
    	we have used k spl moves
    	base case:- obvious
    doubt:- I dont think it will work
    	we should make dp such that the answer is actually we reached n,i
    	from top, that is from top row
    	so that we can check whether starting indices are at a distance of k
		

*/
/*
1
7 8 3
2 1 1 1 -1 -1 -1 -1
2 1 1 1 -1 -1 -1 -1
-1 1 1 1 -1 -1 -1 -1
-1 1 1 1 -1 -1 -1 -1
-1 1 1 1 1 -1 -1 -1
-1 -1 1 1 1 1 -1 -1
-1 -1 1 1 1 1 1 -1

		. | . . . . .
		. | . . . . .
		. . | . . . .
		. . | . . . .
		. . | . . . .
		. . | . . . .
		. . | . . . .
*/