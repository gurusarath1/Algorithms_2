/*
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.
*/

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
