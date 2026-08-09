class DSU{
    vector<int> parent;
    vector<int> rank_;

    
public:
    int components;
    DSU(int n): parent(n), rank_(n, 0), components(n){
        for (int i = 0 ; i < n ; i++)
            parent[i] = i ;
    }
    
    // this is used to find the parent of a particular DSU ID
    int find(int x){ 
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return parent[x];
    }

    bool unite(int a , int b){

        int ra  = find(a); // gets parent of ra 
        int rb = find(b); // get parent of rb 

        //we check if the parent are already the same 
        if (parent[ra] == parent[rb]){
            return false;
        }
        if (rank_[ra] < rank_[rb]) swap(rb , ra);
        parent[rb]= ra;
        if (rank_[ra] == rank_[rb]) rank_[ra]++;

        components--;

        return true;
    }


};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        for (int i = 0 ; i < edges.size(); i++){
            vector<int> current = edges[i];
            int node = current[0];
            int nei = current[1];

            if(!dsu.unite(node, nei)){
                return false;
            }

        }


        if (dsu.components == 1){
            return true;
        }
        else{
            return false;
        }


    }
};
