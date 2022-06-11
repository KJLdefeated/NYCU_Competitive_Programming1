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
#define FILE()      freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
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
const int  Inf     = 1e9+7;
const int N       = 2e5+9;
const int dy[4] = {1, 0, -1,  0};
const int dx[4] = {0, 1,  0, -1};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------

void solve(){
    int n;
    cin>>n;
    vector<int> h(n),w(n);
    FOR(i,0,n){cin>>h[i];h[i]=h[i]*2/3;}
    FOR(i,0,n)cin>>w[i];
    w.pb(0);
    h.pb(0);
    ll ans=0,cnt=0;
    stack<pll> s;
    s.push({0,0});
    FOR(i,0,n+1){
        cnt+=w[i];
        ll r = s.top().second;
        while(h[i] < s.top().first){
            pll tmp = s.top();
            s.pop();
            ans = max(ans, (r-s.top().S)*tmp.first);
        }
        s.push({h[i], cnt});
    }
    cout<<ans<<endl;
}

int main(){
    INITIO()
    //FILE()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
