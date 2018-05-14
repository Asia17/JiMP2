#include "Serialization.h"

namespace academia {


    Room::Room(int id, std::string name,Type type):id_(id),name_(name),type_(type){};
    void Room::Serialize(Serializer* serializer) const{
        serializer->Header("Room");
        serializer->IntegerField("id: ", id_);
        serializer->StringField("name: ",name_);
        serializer->StringField("type: ", ToString(type_));
        serializer->Footer("Room");
    }


    Building::Building(int id, std::string name, std::vector<Room> rooms):id_(id),name_(name) {
        for (auto x: rooms) {
            this->rooms_.emplace_back(x);
        }
    }
    void Building::Serialize(Serializer *serializer) const {
        std::vector<std::reference_wrapper<const Serializable>> rooms_wrapped(rooms_.begin(), rooms_.end());
        serializer->Header("Room");
        serializer->ArrayField("rooms", rooms_wrapped);
        serializer->Footer("Room");
    }
    int Building::Id() {
        {return this->id_;}
    }

    BuildingRepository::BuildingRepository( std::initializer_list<Building> buildings){
        for (auto x : buildings) {
            this->buildings.push_back(x);
        }
    }

    void BuildingRepository::Add(const Building &building){
        this->buildings.push_back(building);
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const{
        std::experimental::optional<Building> new_building;
        for(auto &building : buildings){
            if (building.id_ == id) {
                new_building.emplace(building);
                return new_building;
            }
        }
    }


    ////////SEERIALIZATORY DO JSON/////////////////

    void Room::Serialize(JsonSerializer *serializer) const {
        (*serializer->out_) << "{";
        serializer->IntegerField("id", id_);
        (*serializer->out_) << ", ";
        serializer->StringField("name", name_);
        (*serializer->out_) << ", ";
        serializer->StringField("type", ToString(type_));
        (*serializer->out_) << "}";

    }

    void Building::Serialize(JsonSerializer* serializer) const{
        std::vector<std::reference_wrapper<const Serializable>> rooms_wrapped(rooms_.begin(), rooms_.end());
        (*serializer->out_) << "{";
        serializer->IntegerField("id", id_);
        (*serializer->out_) << ", ";
        serializer->StringField("name", name_);
        (*serializer->out_) << ", ";
        serializer->ArrayField("rooms", rooms_wrapped);
        (*serializer->out_) << "}";
    }

    void BuildingRepository::StoreAll(JsonSerializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        (*serializer->out_) << "{";
        serializer->ArrayField("buildings", buildings_wrapped);
        (*serializer->out_) << "}";

    }



    //////////JSON FORMAT////////////////

    void JsonSerializer::Header(const std::string &object_name){
        (*out_) << "\"" <<  object_name << "\": [";
    }

    void JsonSerializer::Footer(const std::string &object_name){
        (*out_) << "]";
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_) << "\"" << field_name << "\": \"" << value << "\"";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        (*out_) << "\"" << field_name << "\": " << std::to_string(value);
    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        JsonSerializer serializer(out_);
        value.Serialize(&serializer);
    }

    void JsonSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {
        this->Header(field_name);
        bool IsFirst = true;
        for ( const Serializable &element:value) {
            if(!IsFirst)(*out_)<< ", ";
            else IsFirst = false;
            element.Serialize(this);
        }
        this->Footer(field_name);
    }

    ////////////SERIALIZAOTRY DO XML///////////////

    void Room::Serialize(XmlSerializer *serializer) const {

        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name",name_);
        serializer->StringField("type", ToString(type_));
        serializer->Footer("room");

    }

    void Building::Serialize(XmlSerializer* serializer) const {
        std::vector<std::reference_wrapper<const Serializable>> rooms_wrapped(rooms_.begin(), rooms_.end());
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name",name_);
        serializer->ArrayField("rooms", rooms_wrapped);

        serializer->Footer("building");
    }

    void BuildingRepository::StoreAll(XmlSerializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", buildings_wrapped);
        serializer->Footer("building_repository");

    }


    void BuildingRepository::StoreAll(Serializer* serializer)const{
        std::vector<std::reference_wrapper<const Serializable>> buildings_wrapped(buildings.begin(), buildings.end());
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", buildings_wrapped);
        serializer->Footer("building_repository");

    }

    ///////////////XML FORMAT/////////////////

    void XmlSerializer::Header(const std::string &object_name){
        (*out_) << "<" <<object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name){
        (*out_) << "<\\" <<object_name << ">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        (*out_) << "<" << field_name << ">" <<value<< "<\\" << field_name << ">";
    }


    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        (*out_) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        (*out_) << "<" << field_name << ">" << std::to_string(value)<< "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        XmlSerializer serializer(out_);
        value.Serialize(&serializer);
    }


    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value) {
        this->Header(field_name);
        for ( const Serializable& element : value) {
            element.Serialize(this);
        }
        this->Footer(field_name);
    }


}