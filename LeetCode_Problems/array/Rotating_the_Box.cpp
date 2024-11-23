class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        vector<vector<char>> rotated_box(box[0].size(), vector<char>(box.size(), '.'));

        int num_rows = box.size();
        int num_cols = box[0].size();

        for(int i=0; i<num_rows; i++) {
            // Push the rocks to the right (equivalent to falling down)
            for(int j=num_cols-1; j>=0; j--) {

                if(box[i][j] == '.') {
                    // Find the rock to the left this empty space
                    for(int k=j-1; k>=0; k--) {
                        if(box[i][k] == '#') {
                            // Move the rock to the empty space
                            box[i][k] = '.';
                            box[i][j] = '#';
                            rotated_box[k][num_rows - i - 1] = '.';
                            rotated_box[j][num_rows - i - 1] = '#';
                            break;
                        } else if(box[i][k] == '*') {
                            // No rock 
                            rotated_box[k][num_rows - i - 1] = '*';
                            break;
                        }
                    }
                } else if (box[i][j] == '*' || box[i][j] == '#') {
                    rotated_box[j][num_rows - i - 1] = box[i][j];
                }

            }

        }

        return rotated_box;
    }
};
