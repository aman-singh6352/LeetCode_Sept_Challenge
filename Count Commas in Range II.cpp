class Solution {
    public:
        long long countCommas(long long n) {
            long long ans = 0;
            if(n < 1000) return ans;
            if(n >= 1000) ans += (n-1e3+1);
            if(n >= 1e6) ans += (n-1e6+1);
            if(n >= 1e9) ans += (n-1e9+1);
            if(n >= 1e12) ans += (n-1e12+1);
            if(n >= 1e15) ans += 1;
            return ans;
        }
    };

/* ---------------------------------- JAVA CODE ---------------------------------*/
class Solution {
    public long countCommas(long n) {
        long ans = 0;
        if(n < 1000) return ans;
        if(n >= 1000) ans += (n-1e3+1);
        if(n >= 1e6) ans += (n-1e6+1);
        if(n >= 1e9) ans += (n-1e9+1);
        if(n >= 1e12) ans += (n-1e12+1);
        if(n >= 1e15) ans += 1;
        return ans;
    }
}