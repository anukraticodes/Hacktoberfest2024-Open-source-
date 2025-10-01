#include <iostream>
#include <cstring>
#include<vector>
using namespace std;


void firstfit(vector<int> memory, vector<int> &process){
    int internal = 0, external = 0;
    for(int i =0; i< process.size(); i++){
        for(int j =0; j< memory.size(); j++){
            if(process[i] <= memory[j]){
              internal += memory[j] - process[i];
               memory[j] = 0;
              break;
    }
    }
    }
    for(int i : memory) external += i;
    cout<<"internal: "<<internal<<" external: "<<external<<endl;
    }


int main() {
    vector<int> memory = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    firstfit(memory, process);
    // bestfit(memory, process);
    return 0;
    }
