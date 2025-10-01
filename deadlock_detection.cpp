#include <iostream>
using namespace std;

// Function to check for deadlock
bool checkDeadlock(int** request, int** alloc, int* avail, int P, int R) {
    vector<bool> finish(P, false);  // Replace the VLA
    int work[R];

    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool possible = true;
                for (int j = 0; j < R; j++) {
                    if (request[p][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < R; j++) {
                        work[j] += alloc[p][j];
                    }
                    finish[p] = true;  // Works as expected
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            cout << "System is in deadlock." << endl;
            return true;
        }
    }

    cout << "System is not in deadlock." << endl;
    return false;
}


int main() {
    int P, R;
    cout << "Enter number of processes: ";
    cin >> P;
    cout << "Enter number of resources: ";
    cin >> R;

    int* avail = new int[R];
    cout << "Enter available resources: ";
    for (int i = 0; i < R; i++) {
        cin >> avail[i];
    }

    int** request = new int*[P];
    int** alloc = new int*[P];
    for (int i = 0; i < P; i++) {
        request[i] = new int[R];
        alloc[i] = new int[R];
    }

    cout << "Enter request matrix: \n";
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> request[i][j];
        }
    }

    cout << "Enter allocation matrix: \n";
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            cin >> alloc[i][j];
        }
    }

    checkDeadlock(request, alloc, avail, P, R);

    // Free dynamically allocated memory
    delete[] avail;
    for (int i = 0; i < P; i++) {
        delete[] request[i];
        delete[] alloc[i];
    }
    delete[] request;
    delete[] alloc;

    return 0;
}
