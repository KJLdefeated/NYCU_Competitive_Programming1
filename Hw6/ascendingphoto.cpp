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

void solve(){
    int n,cnt=0;cin>>n;
    vector<int> h;
    set<int> st;
    map<int,int> mp;
    FOR(i,0,n){
        int x;cin>>x;
        st.insert(x);
        if(h.empty() || h.back()!=x)h.pb(x);
    }
    for(auto it:st){
        if(!mp.count(it))mp[it] = cnt++;
    }
    n=sz(h);
    vector<vector<int>> pos(cnt);
    FOR(i,0,n){
        h[i] = mp[h[i]];
        pos[h[i]].pb(i);
    }
    pii best[2] = {{0,n}, {0,n}};
    FOR(i,0,cnt-1){
        pii nbest[2] = {best[0], best[1]};
        FOR(j,0,sz(pos[i])){
            int p = pos[i][j];
            if(p == n-1 || h[p]+1!=h[p+1])continue;
            pii s(0,n);
            if(p != best[0].second) s = best[0];
            else s = best[1];
            s.first++;
            s.second = p+1;
            if(pos[i+1].size() == 1) s.second = n;
            if(s > nbest[0]){
                nbest[1] = nbest[0];
                nbest[0] = s;
            }
            else if(s > nbest[1]) nbest[1] = s;
        }
        best[0] = nbest[0];
        best[1] = nbest[1];
    }
    cout<<n-1-best[0].first<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}

 
