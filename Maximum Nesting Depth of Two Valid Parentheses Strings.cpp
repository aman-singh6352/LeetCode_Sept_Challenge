class Solution {
    public:
        vector<int> maxDepthAfterSplit(string seq) {
            vector<int> ans;
            int depth = 0;
            for(auto& ch:seq){
                if(ch == '(') {
                    depth++;
                    ans.push_back(depth%2);
                }
                else {
                    ans.push_back(depth%2);
                    depth--;
                }
            }
            return ans;
        }
    };

/* --------------------------------------------- JAVA CODE --------------------------------------------*/
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] ans = new int[n];
        int depth = 0;
        for(int i = 0;i < n;i++){
            if(seq.charAt(i) == '(') {
                depth++;
                ans[i] = depth%2;
            }
            else {
                ans[i] = depth%2;
                depth--;
            }
        }
        return ans;
    }
}