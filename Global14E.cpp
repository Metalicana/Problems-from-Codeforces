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
ll add(ll a, ll b,ll m)
{
  if(a+b<m)return a+b;
  return (a+b)%m;
}
ll mul(ll a, ll b,ll m)
{
  if(a*b < m)return a*b;
  return (a*b)%m;
}
ll power(ll a, ll b, ll m)
{
  if(b==0)return 1;
  if(b==1)return a%m;
  ll p = power(a,b/2,m);
  p = mul(p,p,m);
  if(b%2==0)return p;
  return mul(p,a,m);
}

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

ll m,n,row,col;
ll fact[405],invFact[405];
ll memo[405][405];
void solve(int test)
{
  memset(memo,0,sizeof memo);
  scanf("%I64d%I64d",&n,&m);
  fact[0]=1;
  invFact[0]=1;
  for(ll i=1;i<=n;i++)fact[i] = mul(i,fact[i-1],m),invFact[i] = power(fact[i],m-2,m);
  for(ll i=2;i<=n+1;i++)memo[i][i-1] =power(2ll,i-2,m);
  ll temp;
  ll pew;
  ll die;
  for(ll len=2;len<=n+1;len++)
  {
    for(ll cnt=len-1;cnt>=1;cnt--)
    {
      for(ll k=1;len+k<=n;k++)
      {
        pew = power(2ll,k-1,m);//2^k-1
        die = mul(fact[cnt+k],mul(invFact[cnt],invFact[k],m),m);//ncr
        temp = mul(pew,die,m);
        temp = mul(memo[len][cnt],temp,m);
        memo[len+k+1][cnt+k] = add(memo[len+k+1][cnt+k],temp,m);
      }
    }
  }
  ll ans =0;
  for(ll i=1;i<=n;i++)ans = add(ans, memo[n+1][i],m);
  cout << ans << endl;



}
void test()
{
  int t=1;
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
