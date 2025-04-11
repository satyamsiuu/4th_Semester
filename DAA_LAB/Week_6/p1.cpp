#include<bits/stdc++.h>
using namespace std;

bool find_path(vector<vector<int>> &AdjM,int u,int v,int V)
{
     vector<int> visit(V,0);
     stack<int> st;
     st.push(u);
     while(!st.empty())
     {
          int node = st.top();
          st.pop();
          
          if(visit[node] == 1)
               continue;
          else
               visit[node] = 1;
          
          if(node==v)
               return true;
          
          visit[node] = 1;
          for(int i=0;i<V;i++)
          {
               if(AdjM[node][i]==1 && visit[i]==0)
                    st.push(i);
          }
     }
     return false;
}

int main()
{
     int V;
     cout<<"Enter Vertices: ";
     cin>>V;
     vector<vector<int>> AdjM(V,vector<int>(V));
     cout<<"Enter adjcency maxtrix:-"<<endl;
     for(int i=0;i<V;i++)
     {
          for(int j=0;j<V;j++)
               cin>>AdjM[i][j];
     }
     
     int u,v;
     cout<<"Enter source and destination nodes: ";
     cin>>u>>v;
     
     if (u < 0 || u >= V || v < 0 || v >= V) 
     {
        cout << "Invalid node values entered!" << endl;
        return 0;
     }
     
     if(find_path(AdjM,u,v,V))
          cout<<"Yes Path Exists"<<endl;
     else
          cout<<"No Such Path Exists"<<endl;
     return 0;
}