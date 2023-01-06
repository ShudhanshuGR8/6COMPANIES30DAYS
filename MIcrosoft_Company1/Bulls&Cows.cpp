class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        int n = secret.size();
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            mp[secret[i]]++;
            if(secret[i] == guess[i]) x++;
        }
        // for(auto i : mp){
        //     cout << i.first << " " << i.second << endl;   
        // }
        // cout << "map end" << endl;
        // cout << x << endl;
        
        for(int i = 0; i < guess.size(); i++){
            if(mp.find(guess[i]) != mp.end()){
                y++;
                // cout << y << " " << "gi: " << mp.count(guess[i]) << endl;
                if(mp[guess[i]] > 1) {
                    // cout << mp[guess[i]] << endl;
                    mp[guess[i]]--;
                    
                }
                else {
                    // cout << "else" << mp[guess[i]] << endl;
                    mp.erase(guess[i]);
                    
                }
            }
        }
        // cout << y << " " << x << endl;
        return(to_string(x)+"A"+to_string(y-x)+"B");
    }
};