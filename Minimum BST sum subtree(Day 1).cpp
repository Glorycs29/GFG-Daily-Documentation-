class Solution {
public:
    //break the problem into two part first one is subtree -sum and other is check for BST, so first find the sub-tree sum if sum is equal to target then we have to check whether it is BST or not .

    int ans = INT_MAX;
    //pair<int , pair<int , int > > will contain data in this order -> bool  , max , min 
    pair<bool , pair<int , int > >  is_BST(Node *root){
        if(!root)return {true , {INT_MIN , INT_MAX}};
        pair<bool , pair<int , int > > left = is_BST(root->left);
        pair<bool , pair<int , int > > right = is_BST(root->right);
        int maxi , mini;
        bool temp;
        temp  = left.first & right.first;
        if(root->left){
            if(root->data > root->left->data){
                temp &= true;
            }else{
                temp = false;
            }
        }
        
        if(root->right){
            if(root->data < root->right->data){
                temp &= true;
            }else{
                temp = false;
            }
        }
        
        if(right.second.second > root->data){
            temp &= true;
        }else{
            temp = false;
        }
        
        if(left.second.first < root->data){
            temp &= true;
        }else{
            temp = false;
        }
        
        maxi = max(left.second.first , right.second.first);
        mini = min(left.second.second , right.second.second);
        maxi = max( maxi, root->data);
        mini = min(mini , root->data);
    
        return {temp , {maxi , mini}};
    }
    pair<int , int > solve(Node *root ,int  target){
        if(!root)return {0,0};
        pair<int , int > left = solve(root->left , target);
        pair<int , int > right = solve(root->right , target);
        int sum = left.first + right.first + root->data;
        int len = left.second + right.second + 1;
        // cout<<sum<<" -> "<<len<<" && ";
        if(sum == target && is_BST(root).first){
            // pair<bool , pair<int ,int >> 
            ans = min(ans , len);
        }
        return {sum , len};
    }
    int minSubtreeSumBST(int target, Node *root) {
        solve(root , target);
        if(ans == INT_MAX)return -1;
        return ans;
        // code here
    }
};
