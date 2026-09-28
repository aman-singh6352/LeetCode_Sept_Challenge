#include<bits/stdc++.h>
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        for(char ch:s){
            if(ch == '(') {
                st.push(ch);
                ans = max(ans, (int)st.size());
            }
            else if(ch == ')') st.pop();
        }
        return ans;
    }
};

/* ------------------------------------- OPTIMISED CODE ---------------------------------*/
class Solution {
public:
    int maxDepth(string s) {
        int openBrac = 0;
        int ans = 0;
        for(char &it:s){
            if(it == '(') {
                openBrac++;
                ans = max(ans, openBrac);
            }
            else if(it == ')') openBrac--;
        }
        return ans;
    }
};

/* ------------------------------------- JAVA CODE --------------------------------------*/
class Solution {
    public int maxDepth(String s) {
        int openBrac = 0;
        int ans = 0;
        for(char it:s.toCharArray()){
            if(it == '(') {
                openBrac++;
                ans = Math.max(ans, openBrac);
            }
            else if(it == ')') openBrac--;
        }
        return ans;
    }
}