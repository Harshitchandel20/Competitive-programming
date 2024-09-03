class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses);
        queue<int> q;

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[1];
      const int v = prerequisite[0];
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    for (int i = 0; i < numCourses; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      result.push_back(u);
      for (const int v : graph[u])
        if (--inDegrees[v] == 0)
          q.push(v);
    }

    return result.size() == numCourses ? result : vector<int>();
    }
};