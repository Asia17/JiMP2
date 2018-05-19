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
#include <algorithm>
#include <numeric>

namespace academia {

    class SchedulingItem {   //  "obiekt samych wartości"
    public:
        SchedulingItem(int course_id_, int teacher_id_, int room_id_, int time_slot_,int year_) :
                course_id(course_id_), teacher_id(teacher_id_), room_id(room_id_), time_slot(time_slot_),year(year_) {};
        ~SchedulingItem() = default;
        int CourseId() const { return course_id; };
        int TeacherId() const { return teacher_id; };
        int RoomId() const { return room_id; };
        int TimeSlot() const { return time_slot; };
        int Year() const { return year;};
        int time_slot;
        int course_id;
        int teacher_id;
        int room_id;
        int year;
    private:


    };

    class Schedule {
    public:
        Schedule(){};
        explicit Schedule(std::vector<SchedulingItem> wektor_wartosci):VectorWithAll(wektor_wartosci){};
        ~Schedule() = default;
        Schedule OfTeacher(int teacher_id) const; //wylicza fragment harmonogramu związany z danym nauczycielem akademickim
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const; //wylicza wektor jeszcze nie zajętych okien czasowych, gdzie n_time_slots jest maksymalną wartością okna czasowego
        void InsertScheduleItem(const SchedulingItem &item); //- wstawia nowy element planu
        size_t Size() const; //- zwaraca rozmiar planu
        SchedulingItem operator[](int i) const;
        std::set<int> zajete_sloty;   // set a nie vector bo set jest automatycznie posortowany co sie przydaje w set_intersection i set_difference
    private:
        std::vector<SchedulingItem> VectorWithAll;

    };


    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
        /* rooms - dostępne pomieszczenia
        teacher_courses_assignment - rozpiska nauczycieli (klucz w mapie) i prowadząnych przez nich przedmiotów (wartosć w mapie)
        courses_of_year - kursy (wartość w mapie) wymagane dla danego rocznika (klucz w mapie)
        n_time_slots - ilość slotów czasowych*/
    };

    class GreedyScheduler : public Scheduler { //pętla która próbuje przypisywać po kolei przedmioty do sal i nauczycieli
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override;
    };

    class NoViableSolutionFound {
    public:
        NoViableSolutionFound(std::string msg) : msg_(msg) {};
        ~NoViableSolutionFound() = default;
    private:
        std::string msg_;
    }; //wyjątek wyrzucany, gdy nie udaje się stworzyć planu
}
#endif //JIMP_EXERCISES_SCHEDULER_H
