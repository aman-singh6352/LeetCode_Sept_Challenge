class Solution {
    public:
        // int disSub(int i, int j, string t, string s){
        //     if(i < 0) return 1;
        //     if(j < 0) return 0;
        //     if(t[i] == s[j]) return disSub(i, j-1, t, s) + disSub(i-1, j-1, t, s); // either we will match it to the current one or don't match it
        //     return disSub(i, j-1, t, s);
        // }
        int numDistinct(string s, string t) {
            vector<double> prev(s.size()+1, 1), curr(s.size()+1, 0);
    
            for(int i = 1;i <= t.size();i++){
                for(int j = 1;j <= s.size();j++){
                    if(t[i-1] == s[j-1]) curr[j] = curr[j-1] + prev[j-1];
                    else curr[j] = curr[j-1];
                }
                prev = curr;
            }
            return prev[s.size()];
        }
    };

/* ------------------------------------------------ JAVA CODE ----------------------------------------------*/
class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length();
        int m = t.length();
        
        int[] dp = new int[m + 1];
        

        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
 
            for (int j = m; j >= 1; j--) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
 
                    dp[j] = dp[j] + dp[j - 1];
                }

            }
        }
        
        return dp[m];
    }
}