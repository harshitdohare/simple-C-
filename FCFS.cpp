#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

// Function to sort processes according to their arrival time
bool sortByArrivalTime(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first < b.first);
}

int main() {
    int n; // number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<pair<int, int>> P; // vector of pairs to store arrival time and burst time for each process

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        int at, bt;
        cout << "Enter arrival time and burst time for process " << i+1 << ": ";
        cin >> at >> bt;
        P.push_back(make_pair(at, bt)); // insert pair into vector
    }

    // Sort P according to their arrival time
    sort(P.begin(), P.end(), sortByArrivalTime);

    // Calculate waiting time and turnaround time for each process
    int CT = P[0].first; // current time
    vector<int> WT(n, 0);
    vector<int> TAT(n, 0);
    for (int i = 0; i < n; i++) {
        CT += P[i].second; // add burst time of current process to current time
        TAT[i] = CT - P[i].first; // turnaround time = current time - arrival time
        WT[i] = TAT[i] - P[i].second; // waiting time = turnaround time - burst time
    }

    // Calculate average waiting time and average turnaround time
    float twt=0;
    float tat= 0;

    for(int i=0; i<n; i++)
    {
        twt += WT[i];
        tat += TAT[i];
    }

    // Output results
    cout << WT[0] << endl;
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t\t" << P[i].first << "\t\t" << P[i].second << "\t\t"
             << WT[i] << "\t\t" << TAT[i] << endl;
    }
    cout << "Average waiting time: " << twt/n << endl;
    cout << "Average turnaround time: " << tat/n << endl;

    return 0;
}
