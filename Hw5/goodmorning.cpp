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

int grid[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};
set<int> all;
void dfs(string s,int x,int y){
    if(s.size()>3)return;
    if(s.size()){
        int cnt=0,k=1;
        //cout<<s<<endl;
        reverse(all(s));
        for(auto it:s){
            cnt+=k*(it-'0');
            k*=10;
        }
        all.insert(cnt);
        reverse(all(s));
    }
    //cout<<s<<' '<<x<<' '<<y<<endl;
    if((x > 3 || y > 2) || (x==3 && y==2) || (x==3 && y==0))return;
    dfs(s+char(grid[x][y]+'0'),x,y);
    if(x < 3)dfs(s+char(grid[x][y]+'0'),x+1,y);
    if(y < 2)dfs(s+char(grid[x][y]+'0'),x,y+1);
    if(x < 3)dfs(s,x+1,y);
    if(y < 2)dfs(s,x,y+1);
}

void solve(){
    int k,ans=100000;cin>>k;
    for(auto it:all){
        if(abs(it-k) < abs(ans-k)){
            ans=it;;
        }
    }
    cout<<ans<<endl;
}

int main(){
    INITIO()
    dfs("",0,0);
    //cout<<all.size()<<endl;
    //for(auto it:all)cout<<it<<endl;
    int t;cin>>t;
    for(int kase=1;kase<=t;kase++){
        solve();
    }
    return 0;
}
