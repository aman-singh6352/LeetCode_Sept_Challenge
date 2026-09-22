class Solution {
    public:
        vector<long long> resultArray(vector<int>& nums, int k) {
            vector<long long> ans(k, 0), prev(k, 0);
            for(int i = 0;i < nums.size();i++){
                vector<long long> curr(k, 0);
                curr[nums[i]%k]++;
                for(int oldrem = 0;oldrem < k;oldrem++){
                    int newrem = (oldrem * (nums[i]%k))%k;
                    curr[newrem] += prev[oldrem];
                }
                prev = curr;
                for(int x = 0;x < k;x++){
                    ans[x] += prev[x];
                }
            }
            return ans;
        }
    };

/* --------------------------------------- JAVA CODE -----------------------------------*/
class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] ans = new long[k];
        long[] prev = new long[k];
        for(int i = 0;i < nums.length;i++){
            long[] curr = new long[k];
            curr[nums[i]%k]++;
            for(int oldrem = 0;oldrem < k;oldrem++){
                int newrem = (oldrem * (nums[i]%k))%k;
                curr[newrem] += prev[oldrem];
            }
            prev = curr;
            for(int x = 0;x < k;x++){
                ans[x] += prev[x];
            }
        }
        return ans;
    }
}