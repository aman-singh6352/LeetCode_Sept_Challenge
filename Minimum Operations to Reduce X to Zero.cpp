class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int totalsum = accumulate(begin(nums), end(nums), 0);
            int remsum = totalsum-x;
    
            // longest subarray having sum = remsum
            int left = 0, sum = 0, len = -1;
            for(int right = 0;right < nums.size();right++){
                sum += nums[right];
                while(left <= right && sum > remsum){
                    sum -= nums[left++];
                }
                if(sum == remsum) len = max(len, right-left+1);
            }
            if(len == -1) return -1;
            return nums.size()-len;
        }
    };

/* ----------------------------------------- JAVA CODE ---------------------------------------*/
class Solution {
    public int minOperations(int[] nums, int x) {
        int totalsum = 0;
        for (int num : nums) {
            totalsum += num;
        }
        int remsum = totalsum-x;

        // longest subarray having sum = remsum
        int left = 0, sum = 0, len = -1;
        for(int right = 0;right < nums.length;right++){
            sum += nums[right];
            while(left <= right && sum > remsum){
                sum -= nums[left++];
            }
            if(sum == remsum) len = Math.max(len, right-left+1);
        }
        if(len == -1) return -1;
        return nums.length-len;
    }
}