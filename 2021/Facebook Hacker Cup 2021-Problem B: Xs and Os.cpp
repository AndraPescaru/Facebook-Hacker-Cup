/*
 Programmer : Anamaria Andra Pescaru 
 Link to the problem : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fcin("input.txt");
ofstream fcout("output.txt");

#define cin fcin
#define cout fcout
char s[52][52];
int v[3000];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(15);
    
    
    int test;
    int p = 1;
    cin>>test;
   
    while(test--){
        
        cout<<"Case #"<<p<<": ";
        int n;
      cin>>n;
      int i, j;
      for(i = 0; i < n; i ++){
          for(j = 0; j < n; j ++){
              cin>>s[i][j];
          }
      }
      int  jj = 0;
      int sum = 0, ok = 1, k = 1;
      for(i = 0; i < n; i ++){
          sum = 0, ok = 1;
          for(j = 0; j < n && ok; j ++){
              if(s[i][j] == '.')
              sum++, jj =j;
              if(s[i][j] == 'O')
              ok = 0;
          }
          if(ok)
          if(sum == 1){
              sum = 0;
              ok = 1;
              int l;
              for(l = 0; l < n && ok;l ++){
                  if(s[l][jj] == '.')
                  sum ++;
                  if(s[l][jj] == 'O')
                  ok = 0;
              }
              
              if(sum != 1 && ok)
              v[k++] = 1;
              if(!ok)
              v[k++] = 1;
          }
          else
          v[k++] = sum;
      }
      for(i = 0; i < n; i ++){
          sum = 0, ok = 1;
          for(j = 0; j < n && ok; j ++){
              if(s[j][i] == '.')
              sum++;
              if(s[j][i] == 'O')
              ok = 0;
          }
          if(ok)
          v[k++] = sum;
      }
      k--;
      if(k){
          int mini = v[1];
      sum = 0;
      for(i = 2;i <= k; i++)
      mini = min(mini,v[i]);
      for(i = 1;i <= k; i++)
      if(v[i] == mini)
      sum ++;
      cout<<mini<<" "<<sum<<endl;
      }
      else
      cout<<"Impossible\n";
      p++;

    }
    
	return 0;
}
