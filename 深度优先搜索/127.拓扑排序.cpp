/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_map<DirectedGraphNode*, int> inDegree;
        for(int i = 0; i < graph.size(); i++)
        {
            inDegree[graph[i]] = 0;
        }
        for(int i = 0; i < graph.size(); i++)
        {
            for(int j = 0; j < graph[i]->neighbors.size(); j++)
            {
                inDegree[graph[i]->neighbors[j]]++;
            }
        }
        queue<DirectedGraphNode*> q;
        vector<DirectedGraphNode*> res;
        for(int i = 0; i < graph.size(); i++)
        {
            if(inDegree[graph[i]] == 0)
                q.push(graph[i]);
        }
        while(!q.empty())
        {
            DirectedGraphNode* temp = q.front();
            res.push_back(temp);
            q.pop();
            for(int i = 0; i < temp->neighbors.size(); i++)
            {
                inDegree[temp->neighbors[i]]--;
                if(inDegree[temp->neighbors[i]] == 0)
                    q.push(temp->neighbors[i]);
            }
        }
        return res;
    }
};
