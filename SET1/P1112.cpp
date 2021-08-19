#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define N 100 + 5 //max number of cells in maze

using namespace std;

//helper method for dijkstraMouse (finds current minimum distance value from cells not yet in sptSet)
int minDistance(vector<int> dist, vector<bool> sptSet)
{
    int min = INT_MAX, min_index; //initialize min value
    for(int v=0; v<dist.size(); v++) {
        if(sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

//finds the shortest path from each cell to the exit cell
vector<int> dijkstraMouse(vector < vector<int> > adjMatrix, int numCells, int exit) 
{
    vector<int> dist(numCells); //output vector -- dist[i] holds shorterst dist from exit to i
    vector<bool> sptSet(numCells); //'shortest path tree set' sptSet will be true if shortest distance from exit to i is finalized
    for (int i=0; i<numCells; i++) {
        dist[i] = INT_MAX, sptSet[i] = false; //initialize all distances to infinite and sptSet to false
    }
    dist[exit] = 0; //distance of exit cell to itself is 0
    for(int count = 0; count < numCells-1; count++) {
        int u = minDistance(dist, sptSet); //pick min_dist cell from set of cells not in SPT. u = exit cell in first iteration
        sptSet[u] = true; //mark the cell as processed
        for(int v=0; v<numCells; v++) { //update dist value of adjacent cells
            //update dist[v] iff is not in sptSet, there is a connection, and total time of traversal from exit to v is smaller than curr_val of dist[v]
            if(!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX
                && dist[u]+adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
        }
    }
    return dist;
}

int main()
{
    //freopen("mice_maze.txt", "r", stdin);
    int numCases;
    cin >> numCases; //first line is the number of cases (mice/maze games)
    vector<int> results(numCases);

    //next comes the number of cells in maze, then number of the exit cell, 
    //then the count-down timer starting value, then finally the number of connections
    //a, b, t: cell a to cell b is connected (one-way) and takes t time
    int numCells, numExitCell, countDownVal, numConnections, a, b, t, numMiceExit;

    for(int i=0; i<numCases; i++) { //for i to number of cases

        cin >> numCells;
        cin >> numExitCell;
        cin >> countDownVal;
        cin >> numConnections;

        numExitCell = numExitCell - 1; //convert to 0-index
        vector< vector<int> > adjMatrix(numCells, vector<int>(numCells)); //initialize the NxN adjacency matrix with zeros
        
        for(int j=0; j<numConnections; j++) {
            cin >> a >> b >> t;
            adjMatrix[b-1][a-1] = t; //needs to be reverse dijkstra
        }

        vector<int> dist = dijkstraMouse(adjMatrix, numCells, numExitCell); //run reverse dijkstra on adjacency matrix

        numMiceExit=0;
        for(int i=0; i<numCells; i++) {
            if(dist[i] <= countDownVal) { numMiceExit++; }
        }
        results[i] = numMiceExit;
    }

    for(int i=0; i<numCases; i++) {
        if(i == numCases-1) {
            cout << results[i] << endl;
        } else {
            cout << results[i] << endl << endl;
        }
    }
    return 0;
}
