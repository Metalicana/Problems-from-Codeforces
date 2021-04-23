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
struct node
{
  int x,y;
  ll len;
}ara[20005];
bool bruh(node a, node b)
{
  return a.len < b.len;
}
int m,n,row,col;
vector<ll> path[105];
ll runner[105][105];
bool mark[105][105];
bool runner_mark[105][105];//ith runner's j'th row is done
ll x,q;
void solve(int test)
{
  scanf("%d%d",&n,&m);
  memset(mark,0,sizeof mark);
  memset(runner_mark,0,sizeof runner_mark);
  q=0;
  node g;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      scanf("%I64d",&x);
      path[i].pb(x);
      g.x = i;
      g.y = j;
      g.len = x;
      ara[q++] = g;
    }
  }
  sort(ara,ara+q,bruh);
  for(int i=0;i<m;i++)
  {
    runner[i][ara[i].x]= ara[i].len;
    mark[ara[i].x][ara[i].y]=1;
    runner_mark[i][ara[i].x]=1;
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(runner_mark[i][j]==1)continue;
      runner_mark[i][j]=1;
      for(int k=0;k<m;k++)
      {
        if(mark[j][k]==0)
        {
          mark[j][k]=1;
          runner[i][j] = path[j][k];
          break;
        }
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      printf("%I64d",runner[j][i]);
      if(j!=m-1)printf(" ");
      else printf("\n");
    }
  }

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int i=0;i<105;i++)
    {
      path[i].clear();
    }
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
