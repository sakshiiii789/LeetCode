#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
    //only one element in the array 
        if(n==1) return nums[0];
    //first element is the unique one
        if(nums[0]!=nums[1]) return nums[0];
    //last element is the unique
        if(nums[n-1]!=nums[n-2])
        return nums[n-1];
    //initialize binary search bounds
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if((mid%2==1 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1; 
    }
};