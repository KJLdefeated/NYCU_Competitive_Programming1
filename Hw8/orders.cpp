#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <list>
#include <string.h>
#include <complex>
#include <sstream>
using namespace std;
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE()      freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define sz(a)       (int)a.size()
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
using vii = vector<vector<int>>;
using vi = vector<int>;
using mii = map<int,int>;
using cd = complex<double>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double PI   = acos(-1);
const ll Mod     = 1e9+7;
//const int  Inf     = 1e9+7;
//const int N       = 1e5+9;
//const int dx[4] = {0, 1,  0, -1};
//const int dy[4] = {1, 0, -1,  0};
//const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
//const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
int mul(int a, int b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------
int n, a[105],dp[30005]={}, d[30005]={};

void solve(){
    int n;cin>>n;
    FOR(i,1,n+1)cin>>a[i];
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    FOR(i,1,n+1){
        for(int j = a[i];j<=30000;j++){
            if(dp[j-a[i]] == -1)continue;
            if(dp[j-a[i]] + a[i] > dp[j]){
                dp[j] = dp[j-a[i]] + a[i];
                d[j] = i;
            }
            else if(dp[j-a[i]] + a[i] == dp[j]){
                d[j] = -1;
            }
        }
    }
    /*
     for(int j=0;j<=15;j++){
         cout<<dp[j]<<' ';
     }
     cout<<endl;

     */
        
    int m;cin>>m;
    while(m--){
        int x;cin>>x;
        if(dp[x]==-1)cout<<"Impossible"<<endl;
        else {
            int cnt = x, p=0;
            vector<int> ans;
            while(cnt){
                if(d[cnt]==-1){
                    p=1;
                    break;
                }
                ans.pb(d[cnt]);
                cnt-=a[d[cnt]];
                //cout<<cnt<<endl;
            }
            if(p)cout<<"Ambiguous"<<endl;
            else{
                while(ans.size()){
                    cout<<ans.back()<<' ';
                    ans.pop_back();
                }
                cout<<endl;
            }
        }
    }
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
