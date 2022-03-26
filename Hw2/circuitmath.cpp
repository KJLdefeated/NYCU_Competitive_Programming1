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

void solve(){
    
}

int main(){
    INITIO()
    int n;
    cin>>n;
    map<char,int> mp;
    for(int i=0;i<n;i++){
        char a;cin>>a;
        if(a=='T')mp[char('A'+i)]=1;
        else mp[char('A'+i)]=0;
    }
    string s;
    getline(cin,s);
    getline(cin,s);
    stack<int> a;
    for(int i=0;i<sz(s);i++){
        if(s[i]!=' '){
            if(s[i]=='*'){
                int p=a.top();a.pop();
                int k=a.top();a.pop();
                a.push(p&k);
            }
            else if(s[i]=='+'){
                int p=a.top();a.pop();
                int k=a.top();a.pop();
                a.push(p|k);
            }
            else if(s[i]=='-'){
                int p=a.top();
                a.pop();
                a.push(!p);
            }
            else{
                a.push(mp[s[i]]);
            }
        }
    }
    cout<<(a.top()?'T':'F')<<endl;
    return 0;
}
