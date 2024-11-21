#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    bool id = false;
    
    for (int i = 0; i < db.size(); i++) {
        if (id_pw[0] == db[i][0]) {
            id = true;
            
            for (int j = 0; j < db[i].size(); j++) {
                if (id_pw[1] == db[i][1]) {
                    return "login";
                }
            }
        }
    }
    
    return id == true ? "wrong pw" : "fail";
}