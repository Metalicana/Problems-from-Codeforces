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
#define newline printf("\n");
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

int m,n,row,col,k,s;
int cost[2][2][505][505];
int cur_cost[2][505][505];
bool legit(int x,int y)
{
  return x>=0&&y>=0&&x<n&&y<m;
}
void solve(int test)
{
  scanf("%d%d%d",&n,&m,&k);
  for(int q=0;q<2;q++)
  {
    for(int i=0;i<n-q;i++)
    {
      for(int j=0;j<m-(q^1);j++)
      {
        scanf("%d",&cost[q][0][i][j]);
        cost[q][1][i+q][j+(q^1)]=cost[q][0][i][j];
      }
    }
  }
  if(k%2==1)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        printf("-1 ");
      }
      newline
    }
  }
  else
  {
    memset(cur_cost,0,sizeof cur_cost);
    int cst=1000000000;
    int gi,gj,a,b;
    for(int q=2;q<=k;q+=2)
    {
      s=(q/2)%2;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          cst=1000000000;
          for(int p=0;p<4;p++)
          {
            gi = i + dir4[0][p];
            gj = j + dir4[1][p];
            if(legit(gi,gj)) cst = min(cst,2*cost[gi!=i?1:0][gi<i||gj<j?1:0][i][j] +cur_cost[s^1][gi][gj]);
          }
          cur_cost[s][i][j] = cst;
        }
      }
    }
    s = (k/2)%2;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        printf("%d ",cur_cost[s][i][j]);
      }
      newline
    }
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
