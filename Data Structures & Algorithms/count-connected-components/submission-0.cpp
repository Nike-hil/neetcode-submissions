class UnionFind{
private:
    vector<int> ranks;
    vector<int> par;
public:
    UnionFind(int n){
        ranks.resize(n);
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int n){
        if(n!=par[n])
            par[n]=find(par[n]);
        return par[n];
    }

    bool Unite(int n1,int n2){
        int p1=find(n1);
        int p2=find(n2);

        if(p1==p2) return false;
        if(ranks[p1]>ranks[p2]) par[p2]=p1;
        else if(ranks[p1]<ranks[p2]) par[p1]=p2;
        else{
            par[p2]=p1;
            ranks[p1]++;
        }
        return true;
    }
    int compo(){
        set<int> node;
        for(int i=0;i<par.size();i++){
            node.insert(find(i));
        }
        return node.size();
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind comp(n);
        for(auto &e: edges){
            comp.Unite(e[0],e[1]);
        }
        return comp.compo();
    }
};