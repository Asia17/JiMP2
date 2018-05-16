//
// Created by Joanna on 16.05.2018.
//

#include "Scheduler.h"
namespace academia {

    size_t Schedule::Size() const {
        return wektor_wartosci_.size();
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        SchedulingItem nowy = item;
        zajete_sloty.emplace_back(item.time_slot);
        wektor_wartosci_.emplace_back(nowy);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule ForThisTeacher;
        for(int i=0; i < wektor_wartosci_.size(); i++){
            if(wektor_wartosci_[i].teacher_id == teacher_id){
                ForThisTeacher.wektor_wartosci_.emplace_back(wektor_wartosci_[i]);
            }
        }
        return ForThisTeacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule ForThisRoom;
        for (int i=0; i < wektor_wartosci_.size(); i++){
            if (wektor_wartosci_[i].room_id == room_id){
                ForThisRoom.wektor_wartosci_.emplace_back(wektor_wartosci_[i]);
            }
        }
        return ForThisRoom;
    }


    Schedule Schedule::OfYear(int year) const {
        Schedule ForThisYear;
        for (int i=0; i < wektor_wartosci_.size();i++){
            if (wektor_wartosci_[i].year == year){
                ForThisYear.wektor_wartosci_.emplace_back(wektor_wartosci_[i]);
            }
        }
        return ForThisYear;
    }

    SchedulingItem Schedule::operator[](int i) const {
        return wektor_wartosci_[i];
    }
}