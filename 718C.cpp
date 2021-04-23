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
/*for(int i=1;i<=5;i++)
{
  for(int j=1;i+j-1<=5;j++)
  {
    cout << "(" << i+j-1 << "," << j << ")" << " ";
  }
  cout << endl;
}*/
int grid[505][505];
int ara[505];
void solve(int test)
{
  scanf("%d",&n);
  memset(grid,0,sizeof grid);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&ara[i]);
    grid[i][i]=ara[i];
  }
  int l,r;
  bool pls=0;
  bool ehhe=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;i+j-1<=n;j++)
    {
      //check left check right, check permutation
      l = i+j-1;
      r = j;
      if(grid[l][r] == i)continue;
      pls=0;
      if(r-1 >=1 && grid[l][r-1]==0)
      {
        grid[l][r-1]=grid[l][r];
        pls=1;
      }
      else if(l+1<=n && grid[l+1][r]==0)
      {
        grid[l+1][r]=grid[l][r];
        pls=1;
      }
      if(!pls)
      {
        ehhe=1;
        break;
      }
    }
    if(ehhe)break;
  }
  if(ehhe)printf("-1\n");
  else
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=i;j++)
      {
        printf("%d",grid[i][j]);
        if(j==i)printf("\n");
        else printf(" ");
      }
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
