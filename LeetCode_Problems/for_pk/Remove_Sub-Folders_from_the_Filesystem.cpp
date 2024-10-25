class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        set<string> folders_set;
        vector<int> delete_list; // list of indices to delete in folder vector
        vector<string> result;

        sort(folder.begin(), folder.end(), [](string &a, string&b){
            return a.size() < b.size();
        }); // folders lower in the hierarchy should come first

        for(int i=0; i<folder.size();  i++) {

            string &path = folder[i];

            string sub_path="";
            int idx = 0;
            bool included_for_delete = false;
            while(idx != -1) {
                idx = get_next_folder(path, idx, sub_path); // build the path from start

                // Check if this is a sub folder of some previous fullpath
                if(!included_for_delete && folders_set.find(sub_path) != folders_set.end()) {
                    delete_list.push_back(i);
                    included_for_delete = true;
                }
            }

            folders_set.insert(sub_path); // push the full path to set
        }

        for(int i=0, j=0; i<folder.size(); i++) {
            if(j < delete_list.size() && delete_list[j] == i) {
                j++;
                continue;
            }

            result.push_back(folder[i]);
        }

        return result;
    }

    int get_next_folder(string &path, int i, string &sub_path) {

        if(path[i] == '/') i++;
        else assert(0);

        sub_path += '/';

        // Get next folder
        while(path[i] != '/' && i < path.size()) {
            sub_path += path[i];
            i++;
        }

        // end of string return
        if(i == path.size()) return -1;

        return i;
    }
};
