#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    //freopen("P481-input.txt", "r", stdin);
    vector<int> sequence; //initialize sequence vector
    int num;
    while(cin >> num) {
        sequence.push_back(num); //store the input into the sequence vector
    }

    //verify the input is stored correctly
    /*cout << "Input sequence:\n----------------------" << endl;
    for(int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << endl;
    }*/
    
    vector<int> subseqVec, subseqID, result; //change these variable names
    //assign the above vectors with 0's and -1's of same size as sequence (input)
    subseqVec.assign(sequence.size(), 0);
    subseqID.assign(sequence.size(), 0);
    result.assign(sequence.size(), -1); //set to -1 for use in the if statement below and outputting (greater-equal than zero)

    int subseqLength = 0, subseqEndIndex = 0; //initialize var's for subsequence length and ending index
    for(int i = 0; i < sequence.size(); i++) {
        //find the lower bound of all numbers in subseqVec up to subseqVec + current subsequence length that are equal to or greater than the current number in sequence
        //then convert to int from iterator with the '- subseqVec.begin()'
        int index = lower_bound(subseqVec.begin(), subseqVec.begin() + subseqLength, sequence[i]) - subseqVec.begin();
        subseqVec[index] = sequence[i];
        subseqID[index] = i;
        if(index) { //if pos not -1 i.e. part of subsequence
            result[i] = subseqID[index-1];
        } else {
            result[i] = -1;
        }
        if(index == subseqLength) {
            subseqLength++; //add to total subsequence total
            subseqEndIndex = i;
        }
    }

    //cout << subseqEndIndex << endl;
    cout << subseqLength << endl << '-' << endl;

    stack<int> finalSubseq; //use a stack to store final subsequence
    int i = subseqEndIndex; // placeholder
    for(; result[i] >= 0; i = result[i]) {
        finalSubseq.push(sequence[i]);
    }
    cout << sequence[i] << endl;
    for(; !finalSubseq.empty(); finalSubseq.pop()) {
        cout << finalSubseq.top() << endl;
    }

    return 0;
}
