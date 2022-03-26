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
const int dx[6] = {0, 1, 1, 0, -1, -1};
const int dy[6] = {1, 0, -1, -1, 0, 1};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
int sub(int a, int b) {return (a - b) % 6 + ((a >= b) ? 0 : 6);}
// -----------------------------------------------------------------------------------------------------
int e,d;
vector<int> a,b;
string dp[100][100],cc,dd;
/*
0 1 0 1 0 1 0 1 0 1 0 1 99 99
20 20
*/

string add_str(string a,string b){
    int cnt=0;
    reverse(all(a));
    reverse(all(b));
    if(sz(a) < sz(b))swap(a,b);
    while(sz(b) < sz(a))b+='0';
    string ans="";
    for(int i=0;i<sz(a);i++){
        cnt = cnt + (a[i]-'0') + (b[i]-'0');
        ans.pb(char(cnt%10+'0'));
        cnt/=10;
    }
    if(cnt)ans.pb(char(cnt+'0'));
    reverse(all(ans));
    return ans;
}

string dfs(int x,int y){
    if(x<=0 || y<=0)return dd;
    if(dp[x][y]!="-1")return dp[x][y];
    dp[x][y]=cc;
    for(int i=0;i<sz(a);i+=2){
        dp[x][y] = add_str(dp[x][y],dfs(x-a[i], y-a[i+1]));
    }
    
    return dp[x][y];
}

void solve(){
    string s,k,c;
    //cin.ignore('\n');
    //getline(cin,s);
    getline(cin,s);
    getline(cin,k);
    a.clear();b.clear();
    for(int i=0;i<100;i++)for(int j=0;j<100;j++)dp[i][j]="-1";
    s+=' ';
    for(int i=0;i<sz(s);i++){
        if(s[i]==' '){
            reverse(all(c));
            int x=0;
            for(int j=0,k=1;j<sz(c);j++, k*=10){
                x+=(c[j]-'0')*k;
            }
            a.pb(x);
            c="";
        }
        else c+=s[i];
    }
    s=k;
    s+=' ';
    for(int i=0;i<sz(s);i++){
        if(s[i]==' '){
            reverse(all(c));
            int x=0;
            for(int j=0,k=1;j<sz(c);j++, k*=10){
                x+=(c[j]-'0')*k;
            }
            b.pb(x);
            c="";
        }
        else c+=s[i];
    }
    d = a[sz(a)-1];
    a.pop_back();
    e = a[sz(a)-1];
    a.pop_back();
    stringstream ss;
    ss << d;
    dd = ss.str();
    stringstream nn;
    nn << e;
    cc = nn.str();
    for(int i=0;i<sz(b);i+=2){
        cout<<dfs(b[i],b[i+1])<<endl;
    }
    cout<<endl;
}

int main(){
    INITIO()
    int t;cin>>t;string s;getline(cin,s);
    while(t--){
        solve();
    }
    return 0;
}
