#include<iostream>
#include<string>
using namespace std;

string deal_str(string s, int &e, int n){
    while(s.length()>0 && s[0] == '0'){//delete leading '0'
        s.erase(s.begin());
    }
    if(s[0] == '.'){//num < 1
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0'){//delete leading '0' and count index
            s.erase(s.begin());
            e--;
        }
    }
    else{//num > 1
        int k = 0;
        while(k<s.length() && s[k]!='.'){//count index
            k++;
            e++;
        }
        if(k<s.length()){//find '.'
            s.erase(s.begin()+k);
        }
    }
    if(s.length() == 0){
        e = 0;
    }

    int num = 0;
    int k = 0;
    string res;
    while(num < n){
        if(k<s.length()) res+=s[k++];
        else res+='0';
        num++;
    }
    return res;
}

int main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n, e1, e2 = 0;
    string num1, num2;
    while(cin >> n >> num1 >> num2){
        e1 = e2 = 0;
        string res1 = deal_str(num1, e1, n);
        string res2 = deal_str(num2, e2, n);
        if(res1 == res2 && e1 == e2){
            cout<<"YES 0."<<res1<<"*10^"<<e1<<endl;
        }
        else{
            cout<<"NO 0."<<res1<<"*10^"<<e1<<" 0."<<res2<<"*10^"<<e2<<endl;
        }
    }
    return 0;
}