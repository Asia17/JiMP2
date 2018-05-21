//
// Created by Joanna on 16.05.2018.
//

#include "Scheduler.h"
namespace academia {

    size_t Schedule::Size() const {
        return VectorWithAll.size();
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        SchedulingItem nowy = item;
        zajete_sloty.insert(item.time_slot);
        VectorWithAll.emplace_back(nowy);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule ForThisTeacher;
        for(int i=0; i < VectorWithAll.size(); i++){
            if(VectorWithAll[i].teacher_id == teacher_id){
                ForThisTeacher.VectorWithAll.emplace_back(VectorWithAll[i]);
            }
        }
        return ForThisTeacher;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule ForThisRoom;
        for (int i=0; i < VectorWithAll.size(); i++){
            if (VectorWithAll[i].room_id == room_id){
                ForThisRoom.VectorWithAll.emplace_back(VectorWithAll[i]);
            }
        }
        return ForThisRoom;
    }


    Schedule Schedule::OfYear(int year) const {
        Schedule ForThisYear;
        for (int i=0; i < VectorWithAll.size();i++){
            if (VectorWithAll[i].year == year){
                ForThisYear.VectorWithAll.emplace_back(VectorWithAll[i]);
            }
        }
        return ForThisYear;
    }

    SchedulingItem Schedule::operator[](int i) const {
        return VectorWithAll[i];
    }

    std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::set<int> wolne_sloty;

        //całkowite wypełnienie "wolnego" w sposób  dla 20: 1 ⇒ pon 8:00-10:00, 2 ⇒ pon 10:00-12:00, … 20 ⇒ pią 14:00-16:00
       for (int i=1; i <=n_time_slots; i++){
            wolne_sloty.insert(i);
        }

        //std::iota(wolne_sloty.begin(), wolne_sloty.end(), 1);  zrobi to samo co pętla ale dla vectora a my chcemy seta


        //idea: wyznaczyć zajęte okna (przecięcie zbiorów 'wypelnione wolne' i 'zajete' i zrobić z nich wektor, odjąc zawartosc wektora 'zajętych' od 'wolnych' => faktycznie wolne okna
        //trzeba posorotowac wektor 'zajete_sloty'
        //std::sort(zajete_sloty.begin(),zajete_sloty.end());   nie posortuje sie w funkcji const! :(  (trzeba sorotować po dodawaniu)

        std::vector<int> wolne_sloty_minus_zajete_sloty;
        //std::vector<int> wolne_sloty_minus_przeciecie_zajetych;
        //std::set_intersection(wolne_sloty.begin(),wolne_sloty.end(),zajete_sloty.begin(),zajete_sloty.end(),std::back_inserter(przeciecie_zajetych));
       // std::set_difference(wolne_sloty.begin(),wolne_sloty.end(),przeciecie_zajetych.begin(),przeciecie_zajetych.end(),std::back_inserter(wolne_sloty_minus_przeciecie_zajetych));
        std::set_difference(wolne_sloty.begin(),wolne_sloty.end(),zajete_sloty.begin(),zajete_sloty.end(),std::back_inserter(wolne_sloty_minus_zajete_sloty));
        return wolne_sloty_minus_zajete_sloty;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        std::vector<SchedulingItem> wartosci_planu;
        //para - klucz= rozpiska nauczycieli, wartość = prowadzone przedmioty przez nauczyciela
     // para2 - klucz= konkretny rocznik, wartość = wymagane dla niego przedmioty
        for(auto para:teacher_courses_assignment){
            for (auto przedmiot:para.second){
                for(auto para2:courses_of_year){
                    if(para2.second.find(przedmiot) != para2.second.end()){
                        wartosci_planu.emplace_back(SchedulingItem(przedmiot,para.first,0,0,para2.first));
                    }
                }  //przyporządkowanie nauczyciela
            }
        }
    if(n_time_slots*rooms.size() < wartosci_planu.size()){
        throw NoViableSolutionFound("Nie mozna utworzyc planu!");
    }

        int licznik=0;
        for (auto pomieszcznie:rooms){
            for(int slot=1; slot <=n_time_slots;slot++) {
                if (licznik < wartosci_planu.size()) {
                    wartosci_planu[licznik].time_slot = slot;
                    wartosci_planu[licznik].room_id = pomieszcznie;

                }  //przyporządkowanie sali
                licznik++;
            }
        }
// para3 - klucz= konkretny rocznik, wartość = wymagane dla niego przedmioty
        //para4 - klucz= rozpiska nauczycieli, wartość = prowadzone przedmioty przez nauczyciela
        int licznik_przedmiotow;
        for(auto para3:courses_of_year){
            for(auto przedmiot:para3.second){
                licznik_przedmiotow==0;
                for(auto para4:teacher_courses_assignment){
                    licznik += std::count(para4.second.begin(),para4.second.end(),przedmiot);

                }
                if(n_time_slots<licznik_przedmiotow){
                    throw NoViableSolutionFound("Nie mozna utowrzyc planu!");
                }
            }
        }

        return Schedule{wartosci_planu};


    }


}