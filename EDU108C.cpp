#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define gap ' '
#define nl printf("\n")
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define eps 1e-9
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}

ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int m,n,row,col,x;
vector<ll> vec[200005];
vector<ll> vec2[200005];
vector<ll> sizes;
bool size_flag[200005];
int belong[200005];
ll val;
bool ulta(ll a, ll b)
{
  return a>b;
}

void solve(int test)
{
  scanf("%d",&n);
  for(int q=0;q<=n;q++)vec[q].clear(),vec2[q].clear();
  sizes.clear();
  memset(size_flag,0,n+2);

  for(int q=0;q<n;q++)scanf("%d",&belong[q]);

  for(int q=0;q<n;q++)
  {
    scanf("%I64d",&val);
    vec[belong[q]].pb(val);
  }
  for(int q=1;q<=n;q++)
  {
    x = (int)vec[q].sz;
    if(!size_flag[x])
    {
      sizes.pb(x);
      size_flag[x]=true;
      vec2[x].resize(x);
      fill(vec2[x].begin(),vec2[x].end(),0);
    }
    sort(vec[q].begin(),vec[q].end(),ulta);
    for(int w=0;w<x;w++)vec2[x][w]+=vec[q][w];
  }
  for(auto size_val : sizes)
  {
    for(int q=0;q<size_val;q++)vec2[size_val][q] += (q==0 ? 0 : vec2[size_val][q-1]);
  }

  for(int q=1;q<=n;q++)
  {
    val = 0;
    for(auto size_val : sizes)
    {
      val += (q>size_val?0:vec2[size_val][size_val - size_val%q - 1]);
    }
    printf("%I64d ",val);
  }
  nl;



}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
