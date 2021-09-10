#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int MAX = 26;
struct TrieNode{
    TrieNode* children[MAX];
    bool isEnd;
    int weight;
};
TrieNode* newnode(){
    TrieNode* root = new TrieNode();
    for(int i=0;i<MAX;i++){
        root->children[i] = NULL;
    }
    root->isEnd = false;
    root->weight = 0;
    return root;
}
int findMax(TrieNode* node, int &maxval){
    TrieNode* root = node;
    if(root->isEnd)
        maxval = max(maxval, root->weight);
    int flag = 0;
    for(int i=0;i<MAX;i++){
        if(root->children[i]){
            flag = 1;
        }
    }
    if(!flag){
        return max(root->weight, maxval);
    }
    else{
        for(int i=0;i<MAX;i++){
            if(root->children[i]){
                maxval = max(maxval, findMax(root->children[i], maxval));
            }
        }
    }
    return maxval;
}
void insert(string s, int w, TrieNode* node){
    TrieNode* root = node;
    for(unsigned int i=0;i<s.length();i++){
        int idx = s[i] - 'a';
        if(!root->children[idx]){
            root->children[idx] = newnode();
        }
        root = root->children[idx];
    }
    root->isEnd = true;
    root->weight = w;
}
int search(string s, TrieNode* node){
    TrieNode* root = node;
    for(unsigned int i=0;i<s.length();i++){
        int idx = s[i] - 'a';
        if(!root->children[idx]){
            return -1;
        }
        root = root->children[idx];
    }
    int ans = -1;
    ans = findMax(root, ans);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,w;
    unordered_map<string, int> mp;
    cin>>n>>q;
    string s;
    TrieNode* root = newnode();
    while(n--){
        cin>>s>>w;
        insert(s, w, root);
    }
    while(q--){
        cin>>s;
        if(mp.find(s)!=mp.end()){
            cout<<mp[s]<<endl;
        }
        else{
            int ans = search(s, root);
            mp[s] = ans;
            cout<<ans<<endl;
        }
    }
}