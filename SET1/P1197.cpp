//-----------------
//author: Corey Johnson
//problem: 1197 - "The Suspects"
//big help https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
//----------------
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <cstdlib>

#define N 30000 + 5 //max number of students
#define M 500 + 5 //max number of groups

using namespace std;

int numStudents, numGroups; //n and m values
vector<int> students[N]; //vector of students (set to maximum size)
vector<int> groups[M]; //vector of groups (set to maximum size)
bool dfsStudents[N], dfsGroups[M]; //boolean array for dfs search (again, set to maximum size)
int k, member, susGroup, susStudent; //k: number of students in each group, group member (placeholder), susGroup: placeholder for each group associated with sick student, susStudent: placeholder for each student associated with a suspected (sick) student --> to be called again in dfsSuspected

//dfsSuspected is a recursive search of the overall students 'graph'.
//it makes use of the dfsStudents & dfsGroups boolean arrays to keep track of already visited groups and students
int dfsSuspected(int n)
{
    int numSus = 1; //number of suspected students
    dfsStudents[n] = true; //student 0 is suspected initially

    for(int i = 0; i < students[n].size(); i++) {
        susGroup = students[n][i]; //read through each group associated with the suspected student
        dfsGroups[susGroup] = true; //set each group to true (so we can skip it later)

        for(int j = 0; j < groups[susGroup].size(); j++) {
            susStudent = groups[susGroup][j];
            if(dfsStudents[susStudent] == true) {
                continue;
            }

            numSus += dfsSuspected(susStudent);
        }
    }

    return numSus;
}

int main()
{    
    //freopen("the_suspects.txt", "r", stdin);

    while(scanf("%d %d", &numStudents, &numGroups)) {
        if(numStudents == 0 && numGroups == 0) {
            break;
        }

        //cout << numStudents << '\t' << numGroups << '\t' << endl;
        //reset the data space for each case
        memset(students, false, sizeof(students));
        memset(groups, false, sizeof(groups));
        memset(dfsStudents, false, sizeof(dfsStudents));
        memset(dfsGroups, false, sizeof(dfsGroups));

        for(int i = 0; i < numGroups; i++) {
            cin >> k;
            //cout << "k: " << k << '\t' << "members: ";
            while(k--) {
                scanf("%d", &member);
                groups[i].push_back(member); //add each member to each group
                students[member].push_back(i); //keep track of what groups each student is in
            }
            //cout << endl;
        }

        printf("%d\n", dfsSuspected(0));

    }
    return 0;
}
