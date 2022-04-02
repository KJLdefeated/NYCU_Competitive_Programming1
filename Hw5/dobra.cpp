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

set<char> vow = {'A','E','I','O','U'};

ll dfs(string &s,int id){
    ll ans=0;
    if(id == s.size()){
        for(auto it:s){
            if(it=='L')return 1;
        }
        return 0;
    }
    //cout<<s<<endl;
    if(s[id] == '_'){
        if(id < 2 || (id >= 2 && (s[id-1]=='2' || s[id-2]=='2'))){
            s[id]='1';
            ans += dfs(s,id+1)*20;
        }
        s[id]='_';
        if(id < 2 || (id >= 2 && (s[id-1]=='1' || s[id-1]=='L' || s[id-2]=='1' || s[id-2]=='L'))){
            s[id]='2';
            ans += dfs(s,id+1)*5;
        }
        s[id]='_';
        if(id < 2 || (id >= 2 && (s[id-1]=='2' || s[id-2]=='2'))){
            s[id]='L';
            ans += dfs(s,id+1);
        }
        s[id]='_';
    }
    else{
        if(id >= 2 && s[id] == '2' && s[id-1] == '2' && s[id-2] == '2') return 0;
        if(id >= 2 && (s[id] == '1'||s[id]=='L') && (s[id-1] == '1'||s[id-1]=='L') && (s[id-2] == '1'||s[id-2]=='L'))
            return 0;
        ans = dfs(s,id+1);
    }
    
    return ans;
}

void solve(){
    string s;
    cin>>s;
    for(auto &it:s){
        if(it == 'L' || it=='_')continue;
        if(vow.count(it))it='2';
        else it='1';
    }
    cout<<dfs(s,0)<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
