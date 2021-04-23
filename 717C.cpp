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

int m,n,row,col;
int ara[105];
int dp[105][100005];
int sum;
int call(int i,int make)
{
  if(i>=n)
  {
    if(make==0)return 1;
    return 0;
  }
  if(dp[i][make]!=-1)return dp[i][make];
  int p1=0,p2=0;
  if(make-ara[i]>=0)p1=call(i+1,make-ara[i]);
  p2 = call(i+1,make);
  dp[i][make] = p1 | p2;
  return dp[i][make];
}
int possible(int make)
{
  memset(dp,-1,sizeof dp);
  return call(0,make);
}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&ara[i]);
  sum = 0;
  for(int i=0;i<n;i++)sum+=ara[i];
  if(sum%2==1)
  {
    printf("0\n");
  }
  else
  {
    sum=sum/2;
    if(possible(sum))
    {
      int minx = 3000;
      int minidx;
      while(true)
      {
        for(int i=0;i<n;i++)
        {
          if(ara[i]%2==1)
          {
            printf("1\n%d\n",i+1);
            return;
          }
          ara[i]/=2;
        }
      }
    }
    else printf("0\n");
  }
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
