#include <iostream>
#include <vector>

using namespace std;

//global variables
int results[2]; //0-index: max total learning units, 1-index: node id where the person ends journey
vector<vector <int> > graph; //use 2D vector as data stucture for graph
vector<int> learningVals; //learning values for each node

//recursive greedy function
//given: current node u (to loop through adjacent nodes)
int bestLearningValue(int u)
{
    int nextNode, maxLearningVal = -1; //nextNode: the next node chosen, maxLearningVal: max learning value for journey

    /*cout << "learningVals in bestLearningValue:";
    for(int i = 0; i < learningVals.size(); i++) {
        cout << " " << learningVals[i];
    }
    cout << endl;*/

    for(int i = 0; i < graph[u].size(); i++) { //loop through given node
        int v = graph[u][i]; //set node v
        //cout << "v: " << v << ", learningVals[v]: " << learningVals[v] << endl;
        if(learningVals[v] > maxLearningVal) { //greedily find the maximum learning value of all adjacent nodes
            maxLearningVal = learningVals[v];
            //cout << "maxLearningVal: " << maxLearningVal << endl;
            nextNode = v;
        }
    }

    if(maxLearningVal == -1) { //if no adjacent nodes
        results[1] = u; //final node
        return 0; //end recursive loop
    }

    //recursively call this function to continue looping through adjacent nodes
    //cout << "maxLearningVal: " << maxLearningVal << endl;
    return maxLearningVal + bestLearningValue(nextNode);
}

int main()
{
    //freopen("P12376-input.txt", "r", stdin);
    int T, n, m, val, u, v; //T: num test cases, n: num nodes in graph, m: num edges in graph
    //val: learning value (for each node), (u,v): edge between nodes u & v
    cin >> T; //store the number of test cases
    //cout << "Number of Test Cases: " << T << "\n---------------" << endl;

    for(int i = 0; i < T; i++) { //loop through test cases

        cin >> n >> m; //store the nodes & edges of each graph
        graph = vector<vector<int>>(n); //initalize graph
        learningVals = vector<int>(n); //initialize learning values vector
        
        //cout << "Number of nodes, edges:\t" << n << ", " << m << "\nLearning values for each node:\t";

        for(int j = 0; j < n; j++) { //loop through learning values
            cin >> val;
            learningVals[j] = val; //store in learningVals vector
            //cout << learningVals[j] << " ";
        }
        //cout << endl;

        /*cout << "learningVals in main:";
        for(int j = 0; j < n; j++) {
            cout << " " << learningVals[j];
        }
        cout << endl;*/

        for(int j = 0; j < m; j++) { //loop through connections
            cin >> u >> v;
            graph[u].push_back(v); //store edges in graph
            //cout << "Edge between: " << u << " & " << v << endl;
        }

        results[0] = bestLearningValue(0); //call bestLearningValue to find max unit
        cout << "Case " << i + 1 << ": " << results[0] << " " << results[1] << "\n"; //final output

    }

    return 0;
}
