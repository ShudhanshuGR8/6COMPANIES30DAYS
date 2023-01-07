class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         int mx = 0;
        if(points.size() <= 2) return points.size();
            // int x1 = points[0][0];
            // int y1 = points[0][1];
            // int x2 = points[1][0];
            // int y2 = points[1][1];
            // //trying to solve for the equation for m
            // float m = (y2 - y1)/(x2 - x1);


            // // int count = 0;
            // // for(int i = 0; i < points.size(); i++){
            // //     if(points[i][1] == m*points[i][0] + c) count++;
            // // }
            // // return count;      
           
            for(int i = 0; i < points.size(); i++){
                unordered_map<float, int> mp;
                float x = points[i][0];
                float y = points[i][1];
                for(int j = i+1; j < points.size(); j++){
                    // int count = 0;
                    float x1 = points[j][0];
                    float y1 = points[j][1];
                    float m;
                    if(x1-x==0){
                        m = INT_MAX;
                    }
                    else{
                    m = (y1 - y) / (x1 - x);
                    cout << x << " "<< y << " " << x1 << " " << y1 << ": ";
                    cout << "Slope M: " << m << endl;
                    }
                     mp[m]++;
                     mx = max(mx, mp[m]);
                }
            }
        return mx + 1; //should also include the point i
    }
};