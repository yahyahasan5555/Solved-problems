#include <bits/stdc++.h>
using namespace std;

struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int id, int imp, vector<int> sub): id(id), importance(imp), subordinates(sub) {
    }
};

// key = id, vec = subordinates
typedef map<int, vector<int>> GRAPH;

class Solution {
public:
       /*static*/int dfs(int id, GRAPH neighbours, map<int,int> values) {
              int total {values[id]};
              for(int subordinate: neighbours[id])
                     total += dfs(subordinate, neighbours, values);
              
              return total;
       }      

       /*static*/int getImportance(vector<Employee*> employees, int id) {
              GRAPH adj;
              map<int, int> vals; // key = id, val = value

              for(Employee*& em: employees) {
                     vals[em->id] = em->importance;
                     adj[em->id] = em->subordinates;
              }

              return dfs(id, adj, vals);
       }
};

int main() {
       Employee* em1 = new Employee(1, 5, {2, 3});
       Employee* em2 = new Employee(2, 3, {});
       Employee* em3 = new Employee(3, 3, {});
       cout << Solution::getImportance({em1, em2, em3}, 1) << endl;
       return 0;
}
