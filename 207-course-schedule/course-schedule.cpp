class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {

        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses,0);

        for(auto p : preq)
        {
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
            inDeg[course]++;
        }

        queue<int> q;

        for(int i =0;i<numCourses;i++)
        {
            if(inDeg[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty())
        {
            int course =  q.front();
            q.pop();

            count++;

            for(int next : adj[course])
            {
                inDeg[next]--;
                if(inDeg[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        return count == numCourses;
        
    }
};