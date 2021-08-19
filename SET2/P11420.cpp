#include <iostream>
#include <cstring>

using namespace std;

//3-dimensional matrix storing all possibilities for the secured drawers
//otherwise known as the dynamic programming memoization table for this problem
long long int pos[70][70][2]; //n = max + 5, s = max + 5, locked is max 2 (0 or 1)
long long int numPos; //total number of possibilities for secured drawers (output)

//number of possibilities can get to be pretty high, so long long int is necessary
//find the number of possibilities
long long int findNumPos(int numDrawers, int numSecured, int locked)
{
    if(numDrawers == 0 && numSecured == 0) { //if we've iterated all the way through
        return 1;
    } else if (numSecured > numDrawers || numDrawers < 0 || numSecured < 0) { //if one of the values has decremented too far
        return 0;
    } else if(pos[numDrawers][numSecured][locked] != -1) { //if this drawer already processed. DP baby
        return pos[numDrawers][numSecured][locked];
    } else {
        if(!locked) { //if not locked, recursively call findNumPos twice to find if this drawer should/should not be locked
            //decrement number of secured drawers
            return pos[numDrawers][numSecured][locked] = findNumPos(numDrawers - 1, numSecured - 1, 0) + findNumPos(numDrawers - 1, numSecured, 1);
        } else { //if already locked, don't decrement number of secured drawers
            return pos[numDrawers][numSecured][locked] = findNumPos(numDrawers - 1, numSecured, 0) + findNumPos(numDrawers - 1, numSecured, 1);
        }
    }
    //return 0;
}

int main()
{
    //freopen("P11420-input.txt", "r", stdin);
    //numDrawers, numSecured: number of drawers in the wardrobe 'chest', number of drawers that need to be secured (respectively) (input)
    int numDrawers, numSecured;
    cin >> numDrawers >> numSecured;

    while(numDrawers >= 0 && numSecured >= 0) { //while n, s are not negative numbers
        //output 0 if either inputs are 0, or if given s is greater than n - can't have more secured drawers than there are existing drawers
        //cout << "numDrawers: " << numDrawers << ", numSecured: " << numSecured << endl;
        if(numDrawers == 0 || numSecured > numDrawers) { //got a wrong answer from checking for numSecured == 0
            numPos = 0;
            cout << numPos << endl;
        } else if (numDrawers == numSecured) { //if they're equal than there's only one possibility
            numPos = 1;
            cout << numPos << endl;
        } else {
            //call recursive DP method here
            memset(pos, -1, sizeof(pos)); //allocate memory for 3-D matrix 'pos'. set all values to -1 (no drawers visited yet)
            numPos = findNumPos(numDrawers, numSecured, 0); //not locked initially
            cout << numPos << endl;
        }

        cin >> numDrawers >> numSecured; //move on to next line

    }

    return 0;
}
