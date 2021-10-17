/*
 Programmer : Anamaria Andra Pescaru 
 Link to the problem : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/A1
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fcin("input.txt");
ofstream fcout("output.txt");
// #define cin fcin
// #define cout fcout
char s[800002];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(15);

    int test;
    cin>>test;

    for(int pp = 1;pp <= test;pp++){
        cout<<"Case #"<<pp<<": ";
        int n;
        cin>>n;
        cin>>s;
        int sum = 0, sx = 0, so = 0;
        if(n == 1)
        cout<<0<<endl;
        else{
            for(int i = 0;i < n - 1;++i){
            if(s[i] == 'X')
            sx++;
            if(s[i] == 'O')
            so++;
            if(s[i] == 'X' && s[i + 1] == 'O'){
                sum++;
                sx = 0;
                continue;
            }
            if(s[i] == 'O' && s[i + 1] == 'X'){
                sum++;
                so = 0;
                continue;
            }
            if(s[i] == 'F' && s[i + 1] == 'X'){
                if(so)
                {
                    so = 0;
                    sum++;
                    continue;
                }
            }
            if(s[i] == 'F' && s[i + 1] == 'O'){
                if(sx)
                {
                    sx = 0;
                    sum++;
                    continue;
                }
            }

            }
            cout<<sum<<endl;
        }
        
    }

	return 0;
}
