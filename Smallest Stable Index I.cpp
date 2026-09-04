class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mine(n), maxe(n);
        int maxele = INT_MIN, minele = INT_MAX;
        for(int i = 0;i < n;i++){
            maxele = max(maxele, nums[i]);
            minele = min(minele, nums[n-i-1]);
            maxe[i] = maxele;
            mine[n-i-1] = minele;
        }
        for(int i = 0;i < n;i++){
            if(maxe[i]-mine[i] <= k) return i;
        }
        return -1;
    }
};

/* ------------------------------------------ JAVA CODE ---------------------------------------*/
class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] mine = new int[n];
        int[] maxe = new int[n];
        int maxele = Integer.MIN_VALUE, minele = Integer.MAX_VALUE;
        for(int i = 0;i < n;i++){
            maxele = Math.max(maxele, nums[i]);
            minele = Math.min(minele, nums[n-i-1]);
            maxe[i] = maxele;
            mine[n-i-1] = minele;
        }
        for(int i = 0;i < n;i++){
            if(maxe[i]-mine[i] <= k) return i;
        }
        return -1;
    }
}