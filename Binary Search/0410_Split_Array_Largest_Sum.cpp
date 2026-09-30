#include<bits/stdc++.h>
using namespace std;        
class Solution {
public:
bool canSplit(vector<int>& nums, int k, long long maxSum){
    int students=1;
    long long currentSum=0;
    for(int i=0;i<nums.size();i++){
        if(currentSum+nums[i]<=maxSum){
          currentSum+=nums[i];
        }
        else{
            students++;
            currentSum=nums[i];
        }
    }
    if(students<=k){
        return true;
    }
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        long long low=0;
        long long high=0;
        for(int i=0;i<nums.size();i++){
            low=max(low,(long long)nums[i]);
            high=high+nums[i];
        }
        long long ans=high;
         while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
        
    }
};