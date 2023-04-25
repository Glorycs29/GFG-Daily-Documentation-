class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
       
        vector<int> leftmin(n,0),rightmin(n,0);
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();   
            }
            if(!st.empty()) leftmin[i] = st.top();
            else leftmin[i] = -1;
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();   
            }
            if(!st.empty()) rightmin[i] = st.top();
            else rightmin[i] = -1;
            
            st.push(i);
        }
        
        
        int dist1 , dist2;
        for(int i = 0;i<n;i++){
            int lmin = leftmin[i], rmin = rightmin[i]; 
            if(lmin!=-1) dist1 = abs(lmin-i);
            else dist1 = 1e9;
            
            if(rmin!=-1) dist2 = abs(rmin-i);
            else dist2 = 1e9;
            
            if(min(dist1,dist2)!=1e9){
                if(dist1==dist2){
                    if(arr[lmin]<arr[rmin]) ans[i] = lmin;
                    else if(arr[lmin]>arr[rmin]) ans[i] = rmin;
                    else ans[i] = lmin;
                }
                else if(dist1<dist2){
                    ans[i] = lmin;
                }
                else ans[i] = rmin;
            }
        }
       
       return ans;
    }
};
