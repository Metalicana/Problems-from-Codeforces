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
char c[500005];
int chi[26];
int bb[26];
bool checked[26];
void solve(int test)
{
  scanf("%s",c);
  memset(chi,0,sizeof chi);
  memset(bb,0,sizeof bb);
  memset(checked,0,sizeof checked);
  int len = strlen(c);
  stack<char>ans;
  queue<char>what;
  vector<char>fin;
  for(int i=len-1;i>=0;i--)
  {
    chi[c[i]-'a']++;
    if(!checked[c[i]-'a'])
    {
      checked[c[i]-'a']=1;
      ans.push(c[i]);
      what.push(c[i]);
    }
  }
  int tote = ans.sz;
  bool flag=0;
  int pagol = tote;
//  trace(tote)
  while(!what.empty())
  {
    if(chi[what.front()-'a'] % tote !=0)
    {
      //cout << "bruh";
      flag = 1;
      break;
    }
    bb[what.front()-'a'] = chi[what.front()-'a']/ tote;
    //trace(bb[what.front()-'a'])
    tote--;
    what.pop();
  }
  if(flag)
  {
    printf("-1\n");
    return;
  }
  memset(chi,0,sizeof chi);
  flag=0;
  int pagolto;
  for(int i=0;i<len;i++)
  {
    chi[c[i]-'a']++;
    pagolto=0;
    for(int q=0;q<26;q++)
    {
      if(chi[q]>bb[q])
      {
      //  cout << "bruh" << " " << i << endl;
        printf("-1\n");
        return;
      }
      else if(chi[q]==bb[q] && bb[q]!=0)pagolto++;
    }
    //trace(pagolto)
    if(pagolto == pagol)
    {
      vector<char>plswork;
      for(int q=0;q<=i;q++)
      {
        plswork.pb(c[q]);
        //printf("%c",c[q]);
      }
      vector<int>fin;
      while(!ans.empty())
      {
        fin.pb(ans.top());
        //printf("%c",ans.top());
        ans.pop();
      }
      for(int q=0,r=0;q<len;r++)
      {
        int s=0;
        while(s<plswork.sz)
        {
          if(plswork[s]!=c[q++])
          {
            printf("-1\n");
            return;
          }
          s++;
        }
        plswork.erase(remove(plswork.begin(), plswork.end(), fin[r]), plswork.end());
      }
      for(int q=0;q<=i;q++)printf("%c",c[q]);
      printf(" ");
      for(auto hayre : fin)
      {
        printf("%c",hayre);
      }
      printf("\n");

      return;

    }
  }
  printf("-1\n");

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
