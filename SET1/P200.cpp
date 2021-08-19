#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#define MAX_INPUT 20 + 5000 //max input string size
#define MAX_STRING 20 //max string size


using namespace std;

int main()
{
    //freopen("rare_order.txt", "r", stdin);
    vector<string> rareWords; //vector of characters
    map<char, bool> seen; //map to determine whether or not a character has been seen before
    int pos = 0; //position
    string line[MAX_INPUT]; //placeholder
    while(cin >> line[pos++]) {
        if(line[pos - 1] == "#") {
            break;
        }
    }
    for(int i=0; i < MAX_STRING; i++) {
        for(int j=0; j < pos - 1; j++) {
            if(i < line[j].size()) {
                if(!seen[line[j][i]]) {
                    cout << line[j][i];
                    seen[line[j][i]] = true;
                }
            }
        }
    }
    /*while(true) {
        getline(cin, line);
        cout << line << endl;
        rareWords.push_back(line);
        if(line == "#") { break; }
    }*/
    cout << endl;
    return 0;
}
