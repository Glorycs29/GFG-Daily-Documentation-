class Solution{
    public:
    bool wifiRange(int N, string S, int x){
        int vis[N+1]={0};
        int left=0, right=0;
        
        for(int i=0;i<N;i++){
            int leftTime=x, rightTime=x;
            
            if(S[i]=='1'){
                vis[i]=1;
                left=i-1;
                right=i+1;
                
                while(leftTime>0 && left>=0){
                    
                    vis[left]=1;
                    leftTime--;
                    left--;
                    
                }
                while(rightTime>0 && right<N){
                    
                    vis[right]=1;
                    rightTime--;
                    right++;
                    
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
        
    }
};
