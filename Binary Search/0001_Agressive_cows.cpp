#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<int>& stalls, int cows, int minDist){
    int count =1;
    int lastpos=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=minDist){
            count++;
            lastpos=stalls[i];
        }
        if(count>=cows){
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int>& stalls, int cows){
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPlace(stalls, cows, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }