#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <experimental/optional>
#include <functional>



namespace academia {

    class Serializable;   //widoczność

    class Serializer {   // centrum dowodzenia
    public:
        Serializer(){};
        Serializer(std::ostream *out){};
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value)= 0;
        virtual void StringField(const std::string &field_name, const std::string &value)= 0;
        virtual void BooleanField(const std::string &field_name, bool value)= 0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)= 0;
        virtual void ArrayField(const std::string &field_name, const std::vector <std::reference_wrapper<const Serializable>> &value)= 0;
        virtual void Header(const std::string &object_name)= 0;
        virtual void Footer(const std::string &object_name)= 0;
        virtual  ~Serializer(){};

    };
    class XmlSerializer;   // widoczność

    class JsonSerializer;   //widoczność

    class Serializable {
    public:
        virtual void Serialize(Serializer* serializer) const = 0;
        virtual void Serialize(JsonSerializer* serializer) const = 0;
        virtual void Serialize(XmlSerializer* serializer) const = 0;
    };

    class Room : public Serializable{
    public:
        enum class Type{   //enum-może przyjąć tylko te 3 rodzaje
            CLASSROOM,
            LECTURE_HALL,
            COMPUTER_LAB
        };
        Room(int id, std::string name,Type type);
        Room(){};
        ~Room(){};
        void Serialize(Serializer* serializer) const override;
        void Serialize(JsonSerializer* serializer)const;
        void Serialize(XmlSerializer* serializer)const;
        std::string name_;
        int id_;
        Type type_;


        std::string ToString(const Type &type) const {
            switch (type) {
                case Type::CLASSROOM:
                    return "CLASSROOM";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";
            }
        }
    };

    class Building : public Serializable {
    private:
        std::string name_;

        std::vector<Room> rooms_;
    public:
        Building(){};
        void Serialize(Serializer* serializer) const override;
        void Serialize(JsonSerializer* serializer) const;
        void Serialize(XmlSerializer* serializer) const;
        int Id();
        int id_;   // musszę dać jako public
        Building(int id, std::string name, std::vector<Room> rooms);
    };


    class BuildingRepository{
    private:
        std::vector<Building> buildings;
    public:
        BuildingRepository(){};
        BuildingRepository( std::initializer_list<Building> buildings);
        void Add(const Building &building);//zapomniałam o dodawaniu w poprzednim kroku
        std::experimental::optional<Building> operator[](int id) const;
        //Wszystko do StoreAll?
        void StoreAll(Serializer *serializer)const;
        void StoreAll(JsonSerializer* serializer)const;
        void StoreAll(XmlSerializer* serializer)const;
        ~BuildingRepository(){};
    };


///////////JSON////////////////
    class JsonSerializer{
    public:
        JsonSerializer(std::stringstream* out):out_(out) {}
        void IntegerField(const std::string &field_name, int value);
        void DoubleField(const std::string &field_name, double value);
        void StringField(const std::string &field_name, const std::string &value);
        void BooleanField(const std::string &field_name, bool value);
        void SerializableField(const std::string &field_name, const Serializable &value);
        void ArrayField(const std::string &field_name,const std::vector <std::reference_wrapper<const Serializable>> &value);
        void Header(const std::string &object_name);
        void Footer(const std::string &object_name);
        ~JsonSerializer(){};
    //w private nie działa :/
        std::stringstream* out_;
    };

    //////////////XML////////////////
    class XmlSerializer{
    public:
        XmlSerializer(std::stringstream* out):out_(out){}
        void IntegerField(const std::string &field_name, int value);
        void DoubleField(const std::string &field_name, double value);
        void StringField(const std::string &field_name, const std::string &value);
        void BooleanField(const std::string &field_name, bool value);
        void SerializableField(const std::string &field_name, const Serializable &value);
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value);
        void Header(const std::string &object_name);
        void Footer(const std::string &object_name);
        ~XmlSerializer(){};
    private:
        std::stringstream* out_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H