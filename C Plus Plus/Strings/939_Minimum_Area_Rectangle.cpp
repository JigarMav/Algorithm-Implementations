// Time - O(N2)
// Space - O(N)

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        // traverse through all points and find the diagonal elements
        // then see if we can form rectangle from the diagonal elements
        // get the minium and return res
        int area = INT_MAX;
        unordered_map<int, unordered_set<int>> mp;
        for (auto p : points)
        {
            mp[p[0]].insert(p[1]);
        }

        for (int i = 0; i < points.size() - 1; i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                // skip same row or column
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                // (x1,y2)  ______x2,y2
                //         |     |
                //         |     |
                //       x1,y1    (x2,y1)
                if (mp[points[i][0]].count(points[j][1]) && mp[points[j][0]].count(points[i][1]))
                {
                    area = min(area, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                }
            }
        }
        return area == INT_MAX ? 0 : area;
        
        
    }
};
