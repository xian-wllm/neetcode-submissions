class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();

                int width = right - left - 1;

                area = max(area, h * width);
            }

            st.push(i);
        }

        // Traiter les barres restantes
        while (!st.empty()) {

            int h = heights[st.top()];
            st.pop();

            int right = n;
            int left = st.empty() ? -1 : st.top();

            int width = right - left - 1;

            area = max(area, h * width);
        }

        return area;
    }
};