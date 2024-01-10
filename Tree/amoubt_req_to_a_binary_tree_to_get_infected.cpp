class Solution {
public:
TreeNode* find(TreeNode* node,int key)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->val==key)
    {
        return node;
    }
    else
    {
        TreeNode* node_found=find(node->left,key);
        if(!node_found)
        {
            node_found=find(node->right,key);
        }
        return node_found;
    }
}

void find_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left)
    {
        parent[root->left]=root;
    }
    if(root->right)
    {
        parent[root->right]=root;
    }
    find_parent(root->left,parent);
    find_parent(root->right,parent);
}
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        unordered_map<TreeNode*,TreeNode*> parent;
        find_parent(root,parent);
        TreeNode*target=find(root,start);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=false;

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto front=q.front();
                q.pop();
                visited[front]=true;
                if(front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(parent[front] && !visited[parent[front]])
                {
                    q.push(parent[front]);
                    visited[parent[front]]=true;
                }
            }
            time++;
        }
        return time-1;
    }

};
