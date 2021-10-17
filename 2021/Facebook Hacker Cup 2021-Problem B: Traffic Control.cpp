/*
 Programmer : Anamaria Andra Pescaru 
 Link to the problem : https://www.facebook.com/codingcompetitions/hacker-cup/2021/round-1/problems/B
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fcin("input.txt");
ofstream fcout("output.txt");
// #define cin fcin
// #define cout fcout

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cout<<fixed<<setprecision(15);

    int test;
    cin>>test;

    for(int pp = 1;pp <= test;pp++){
        cout<<"Case #"<<pp<<": ";
        int n, m, a, b;
        cin>>n>>m>>a>>b;
        if(n + m - 1 > a || n + m - 1 > b)
        cout<<"Impossible"<<endl;
        else{
            cout<<"Possible"<<endl;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                    if(i == 1 && j == 1){
                        cout<<a - n - m + 2<<" ";
                        continue;
                    }
                    if(i == 1 && j != 1){
                        cout<<1<<" ";
                        continue;
                    }
                    if(j == m ){
                        cout<<1<<" ";
                        continue;
                    }
                    if(i == n && j != 1){
                        cout<<1<<" ";
                        continue;
                    }
                    if(i == n && j == 1){
                        cout<<b - n - m + 2<<" ";
                        continue;
                    }
                    cout<<1<<" ";
                }
                cout<<endl;
            }
        }
        
    }

	return 0;
}
