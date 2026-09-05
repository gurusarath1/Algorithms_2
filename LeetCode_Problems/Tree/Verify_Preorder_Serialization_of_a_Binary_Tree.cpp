class Solution {
public:
    bool isValidSerialization(string preorder) {

        istringstream stream(preorder);
        string tok;
        int slots = 1; // Number of available slots to place a node.

        while(getline(stream, tok, ',')) {

            if(slots <= 0) return false; // We exhausted all slots

            if(tok == "#") {
                slots -= 1; // 0 children + one slot used = -1
            } else {
                slots += 1; // 2 children + one slot used = 1
            }
        }

        if(slots != 0) {
            return false;
        }

        return true;
        
    }
};
