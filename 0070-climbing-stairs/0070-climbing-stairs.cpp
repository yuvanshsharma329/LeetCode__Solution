class Solution {
public:
    int Helper(int n, vector<int>&dat){
        if(n==0)
        return 1;

        if(n<0)
        return 0;

        if(dat[n]==0)
        dat[n]=Helper(n-1,dat)+Helper(n-2,dat);
        return dat[n];

    }
    int climbStairs(int n) {
        vector<int>dat(n+1);
        return Helper(n,dat);
        
    }
};