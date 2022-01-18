#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;
int root[MAXN];
int weight[MAXN];

void init(){
    for(int i=0;i<=MAXN;i++){
        root[i] = i;
        weight[i] = 1;
    }
}

int find(int x){
    if(x == root[x])
        return x;
    return root[x] = find(root[x]);
}

void union1(int x, int y){
    int rootx = root[x];
    int rooty = root[y];
    if(rootx != rooty){
        if(weight[x] > weight[y])
        root[rooty] = rootx;
        else if(weight[x] < weight[y])
            root[rootx] = rooty;
        else{
            root[rooty] = rootx;
            weight[rootx] += 1;
        }
    }
}

bool isConnected(int x, int y){
    return find(x) == find(y);
}

int main(){
    init();
    union1(1,2);
    union1(2,3);
    union1(4,5);
    cout<<isConnected(1,4)<<endl; //false
    cout<<isConnected(1,3)<<endl; //true
}
