#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate total hours at given speed
    int calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas/speed);
        }
        return totalH;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Find maximum element
        int maxPile = *max_element(piles.begin(), piles.end());

        // Initialize low and high pointers
        int low =1;int high = maxPile;
        int ans = maxPile;

        // Binary search on answer space
        while (low < high) {
            int mid = low+(high-low) / 2;
            int totalH = calculateTotalHours(piles, mid);
      
            // If possible, try smaller speed
            if (totalH <= h) {
                ans=mid;
                high = mid;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

