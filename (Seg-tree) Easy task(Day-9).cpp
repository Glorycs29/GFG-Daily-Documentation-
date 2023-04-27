class segtree{
    int N;
    vector<vector<int>> tree;
    public:
    vector<int> emp;
    vector<int> prev;
    segtree(int n,string &s)
    {
        emp.resize(26,0);
        prev.resize(n,0);
        N = 1;
        while(N<n)
        {
            N*= 2;
        }
        tree.resize(2*N + 1,vector<int>(26,0));
        for(int i = 0;i<n;i++)
        {
            prev[i] = s[i] - 'a';
            tree[N+i][s[i]-'a']++;
        }
        for(int i = N - 1;i>=1;i--)
        {
            tree[i] = merge(tree[2*i],tree[2*i + 1]);
        }
    }
    
    vector<int> merge(vector<int>&a,vector<int>&b)
    {
        vector<int> curr(26,0);
        for(int i = 0;i<26;i++)
        {
            curr[i] = a[i] + b[i];
        }
        return curr;
    }
    
    void update(int ind,int k)
    {
        int p = prev[ind];
        prev[ind] = k;
        ind += N;
        while(ind>=1)
        {
            tree[ind][p]--;
            tree[ind][k]++;
            ind /= 2;
        }
    }
    
    vector<int> query(int l,int r)
    {
        return query(l,r,0,N-1,1);
    }
    
    vector<int> query(int q_l,int q_r,int node_l,int node_r,int node)
    {
        if(node_l>q_r || q_l>node_r)
        {
            return emp;
        }
        if(q_l<=node_l && node_r<=q_r)
        {
            return tree[node];
        }
        int mid = node_l + (node_r - node_l)/2;
        vector<int> l = query(q_l,q_r,node_l,mid,2*node);
        vector<int> r = query(q_l,q_r,mid+1,node_r,2*node + 1);
        return merge(l,r);
    }
};


class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &v){
        // Code here
        segtree st(n,s);
        vector<char> ans;
        for(int i = 0;i<q;i++)
        {
            if(v[i][0][0]=='1')
            {
                int pos = stoi(v[i][1]);
                //cout<<pos<<endl;
                int k = v[i][2][0] - 'a';
                //cout<<k<<endl;
                st.update(pos,k);
            }else{
                int l = stoi(v[i][1]);
                int r = stoi(v[i][2]);
                vector<int> curr = st.query(l,r);
                int k = stoi(v[i][3]);
                for(int i = 25;i>=0;i--)
                {
                    k -= curr[i];
                    if(k<=0)
                    {
                        ans.push_back(i + 'a');
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
