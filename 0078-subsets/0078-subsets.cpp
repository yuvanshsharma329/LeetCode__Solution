class Solution {
public:
vector<vector<int>>ans;
void Helper(vector<int>nums,int i,vector<int>temp){
int n=nums.size();
if(i==n) ans.push_back(temp);
else{
    Helper(nums,i+1,temp);
    temp.push_back(nums[i]);
    Helper(nums,i+1,temp);
    }
} 
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<int>temp;
        Helper(nums,0,temp);
        return ans;
    }
};