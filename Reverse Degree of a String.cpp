class Solution {
    public:
        int reverseDegree(string s) {
            // 'z'-'a' -> 25
            int ans = 0;
            for(int i = 0;i<s.size();i++){
                ans += ('z'-s[i]+1)*(i+1);
            }
            return ans;
        }
    };

/* ------------------------------------- JAVA CODE -------------------------------*/
class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            ans += ('z'-s.charAt(i)+1)*(i+1);
        }
        return ans;
    }
}