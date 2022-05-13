#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#ifdef DEBUG
#else
#define deb(...)
#define debit(...)
#endif
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE        freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define MEM(i,j) memset(i,j,sizeof i);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define sz(a)       (int)a.size()
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
const double Eps  = 1e-8;
const int Inf     = 1e9+9;
const int Mod     = 1000000009;
const int N       = 1e5+9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int gcd(int a, int b){if( b==0 )return a;return gcd( b, a%b );}
int lcm(int a,int b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// -----------------------------------------------------------------------------------------------------
int a[205]={},dp[205]={},ps[205]={};
int n;
void solve(){
    for(int i=1;i<=n;i++){cin>>a[i];dp[i]=1;ps[i]=i;}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j] > a[i]){
                if(dp[i]+1 > dp[j]){
                    dp[j] = dp[i]+1;
                    ps[j] = i;
                }
                else if(dp[i]+1 == dp[j] && a[i] < a[ps[j]]){
                    dp[j] = dp[i]+1;
                    ps[j] = i;
                }
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<ps[i]<<' ';
    //cout<<endl;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int idx=i;
        vector<int> v;
        while(1){
            v.pb(a[idx]);
            if(ps[idx]==idx)break;
            idx = ps[idx];
        }
        sort(all(v));
        if(v.size() > ans.size()){
            ans = v;
        }
        else if(v.size() == ans.size()){
            for(int j=0;j<sz(ans);j++){
                if(v[j] < ans[j]){
                    ans=v;
                    break;
                }
            }
        }
    }
    cout<<ans.size()<<' ';
    for(auto it:ans)cout<<it<<' ';
    cout<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    while(cin>>n && n){
        solve();
    }
    return 0;
}
