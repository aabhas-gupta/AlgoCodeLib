#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void rabin_karp(string txt, string pat) {
    int  m = pat.length();
    int  n = txt.length();
    const int p = 31;
    const int MOD = 1e9 + 9;
    
    vector<long long> powers(max(n, m)); 
    powers[0] = 1; 
    for (int i = 1; i < (int)powers.size(); i++) 
        powers[i] = (powers[i-1] * p) % MOD;
    
    vector<long long> hash(n + 1, 0); 
    for (int i = 0; i < n; i++)
        hash[i+1] = (hash[i] + (txt[i] - 'a' + 1) * powers[i]) % MOD; 
    long long hash_pat = 0; 
    for (int i = 0; i < m; i++) 
        hash_pat = (hash_pat + (pat[i] - 'a' + 1) * powers[i]) % MOD; 

    for (int i = 0; i + m - 1 < n; i++) { 
        long long cur_h = (hash[i+m] + MOD - hash[i]) % MOD; 
        if (cur_h == hash_pat * powers[i] % MOD)
            ans.push_back(i);
    }
}
int main(){
    string txt, pat;
    cin>>txt>>pat;
    rabin_karp(txt, pat);
    if(ans.size() == 0)
        cout<<-1;
    else{
        for(auto x : ans)
            cout<<x<<endl;
    }
}