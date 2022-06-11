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
int n,m,a[105],b[105],f[100005]={},d[100005]={};
void solve(){
    cin>>n;FOR(i,0,n)cin>>a[i];
    cin>>m;FOR(i,0,m)cin>>b[i];
    FOR(i,0,100001)f[i]=d[i]=Inf;
    f[0]=d[0]=0;
    for(int i=0;i<n;i++){
        for(int j=100000;j>=0;j--){
            if(f[j]!=Inf && j+a[i]<=100000)f[j+a[i]] = min(f[j+a[i]], f[j] + 1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=100000;j>=0;j--){
            if(d[j]!=Inf && j+b[i]<=100000)d[j+b[i]] = min(d[j+b[i]], d[j] + 1);
        }
    }
    int ans = Inf;
    for(int i=1;i<=100000;i++){
        if(f[i]!=Inf && d[i]!=Inf)ans = min(ans, f[i]+d[i]);
    }
    if(ans == Inf)cout<<"impossible"<<endl;
    else cout<<ans<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
