class Solution {
    public:
        string evaluate(string s, vector<vector<string>>& knowledge) {
            unordered_map<string, string> mp;
            for(auto& it:knowledge){
                mp[it[0]] = it[1];
            }
            int i = 0, n = s.size();
            string ans;
            while(i < n){
                if(s[i] == '('){
                    string temp = "";
                    while(++i < n && s[i] != ')'){
                        temp.push_back(s[i]);
                    }
                    if(mp.count(temp)) ans += mp[temp];
                    else ans.push_back('?');
                }
                else {
                    ans.push_back(s[i]);
                }
                i++;
            }
            return ans;
        }
    };

/* ---------------------------------------- JAVA CODE ---------------------------------------*/
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        HashMap<String, String> mp = new HashMap<>();
        for(List<String> it:knowledge){
            mp.put(it.get(0),it.get(1));
        }
        int i = 0, n = s.length();
        StringBuilder ans = new StringBuilder();
        while(i < n){
            if(s.charAt(i) == '('){
                StringBuilder temp = new StringBuilder();
                while(++i < n && s.charAt(i) != ')'){
                    temp.append(s.charAt(i));
                }
                String key = temp.toString();
                if(mp.containsKey(key)) ans.append(mp.get(key));
                else ans.append('?');
            }
            else {
                ans.append(s.charAt(i));
            }
            i++;
        }
        return ans.toString();
    }
}