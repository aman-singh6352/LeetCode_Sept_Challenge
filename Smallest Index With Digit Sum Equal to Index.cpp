class Solution {
    public:
        int smallestIndex(vector<int>& nums) {
            auto sum = [](int num){
                int totalsum = 0;
                while(num != 0){
                    totalsum += num%10;
                    num /= 10;
                }
                return totalsum;
            };
            for(int i = 0;i < nums.size();i++){
                if(sum(nums[i]) == i) return i;
            }
            return -1;
        }
    };

/* -------------------------------------- JAVA CODE ---------------------------------*/
class Solution {
    private int sum(int num){
        int totalsum = 0;
        while(num != 0){
            totalsum += num%10;
            num /= 10;
        }
        return totalsum;
    }
    public int smallestIndex(int[] nums) {
        for(int i = 0;i < nums.length;i++){
            if(sum(nums[i]) == i) return i;
        }
        return -1;
    }
}