#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void compute(int lps[], string pat, int m){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string txt, string pat){
    int  m = pat.length();
    int  n = txt.length();
    int lps[m];
    compute(lps, pat, m);
    int i = 0;
    int j = 0;
    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == m){
            ans.push_back(i-j);
            j = lps[j-1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main(){
    string txt, pat;
    cin>>txt>>pat;
    kmp(txt, pat);
    if(ans.size() == 0)
        cout<<-1;
    else{
        for(auto x : ans)
            cout<<x<<endl;
    }
}
