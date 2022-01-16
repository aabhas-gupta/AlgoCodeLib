#include<bits/stdc++.h>
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

bool search(string s, TrieNode* node){
    TrieNode* root = node;
    for(unsigned int i=0;i<s.length();i++){
        int idx = s[i] - 'a';
        if(!root->children[idx]){
            return false;
        }
        root = root->children[idx];
    }
    return true;
}

int main(){
    int n,w;
    string s;
    cin>>n;
    TrieNode* root = newnode();
    while(n--){
        cin>>s>>w;
        insert(s, w, root);
    }
    return 0;
}