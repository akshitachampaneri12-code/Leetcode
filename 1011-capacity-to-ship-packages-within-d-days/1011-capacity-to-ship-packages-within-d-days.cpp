class Solution {
public:
    //find days
    int findDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++) {

            if(load + weights[i] > cap) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return days;
    }
   //finds the minimum ship capacity required to ship all packages within the given number of day
    int shipWithinDays(vector<int>& weights, int days) {
       //Find the minimum capacity
        int low = *max_element(weights.begin(), weights.end());
        //max capacity
        int high = 0;
        for(int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }
        //apply bs 
        while(low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = findDays(weights, mid);

            if(requiredDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};