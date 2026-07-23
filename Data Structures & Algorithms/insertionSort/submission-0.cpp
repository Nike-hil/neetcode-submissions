class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> states;
        if (pairs.empty()) return states;
        
        for(int i=0;i<pairs.size();i++){
            int j=i-1;
            while(j>=0 && pairs[j+1].key < pairs[j].key){
                swap(pairs[j+1],pairs[j]);
                j-=1;
            }
            states.push_back(pairs);
        }
        return states;
    }
};