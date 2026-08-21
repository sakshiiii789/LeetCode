#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        while(low<high){
            int mid=low+(high-low)/2;
            int daysneeded=1;
            int currentweight=0;
            for(int i=0;i<weights.size();i++){
                if(currentweight+weights[i]<=mid){
                    currentweight+=weights[i];
                }
                else{
                    daysneeded++;
                    currentweight=weights[i];
                }
            }
            if(daysneeded<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};