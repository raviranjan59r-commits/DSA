class Solution {
public:
     int getSum(vector<int> &arr,int x) {
        return accumulate(arr.begin(), arr.end(), 0,
            [x](int acc, int val) {
                return acc + min(val, x);
            });
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int lo = target / n;
        int hi = arr[n - 1];

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int sum = accumulate(arr.begin(), arr.end(), 0,
                [mid](int acc, int x) {
                    return acc + min(x, mid);
                });

            if (sum < target) {
                lo = mid + 1;
            }
            else if (sum > target) {
                hi = mid - 1;
            }
            else {
                return mid;
            }
        }

        // lo is the first value whose sum >= target
        // hi = lo - 1

        int sumLo = getSum(arr,lo);
        int sumHi = getSum(arr,hi);

        int diffLo = abs(sumLo - target);
        int diffHi = abs(sumHi - target);

        if (diffHi <= diffLo)
            return hi;   // <= handles the tie: choose smaller
        return lo;
    }
};