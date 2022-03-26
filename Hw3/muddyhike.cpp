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
#define sz(a)       (int)a.size()
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
const int Mod     = 1e9+7;
const int N       = 1e5+9;
const int dx[4] = {0, 1,  0, -1};
const int dy[4] = {1, 0, -1,  0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
int sub(int a, int b) {return (a - b) % 6 + ((a >= b) ? 0 : 6);}
// ----------------------------------------------------------------------------------------------------
int n,m,a[1005][1005]={},vis[1005][1005]={},bst[1005][1005]={};
struct p{
    int val,x,y;
};
void solve(){
    cin>>n>>m;
    FOR(i,0,n)FOR(j,1,m+1)cin>>a[i][j];
    FOR(i,0,n+1)FOR(j,0,m+2)bst[i][j]=1000005;
    bst[0][0]=0;
    set<tuple<int,int,int>> s;
    s.insert({0,0,0});
    while(!s.empty()){
        int x = get<1>(*s.begin()), y = get<2>(*s.begin());
        s.erase(*s.begin());
        for(int i=0;i<4;i++){
            int fx=x+dx[i],fy=y+dy[i];
            if(fx>=0 && fx<n && fy>=0 && fy<m+2){
                int nexval = max(bst[x][y], a[fx][fy]);
                if(nexval < bst[fx][fy]){
                    bst[fx][fy]=nexval;
                    s.insert({nexval, fx, fy});
                }
            }
        }
    }
    cout<<bst[0][m+1]<<endl;
}

int main(){
    INITIO()
    //int t;
    //while(t--){
        solve();
    //}
    return 0;
}
