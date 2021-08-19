#include <iostream>

using namespace std;

long long int heap[22][22][22];
long long int sum[22][22][22];

int main()
{
    int numCases;
    cin >> numCases; //store the number of cases

    while(numCases--) {
        int A, B, C;
        cin >> A >> B >> C; //store the A, B, and C values
        
        //loop through em
        for(int i = 0; i < A; i++) {
            for(int j = 0; j < B; j++) {
                for(int k = 0; k < C; k++) {
                    cin >> heap[i][j][k]; //add values to heap
                    sum[i][j][k] = heap[i][j][k]; //keep track of sum
                    if(j > 0) { //add last j value
                        sum[i][j][k] += sum[i][j-1][k];
                    } else if (k > 0) { //add last k value
                        sum[i][j][k] += sum[i][j][k-1];
                    } else if(j > 0 && k > 0) { //subtract if j and k greater than zero
                        sum[i][j][k] -= sum[i][j-1][k-1];
                    }
                }
            }
        }

        //TODO: continue here

    }

    return 0;
}
