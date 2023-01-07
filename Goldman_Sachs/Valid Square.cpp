class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            if(p1==p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3==p4) return false;
            
            //1st approach
            // int x1 = p1[0];
            // int y1 = p1[1];
            // int x2 = p2[0];
            // int y2 = p2[1];
            // int x3 = p3[0];
            // int y3 = p3[1];
            // int x4 = p4[0];
            // int y4 = p4[1];
            // float s1 = pow(x2 - x1, 2) + pow(y2 - y1, 2); //sq. dist(p1, p2)
            // cout << s1 << endl;
            // float s2 = pow((y3-y1), 2) + pow((x3-x1),2); //sq. dist(p1, p3)
            // cout << s2 << endl;
            // float s3 = pow((y4-y1), 2) + pow((x4-x1),2);//sq. dost(p1, p4)
            // cout << s3 << endl;
            // if(s1 == s2 && s3 == 2*s1){ // sides (p1,p2) and (p1, p3) are equal and (p1, p4) makes the diagonal, so should be equal to 2*sq. dist(p1,p2)
            //     float s_1 = pow((y2-y4), 2) + pow((x2-x4),2); //now we check for dist bw other points i.e. (p2, p4)
            //     float s__1 = pow((y3-y4), 2) + pow((x3-x4),2); //now we will check for dist bw (p3, p4)
            //     if(s_1==s__1 && s_1 == s1) return true;
            // }
            // else if(s1 == s3 && s2 == 2*s1){ //this if has two conds: 1) sides equal 2) diagonal sq.=2*side
            //     float s_2 = pow((y2-y3), 2) + pow((x2-x3),2);
            //     float s__2 = pow((y3-y4), 2) + pow((x3-x4),2);
            //     if(s_2 == s__2 && s_2 == s1) return true;
            // }
            // else if(s2 == s3 && s1 == 2*s2){
            //     float s_3 = pow((y4-y2), 2) + pow((x4-x2),2);
            //     float s__3 = pow((y2-y3), 2) + pow((x2-x3),2);
            //     if(s_3 == s__3 && s_3 == s2) return true;
            // }
            
            // return false;

            //2nd Approach -> What wer do here is that:- Firstly we have 4 pts. so in total we will have 6 different distances betweeen them. SO we first calculate those dists.
            int a = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
            int b = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
            int c = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
            int d = pow(p3[0] - p2[0], 2) + pow(p3[1] - p2[1], 2);
            int e = pow(p4[0] - p2[0], 2) + pow(p4[1] - p2[1], 2);
            int f = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
            //Second Step is to check that 4 distances should be equal among these 6 dists in ordeer to form a sq. But the figure could also be a rhombus. Hence we will also check the pother 2 dists. as they will be the diagonal of the figure. Now for sq. those diagonals also have to equal. Hence in total there will only be two unique and different dists. 
            //Hence we will push these elements into a map. And is the size of the map increase more than 2, we will understand that the points do not form a square.
            unordered_map<int, int> mp;
            mp[a]++;
            mp[b]++;
            mp[c]++;
            mp[d]++;
            mp[e]++;
            mp[f]++;
            if(mp.size() > 2) return false;
            return true;

    }
};