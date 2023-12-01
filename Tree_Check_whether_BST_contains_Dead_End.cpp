//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void find_all_nodes(Node*root,map<int,int>&allnodes)
    {
        if(root == NULL)
        return ;
        
        allnodes[root->data]=1;
        find_all_nodes(root->left,allnodes);
        find_all_nodes(root->right,allnodes);
    }
    bool check(Node*root,map<int,int>&all_nodes)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)
        {
            int prev=root->data-1;
            int next=root->data+1;
            
            if(all_nodes.find(prev)!=all_nodes.end() && all_nodes.find(next)!=all_nodes.end())
            {
                return true;
            }
        }
        return check(root->left,all_nodes) or check(root->right,all_nodes);
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        if(root==NULL)
        {
            return false;
        }
        map<int,int>all_nodes;
        all_nodes[0]=1;
        find_all_nodes(root,all_nodes);
        return check(root,all_nodes);
        
    }
//     void storeNodes(Node * root, unordered_set<int> &all_nodes,
//                           unordered_set<int> &leaf_nodes)
// {
//     if (root == NULL)
//         return ;
 
//     // store all node of binary search tree
//     all_nodes.insert(root->data);
 
//     // store leaf node in leaf_hash
//     if (root->left==NULL && root->right==NULL)
//     {
//         leaf_nodes.insert(root->data);
//         return ;
//     }
 
//     // recur call rest tree
//     storeNodes(root-> left, all_nodes, leaf_nodes);
//     storeNodes(root->right, all_nodes, leaf_nodes);
// }
 
// // Returns true if there is a dead end in tree,
// // else false.
// bool isDeadEnd(Node *root)
// {
//     // Base case
//     if (root == NULL)
//         return false ;
 
//     // create two empty hash sets that store all
//     // BST elements and leaf nodes respectively.
//     unordered_set<int> all_nodes, leaf_nodes;
 
//     // insert 0 in 'all_nodes' for handle case
//     // if bst contain value 1
//     all_nodes.insert(0);
 
//     // Call storeNodes function to store all BST Node
//     storeNodes(root, all_nodes, leaf_nodes);
 
//     // Traversal leaf node and check Tree contain
//     // continuous sequence of
//     // size tree or Not
//     for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
//     {
//         int x = (*i);
 
//         // Here we check first and last element of
//         // continuous sequence that are x-1 & x+1
//         if (all_nodes.find(x+1) != all_nodes.end() &&
//             all_nodes.find(x-1) != all_nodes.end())
//             return true;
//     }
 
//     return false ;
// }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends
