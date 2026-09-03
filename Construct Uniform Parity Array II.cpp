class Solution {
    public:
        bool uniformArray(vector<int>& nums1) {
            int minodd = INT_MAX, mineven = INT_MAX;
            for(auto &it:nums1){
                if(it%2) minodd = min(minodd, it);
                else mineven = min(mineven, it);
            }
            if(minodd == INT_MAX || mineven == INT_MAX) return true;
            return mineven > minodd;
        }
    };

/* -------------------------------------------- JAVA CODE ---------------------------------------------*/
class Solution {
    public boolean uniformArray(int[] nums1) {
        int minodd = Integer.MAX_VALUE, mineven = Integer.MAX_VALUE;
        for(int it:nums1){
            if(it%2 == 1) minodd = Math.min(minodd, it);
            else mineven = Math.min(mineven, it);
        }
        if(minodd == Integer.MAX_VALUE || mineven == Integer.MAX_VALUE) return true;
        return mineven > minodd;
    }
}