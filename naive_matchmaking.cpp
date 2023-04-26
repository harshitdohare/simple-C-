#include <bits/stdc++.h>
using namespace std;

void naive_matchmaking(string a,string b){

    int m = a.length();
    int n = b.length();
    
    for (int i = 0; i <(m-n)+1; i++)
    {   
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i+j]==b[j])
                count++;
            else
                break;    

        }
        if (count == n)
            cout<<i<<endl;
    }
}    

int main(){

    string text = "abcabdbdacdbda";
    string pattern = "bda";
    naive_matchmaking(text,pattern);

    return 0;
}
