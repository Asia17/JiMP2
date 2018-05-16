//
// Created by Joanna on 16.05.2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>



class SchedulingItem {   //  "obiekt samych wartości"
public:
    SchedulingItem( int course_id_, int teacher_id_, int room_id_, int time_slot_):
    course_id(course_id_),teacher_id(teacher_id_),room_id(room_id_),time_slot(time_slot_){};
    ~SchedulingItem()= default;
private:
    int course_id;
    int teacher_id;
    int room_id;
    int time_slot;
};
class Schedule{
public:
    Schedule();
    ~Schedule()= default;
    void ScheduleOfTeacher(int teacher_id) const; //wylicza fragment harmonogramu związany z danym nauczycielem akademickim
    void ScheduleOfRoom(int room_id) const;
    void ScheduleOfYear(int year) const;
    std::vector<int> AvailableTimeSlots(int n_time_slots) const; //wylicza wektor jeszcze nie zajętych okien czasowych, gdzie n_time_slots jest maksymalną wartością okna czasowego
    void InsertScheduleItem(const SchedulingItem &item); //- wstawia nowy element planu
    size_t Size() const; //- zwaraca rozmiar planu

};


class Scheduler {
public:
    virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
};
class GreedyScheduler : public Scheduler{
public:
    Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
};

class NoViableSolutionFound{}; //wyjątek wyrzucany, gdy nie udaje się stworzyć planu

#endif //JIMP_EXERCISES_SCHEDULER_H
