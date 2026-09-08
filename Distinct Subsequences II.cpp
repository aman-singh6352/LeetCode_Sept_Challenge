class Solution {
    private:
        int mod = 1e9+7;
    public:
        int distinctSubseqII(string s) {
            vector<int> prevAsked(26, 0);
            long long ans = 1;
            for(auto &it:s){
                int temp = prevAsked[it-'a'];
                prevAsked[it-'a'] = ans;
                ans = ((1ll * ans * 2)-temp+mod)%mod;
            }
            return (ans-1+mod)%mod;
        }
    };

/* -------------------------------------------- JAVA CODE ---------------------------------------*/
class Solution {
    private int mod = 1000000007;
    public int distinctSubseqII(String s) {
        long[] prevAsked = new long[26];
        long ans = 1;
        for(char it:s.toCharArray()){
            long temp = prevAsked[it-'a'];
            prevAsked[it-'a'] = ans;
            ans = (ans*2-temp+mod)%mod;
        }
        return (int)(ans-1+mod)%mod;
    }
}