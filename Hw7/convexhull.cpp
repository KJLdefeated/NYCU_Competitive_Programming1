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
//const ll  Inf     = 2e18+9;
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
int n;
int cross(pii o,pii a,pii b){
    return (a.first - o.first)*(b.second - o.second) - (a.second - o.second)*(b.first - o.first);
}
void solve(){
    vector<pii> a,b;
    set<pii> s;
    FOR(i,0,n){
        int x,y;cin>>x>>y;
        if(s.count({x,y}))continue;
        a.pb({x,y});
        s.insert({x,y});
    }
    b=a;
    n=sz(a);
    sort(all(a));
    vector<pii> ans;
    FOR(i,0,n){
        while(sz(ans)>=2 && cross(ans[sz(ans)-1], ans[sz(ans)-2], a[i]) <= 0)ans.pop_back();
        ans.pb(a[i]);
    }
    for(int i=n-2, t=sz(ans)+1;i>=0;i--){
        while(sz(ans) >= t && cross(ans[sz(ans)-1], ans[sz(ans)-2], a[i]) <= 0)ans.pop_back();
        ans.pb(a[i]);
    }
    if(sz(ans)>1)ans.pop_back();
    cout<<ans.size()<<endl;
    reverse(all(ans));
    for(auto it:ans){
        cout<<it.F<<' '<<it.S<<endl;
    }
}

int main(){
    INITIO()
    while(cin>>n && n){
        solve();
    }
    return 0;
}
