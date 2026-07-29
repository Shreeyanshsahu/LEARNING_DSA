class Solution {
public:
    bool findRotation(vector<vector<int>>& mat2, vector<vector<int>>& target) {

        int check = true;
        for (int i = 0; i < 4; i++) {
            int x = 0;
            int n = mat2.size();
            for (int i = 0; i < n; i++) {
                for (int j = x; j < n; j++) {
                    if (i == j) {
                        continue;
                    } else {
                        int temp = mat2[i][j];
                        mat2[i][j] = mat2[j][i];
                        mat2[j][i] = temp;
                    }
                }
                x++;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < (n / 2); j++) {
                    int temp = mat2[i][j];
                    mat2[i][j] = mat2[i][n - j - 1];
                    mat2[i][n - j - 1] = temp;
                }
            }
            if(mat2==target){check=true;
            break;}
            else{
                check=false;
            }
        }
        if(mat2==target) check=true;
        return check;
    }
};