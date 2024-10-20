#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct node{
    int left;
    int right;
};
vector<node>tree(1000000, {0,0});

void postorder(int now){
    if(tree[now].left)postorder(tree[now].left);
    if(tree[now].right)postorder(tree[now].right);
    cout << now << "\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int tmp, par=0, root;
    stack<int>st;
    cin>>tmp;
    root = tmp;
    st.push(tmp);
    while(cin>>tmp){
        if(st.top()>tmp)
            tree[st.top()].left=tmp;
        else{
            while(st.size() && st.top()<tmp){
                par = st.top();
                st.pop();
            }
            tree[par].right=tmp;
        }
        st.push(tmp); 
    }

    postorder(root);
}