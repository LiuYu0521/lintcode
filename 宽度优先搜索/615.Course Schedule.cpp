class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for(auto a : prerequisites)
        {
            graph[a.first].push_back(a.second);
            in[a.second]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto a : graph[temp])
            {
                in[a]--;
                if(in[a] == 0)
                    q.push(a);
            }
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(in[i] != 0)
                return false;
        }
        return true;
    }
};
