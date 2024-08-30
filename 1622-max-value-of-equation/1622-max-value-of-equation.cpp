class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>> heap;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(!heap.empty() && (points[i][0]-heap.top().second)>k)
                heap.pop();
            if(!heap.empty())
                ans = max(ans, (heap.top().first + points[i][0] + points[i][1]));

            heap.push({(points[i][1]-points[i][0]), points[i][0]});
        }

        return ans;
    }
};