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
#define INITIO()
#endif
#define MEM(i,j) memset(i,j,sizeof i);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define sz(a) (int)a.size()
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
const double Eps  = 1e-8;
const int Inf     = 1e9+9;
const int Mod     = 1e9+9;
const int N       = 1e6+9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll x, ll y){if( y==0 )return x;return gcd( y, x%y );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}

// -----------------------------------------------------------------------------------------------------
char a[101][101];
int n,m,cnt=0;
int ox=0,oy=0,dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,-1,-1,-1,0,1,1,1};

void dfs(int x,int y){
    a[x][y]='.';
    FOR(i,0,8)if(a[x+dx[i]][y+dy[i]] == '#'){
        dfs(x+dx[i],y+dy[i]);
        return;
    }
    FOR(i,0,8)if(x+dx[i]==ox && y+dy[i]==oy){
        cnt++;
        break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
    cin>>n>>m;
    FOR(i,1,n+1)FOR(j,1,m+1)cin>>a[i][j];
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            if(a[i][j]=='#'){
                ox=i;oy=j;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
