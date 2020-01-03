/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool checkBst(Node *root, int l, int r)
    {
        if(!root)
        {
            return true;
        }
        
        if(l > root->data || r < root->data)
        {
            return false;
        }
        
        return checkBst(root->left, l, root->data - 1) && checkBst(root->right, root->data + 1, r);
    }

	bool checkBST(Node* root) {
        #include<climits>
        return checkBst(root, INT_MIN, INT_MAX);
	}
