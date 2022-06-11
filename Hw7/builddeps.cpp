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

void dfs(string tar, vector<string> &ans, map<string,set<string>> &mp, map<string,bool> &vis){
    if(vis[tar])return;
    vis[tar]=1;
    for(auto it:mp[tar])dfs(it, ans, mp, vis);
    ans.pb(tar);
}

void solve(){
    int n;cin>>n;
    string s,tar;
    map<string,set<string>> mp;
    map<string,bool> vis;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        string c,g; int bre=0;
        for(int i=0;i<sz(s);i++){
            if(s[i]==':'){vis[c]=0;bre=1;}
            if(s[i]==' ' && bre && sz(g)){
                if(!vis.count(g))vis[g]=0;
                mp[g].insert(c);
                g.clear();
            }
            if(s[i]>='a' && s[i]<='z'){
                if(bre) g+=s[i];
                else c+=s[i];
            }
        }
        if(sz(g)){
            mp[g].insert(c);
        }
    }
    cin>>tar;
    vector<string> ans;
    dfs(tar,ans,mp,vis);
    reverse(all(ans));
    for(auto it:ans)cout<<it<<endl;
}

int main(){
    INITIO()
    //while(cin>>n && n){
        solve();
    //}
    return 0;
}

 
