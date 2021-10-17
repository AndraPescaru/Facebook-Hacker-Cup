/*
 Programmer : Anamaria Andra Pescaru 
 Link to the problem : https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fcin("input.txt");
ofstream fcout("output.txt");

//#define cin fcin
//#define cout fcout

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(15);
    
    
    int test;
    cin>>test;
    string s;
    int p = 1;
    while(test--){
       cout<<"Case #"<<p<<": ";
       cin>>s;
       if( !s[1])
       cout<<0<<endl;
       else{
           int nr1 = 0, nr2 = 0;
       for(int i = 0; s[i]; i ++)
       if(strchr("AEIOU",s[i]))
       nr1++;
       else
       nr2++;
       if(nr1 == 0)
       cout<<nr2<<endl;
       if(nr2 == 0)
       cout<<nr1<<endl;
       if(nr1 != 0 && nr2 != 0){
           sort(s.begin(), s.end());
       int i, j, sum = 0, v = 0, c = 0, min = 5000;
       for(i = 0; s[i] ; i++){
            v = 0, c = 0;
            if(strchr("AEIOU",s[i]))
               v = 1, c = 0;
               else
               c = 1, v = 0;
           for(j = 0; s[j]; j ++){
               if(s[i] != s[j]){
                   if(v){
                       if(strchr("AEIOU",s[j]))
                       sum += 2;
                       else
                       sum ++;
                   }
                   else{
                       if(strchr("AEIOU",s[j]))
                       sum ++;
                       else
                       sum += 2;
                   }
               }
               
           }
           if(s[i+1] && s[i+1] == s[i])
           i++;
           
           if( min > sum)
           min = sum;
           sum  = 0;
       }

       cout<<min<<endl;
       }
       }
       ++p;
    }
    
	return 0;
}
