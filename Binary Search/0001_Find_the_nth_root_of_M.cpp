#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int nthRoot(int n,int m){
        int low=1;int high=m; int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid*mid<=m){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }


        }
        return ans; 
    }
};
int main() {
    Solution obj;
    int result = obj.nthRoot(5, 69);
    cout << result << endl;
    return 0;
}