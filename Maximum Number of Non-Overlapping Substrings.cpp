class Solution {
    public:
        vector<string> maxNumOfSubstrings(string s) {
            vector<int> start(26, -1), end(26,-1);
            for(int i = 0;i < s.size();i++){
                if(start[s[i]-'a'] == -1){
                    start[s[i]-'a'] = i;
                }
                end[s[i]-'a'] = i;
            }
            vector<bool> valid(26, true);
            for(int c = 0;c < 26;c++){
                if(start[c] == -1) continue;
                for(int i = start[c];i <= end[c];i++){
                    if(start[s[i]-'a'] < start[c]) {
                        valid[c] = false;
                        break;
                    }
                    end[c] = max(end[c], end[s[i]-'a']);
                }
            }
            int prevCharStart = s.size();
            vector<string> ans;
            for(int right = s.size()-1;right >= 0;right--){
                if(valid[s[right]-'a'] && 
                    right == start[s[right]-'a'] && 
                    prevCharStart > end[s[right]-'a'])
                {
                    prevCharStart = right;
                    ans.push_back(s.substr(right, end[s[right]-'a']-start[s[right]-'a']+1));
                }
            }
            return ans;
        }
    };

/* ------------------------------------ JAVA CODE -----------------------------*/
class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int[] start = new int[26];
        int[] end = new int[26];
        Arrays.fill(start, -1);
        Arrays.fill(end, -1);
        for (int i = 0; i < s.length(); i++) {
            if (start[s.charAt(i) - 'a'] == -1) {
                start[s.charAt(i) - 'a'] = i;
            }
            end[s.charAt(i) - 'a'] = i;
        }
        boolean[] valid = new boolean[26];
        Arrays.fill(valid, true);
        for (int c = 0; c < 26; c++) {
            if (start[c] == -1)
                continue;
            for (int i = start[c]; i <= end[c]; i++) {
                if (start[s.charAt(i) - 'a'] < start[c]) {
                    valid[c] = false;
                    break;
                }
                end[c] = Math.max(end[c], end[s.charAt(i) - 'a']);
            }
        }
        int prevCharStart = s.length();
        List<String> ans = new ArrayList<>();

        for (int right = s.length() - 1; right >= 0; right--) {
            if (valid[s.charAt(right) - 'a']
                    && right == start[s.charAt(right) - 'a']
                    && prevCharStart > end[s.charAt(right) - 'a']) {

                prevCharStart = right;

                ans.add(s.substring(
                        right,
                        end[s.charAt(right) - 'a'] + 1));
            }
        }
        return ans;
    }
}