class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for(auto a : prerequisites)
        {
            graph[a.second].push_back(a.first);
            in[a.first]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(auto a : graph[temp])
            {
                in[a]--;
                if(in[a] == 0)
                    q.push(a);
            }
        }
        if(res.size() != numCourses)
            res.clear();
        return res;
    }
};
