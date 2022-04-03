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
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
typedef                pair<long,long> pll;
const double PI   = acos(-1);
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

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a&1){
        cout<<0<<endl;
    }
    else{
        ll m=a;
        a>>=1;
        ll ans=1;
        while(b--){
            ans=(ans*a)%m;
        }
        cout<<ans<<endl;
    }
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        //cout<<"Case #"<<kase<<": ";
        solve();
    //}
    return 0;
}

 
