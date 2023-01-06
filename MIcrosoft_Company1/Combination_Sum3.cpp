class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res; //result array
        vector<int> temp; //empty array -> backtracking addition and deletion occur in this array
        generate_comb3(1, k, n, temp, res); //calling the function to create the combs
        return res;
    }
    void generate_comb3(int start, int k, int sum, vector<int>& temp, vector<vector<int>>& res){ //creating the comb function
        if(temp.size() == k && accumulate(temp.begin(),temp.end(),0) == sum){ //this condition is to be true, only then can the temp array be pushed back into the result array
            res.push_back(temp);
            return;
        }
        for(int i = start; i <= 9; i++){ // performing the operations of adding and recursively calling this function and then removing it frpm temp array
            temp.push_back(i);
            generate_comb3(i+1, k, sum, temp, res);
            temp.pop_back();
        }

    }
};