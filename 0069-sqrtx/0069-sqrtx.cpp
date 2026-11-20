class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x;
        long long  ans=1;

        while(low<=high){
            long long mid = low + (high - low) / 2;
            long long value=(mid*mid);
            if(value <=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};