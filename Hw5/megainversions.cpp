#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <list>
#include <string.h>
#include <sstream>
using namespace std;
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE        freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define rall(a)      a.rbegin(),a.rend()
#define sz(a)       (int)a.size()
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
typedef                pair<long,long> pll;
const ll  Inf     = 2e18+9;
const int Mod     = 998244353;
const int N       = 1e5+9;
const int dx[4] = {0, 1,  0, -1};
const int dy[4] = {1, 0, -1,  0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
int mul(int a, int b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------

struct BIT{
    vector<ll> a;
    void modify(ll x,ll val){
        for(;x<a.size();x+=(x&-x))a[x]+=val;
    }
    ll query(ll x,ll y){
        ll cnt1=0,cnt2=0;
        for(;y;y-=(y&-y))cnt2+=a[y];
        for(;x;x-=(x&-x))cnt1+=a[x];
        return cnt2-cnt1;
    }
};

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    FOR(i,0,n)cin>>a[i];
    BIT tr1,tr2;
    tr1.a.resize(n+1,0);
    tr2.a.resize(n+1,0);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=tr2.query(a[i],n);
        tr2.modify(a[i],tr1.query(a[i],n));
        tr1.modify(a[i],1);
    }
    cout<<ans<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
