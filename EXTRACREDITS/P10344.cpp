#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fiveTupel[5]; //initialize tupel array

//boolean function 'possibleFunc'
bool possibleFunc(int checkNum, int index)
{
    if(index == 5) { //if index is 5
        return checkNum == 23;
    }
    //run through each operator
    return possibleFunc(checkNum + fiveTupel[index], index + 1) || possibleFunc(checkNum - fiveTupel[index], index + 1) || possibleFunc(checkNum * fiveTupel[index], index + 1);
}

int main() {
    
    //freopen("P10344-input.txt", "r", stdin);
    //vector<int> initial; //array of initial calculations between index 0 and index 1 (+, -, *)

    //get the initial five tupel
    cin >> fiveTupel[0] >> fiveTupel[1] >> fiveTupel[2] >> fiveTupel[3] >> fiveTupel[4];
    
    //while not termination input
    while(fiveTupel[0] != 0 && fiveTupel[1] != 0 && fiveTupel[2] != 0 && fiveTupel[3] != 0 && fiveTupel[4] != 0)
    {
        //print given input
        //cout << "Input: " << fiveTupel[0] << ", " << fiveTupel[1] << ", " << fiveTupel[2] << ", " << fiveTupel[3] << ", " << fiveTupel[4] << endl;
        bool possible = false;
        /*initial.push_back(fiveTupel[0] + fiveTupel[1]);
        initial.push_back(fiveTupel[0] - fiveTupel[1]);
        initial.push_back(fiveTupel[0] * fiveTupel[1]);
        findIfPossible(fiveTupel, initial);
        if(possible) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }*/

        //sort the given numbers in ascending order
        sort(fiveTupel, fiveTupel + 5);
        do { //while new permutations for the given input
            if(possible = (possible || possibleFunc(fiveTupel[0], 1))) {
                break;
            }
        } while(next_permutation(fiveTupel, fiveTupel + 5)); //next_permutation creates all possible organizations for the given fiveTuple

        cout << (possible ? "Possible" : "Impossible") << endl; //if possible is true then output possible, if not output impossible

        //continue to loop through input
        cin >> fiveTupel[0] >> fiveTupel[1] >> fiveTupel[2] >> fiveTupel[3] >> fiveTupel[4];
    }

    return 0;
}
