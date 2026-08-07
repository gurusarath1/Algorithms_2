class Solution {
public:
    string simplifyPath(string path) {

        string ret;
        deque<string> dq;

        for(int i=0; i<path.size(); i++) {
            char c = path[i];
            string data = "";

            if(c == '/') { // Split point

                if(i+1>=path.size()) {
                    break;
                } else {
                    if(path[i+1] == '/') {
                        data = "//";
                        i++;
                    } else {
                        data = "/";
                    }
                }

            } else { // directory

                // get the string till the next /
                while(i < path.size() && path[i] != '/') {
                    data += path[i];
                    i++;
                }
                i--;

            }

            // Check the type of data
            if(data == "..") {
                if(dq.size() > 2) {
                    dq.pop_back();
                    dq.pop_back();
                }
            } else if(data == "/" || data == "//") {
                if(!dq.empty() && dq.back() != "/"){
                    dq.push_back("/");
                } else if (dq.empty()) {
                    dq.push_back("/");
                }
            } else if(data == "."){
                ;
            } else {
                dq.push_back(data);
            }

        }

        // Build string
        while(!dq.empty()) {
            string dir = dq.front();
            dq.pop_front();
            if(!(dq.empty() && dir=="/")) { // don't add last /
                ret += dir;
            }
        }

        if(ret == "") return "/";

        return ret;
    }
};
