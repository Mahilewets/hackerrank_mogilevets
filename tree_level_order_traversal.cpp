#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

vector<int> tr_order[1000];

void dfs(int l, Node *v)
{
    if(!v)
    {
        return;
    }
    tr_order[l].push_back(v->data);
    dfs(l+1,v->left);
    dfs(l+1,v->right);
}



    void levelOrder(Node * root) {
        dfs(0,root);
        for(int i = 0; i < 1000; ++i)
        {
            for(auto x: tr_order[i])
            {
                cout<<x<<" ";
            }
        }
    }

}; //End of Solution
