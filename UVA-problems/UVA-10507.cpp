#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void testCase(void) {
       int n, m; 
       while(cin >> n >> m) { // cin.eof();
              // our adjacency list
              unordered_map<char, vector<char>> adj;
              // for counts the number of active/wake connected nodes
              unordered_map<char, int> counter; 
              // save awake, and sleep nodes so far.
              unordered_set<char> awake, sleep;

              // read 3 awake nodes
              for(int i {}; i < 3; ++i) {
                     char x; cin >> x;
                     awake.insert(x);
              }

              char u, v;
              while(m-- && cin >> u >> v)
                     adj[u].push_back(v), 
                     adj[v].push_back(u);

              /* Next step:
               * Loop for all nodes in adjacency list:
               * for each slept node:
               * insert it to the sleep array
               * check from its neighbours: if any of them is an awake node, increment it's counter
               */
              for(auto& [area, neighbors]: adj) {
                     // if not awake node:
                     if(!awake.count(area)) {
                            sleep.insert(area);

                            for(char neighbor: neighbors)
                                   if(awake.count(neighbor))
                                          // Increment it's counter with awake nodes. 
                                          counter[area]++; 
                     }
              }

              int years {};
              while(!sleep.empty()) {
                     // for check waether if there a nodes that connected with 3 awake nodes, 
                     // and collect them, and remove them from sleep array, and add them to main awake array
                     unordered_set<char> newly_awake;
                     for(char sleep_area: sleep) 
                            if(counter[sleep_area] >= 3) 
                                   newly_awake.insert(sleep_area);
                     
                     if(newly_awake.empty())
                            break; // there are no node to be awake

                     for(auto new_awake_area: newly_awake) {
                            awake.insert(new_awake_area);
                            sleep.erase(new_awake_area);

                            // loop for it's sleep neighbors to increment thier counter
                            // because it was an awake area
                            for(char neighbor: adj[new_awake_area])
                                   if(sleep.count(neighbor))
                                          counter[neighbor]++; // own a new awakes area. 
                     }

                     ++years;
              }

              // are all nodes was be awake nodes?
              if((int)awake.size() == n)
                     cout << "WAKE UP IN, " << years << ", YEARS\n";
              else 
                     cout << "THIS BRAIN NEVER WAKES UP\n";
       }
}

int main () {        
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}
