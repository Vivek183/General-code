#include <bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& p) {
        
        int n = p.size(); 
        // for(auto x: p )
        // {
        //     x[0] = x[1]-x[0]+1 ; 
        //     if(x[0] < 1)
        //     {
        //         x[0] = -1 ; 
        //         x[1] = -1 ; 
        //     }
        // }
        
 vector<pair<int,int>>ans;
 
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
 
 for(int i=0;i<n;i++){

        p[i][0] = p[i][1] - p[i][0] + 1 ;
        cout << p[i][0] << "-" << p[i][1] << endl ; 
        // Pushing elements in priority queue where the key is f[i]
          if(p[i][0] < 1 ) continue ;   
        q.push(make_pair(p[i][1] , p[i][0]));
    }
    cout << "-------------" << endl ; 
    if(q.empty())return 0 ; 
    auto it = q.top();
    int start = it.second;
    int end = it.first;
    q.pop();
    ans.push_back(make_pair(start,end));
    
    int len = 1 ; 
    
     while(!q.empty()){
        auto itr = q.top();
        q.pop();
      
        if(itr.second > end){
              cout << itr.second << "-" << itr.first << endl ; 
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
            //len++ ; 
        }
    }
    
    return ans.size() ; 
        
    }
};


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt" , "w" ,stdout);
    #endif
Solution s ; 
vector<vector<int>> p {{100,200}, {200,1300},{1000,1250},{2000,3200}};
 int ans = s.scheduleCourse(p);

 cout << ans ; 

    return 0 ; 
}