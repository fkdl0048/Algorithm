class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int prevDay = st.top();
                st.pop();
                answer[prevDay] = i - prevDay;
            }

            st.push(i);
        }

        return answer;
    }
};