//
// Created by Joanna on 16.05.2018.
//
#include "Scheduler.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <memory>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <ostream>

using namespace academia;
using namespace std;

int main(){

    unique_ptr<Scheduler> scheduler = make_unique<GreedyScheduler>();

    vector<int> rooms{1000, 2000};
    map<int, vector<int>> teachers{make_pair(100, vector<int>{10, 10, 10}), make_pair(200, vector<int>{10, 10})};
    map<int, set<int>> years{make_pair(1, set<int>{10})};

    Schedule schedule = scheduler->PrepareNewSchedule(rooms,teachers,years,3);
    for (int i:schedule.zajete_sloty)
        cout<<i<<endl;
    cout<<endl;

    for (size_t i=0;i<schedule.Size();i++)
        cout<<schedule[i].TeacherId()<<endl;
    return 0;
}