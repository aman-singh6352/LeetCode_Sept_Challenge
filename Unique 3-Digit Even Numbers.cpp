
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        int ans = 0;

        for (auto &it : digits) {
            count[it]++;
        }

        for (int i = 0; i <= 8; i += 2) {
            if (count[i] == 0) continue;
            count[i]--;
            int uniq = 0;
            for (int j = 0; j < 10; j++) {
                if (count[j]) uniq++;
            }
            ans += uniq * (uniq - 1);

            for (int j = 1; j < 10; j++) {
                if (count[j] >= 2) {
                    ans++;
                }
            }

            if (count[0]) {
                ans -= uniq - 1;
            }

            count[i]++;
        }

        return ans;
    }
};

/* ------------------------------------------- JAVA CODE --------------------------------*/
class Solution {
    public int totalNumbers(int[] digits) {
        int[] count = new int[10];
        int ans = 0;

        for (int it : digits) {
            count[it]++;
        }

        for (int i = 0; i <= 8; i += 2) {
            if (count[i] == 0) continue;
            count[i]--;
            int uniq = 0;
            for (int j = 0; j < 10; j++) {
                if (count[j] != 0) uniq++;
            }
            ans += uniq * (uniq - 1);

            for (int j = 1; j < 10; j++) {
                if (count[j] >= 2) {
                    ans++;
                }
            }

            if (count[0] != 0) {
                ans -= uniq - 1;
            }

            count[i]++;
        }

        return ans;
    }
}