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
char s[55];
char grid[55][55];
void solve(int test)
{
  scanf("%d%s",&n,s);
  int a=0,b=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='2')a++;
    else b++;
  }
  if(a==0 || a> 2)
  {
    //list up all the uh 2's
    //cyclically do it
    vector<int> cyc;
    for(int i=0;i<n;i++)
    {
      for(int q=0;q<n;q++)grid[i][q]='=';
    }
    for(int i=0;i<n;i++)
    {
      if(s[i]=='2')cyc.pb(i);
    }
    if((int)cyc.sz > 0)
    {
      for(int i=0;i<cyc.sz-1;i++)
      {
        grid[cyc[i]][cyc[i+1]]='+';
        grid[cyc[i+1]][cyc[i]]='-';
      }
      grid[cyc[cyc.sz-1]][cyc[0]]='+';
      grid[cyc[0]][cyc[cyc.sz-1]]='-';
    }
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        if(i== j)grid[i][j]='X';
        else if(s[i]=='1' || s[j]=='1')
        {
          grid[i][j] = grid[j][i]= '=';
        }
      }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        printf("%c",grid[i][j]);
      }
      printf("\n");
    }

  }
  else printf("NO\n");
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
