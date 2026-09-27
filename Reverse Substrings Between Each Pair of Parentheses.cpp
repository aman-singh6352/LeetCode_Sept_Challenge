class Solution {
    public:
        string reverseParentheses(string s) {
            for(int i = 0;i < s.size();i++){
                int openBrac = 0;
                int j = i;
                if(s[i] == '('){
                    j++;
                    openBrac++;
                    s[i] = ')';
                    while(openBrac > 0){
                        if(s[j] == '(') openBrac++;
                        if(s[j] == ')') openBrac--;
                        if(s[j] == '(') s[j] = ')';
                        else if(s[j] == ')') s[j] = '(';
                        j++;
                    }
                    reverse(s.begin()+i, s.begin()+j);
                }
            }
            string ans;
            for(int i = 0;i < s.size();i++){
                if(s[i] != '(' && s[i] != ')') ans.push_back(s[i]);
            }
            return ans;
        }
    };

/* --------------------------------------------- JAVA CODE ------------------------------------*/
class Solution {
    public String reverseParentheses(String s) {
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == '(') {
                int openBrac = 1;
                int j = i + 1;
                while (openBrac > 0) {
                    if (sb.charAt(j) == '(') {
                        openBrac++;
                    } else if (sb.charAt(j) == ')') {
                        openBrac--;
                    }
                    j++;
                }
                int closeBrac = j - 1;
                StringBuilder temp = new StringBuilder(
                    sb.substring(i + 1, closeBrac)
                );
                for (int k = 0; k < temp.length(); k++) {
                    char c = temp.charAt(k);
                    if (c == '(') {
                        temp.setCharAt(k, ')');
                    } else if (c == ')') {
                        temp.setCharAt(k, '(');
                    }
                }
                temp.reverse();
                sb.replace(i + 1, closeBrac, temp.toString());
                sb.deleteCharAt(closeBrac);
                sb.deleteCharAt(i);
                i--;
            }
        }

        return sb.toString();
    }
}