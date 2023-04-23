class Solution{
public:

    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b, a%b);
    }


    int minimumNumber(int n,vector<int> &arr){
        // if we are applying this operation on two numbers
        // then one become zero and other become gcd(a,b)
        // using the same concept
        int GCD = arr[0];
        for(int i=1;i<n;i++){
            GCD = gcd(GCD,arr[i]);
        }
        return GCD;
    }
};
