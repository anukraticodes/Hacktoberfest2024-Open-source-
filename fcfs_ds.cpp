#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int fcfs(const vector<int> &requests, int head)
{
    int seek_count = 0;
    int current = head;

    cout << "Seek Sequence: " << current;
    for (int request : requests)
    {
        seek_count += abs(request - current);
        current = request;
        cout << " -> " << current;
    }
    cout << endl;
    return seek_count;
}

int main()
{
    vector<int> requests = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int disk_size = 200;

    cout << "FCFS Seek Time: " << fcfs(requests, head) << endl;
    return 0;
}
