#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void gen(int n,string out,int ld) {
    if(n==0) {
        cout<<out<<endl;
        return;
    }
    //Very important technique - Don't make out something but just keep on adding charachters to it.
    gen(n-1,out+'0',0);
    if(ld==0)               
        gen(n-1,out+'1',1);
}


int main() {
	int n;
	cin>>n;
	string out="";
	gen(n,out,0);
}
