#include "car_rental.hpp"

class Vehicle
{
protected:
  int dryWeight, seat, year;
  std::string type, licensePlate, brand, model;

public:
  Vehicle() {}
  Vehicle(int dryWeight, int seat, int year, std::string type, std::string brand, std::string model, std::string licensePlate) : dryWeight(dryWeight), seat(seat), type(type), year(year), brand(brand), model(model), licensePlate(licensePlate) {}

public:
  int getWeight() const { return dryWeight; }
  int getSeat() const { return seat; }
  int getYear() const { return year; }
  std::string getType() const { return type; }
  std::string getBrand() const { return brand; }
  std::string getModel() const { return model; }
  std::string getPlate() const { return licensePlate; }
  void setWeight(int value) { dryWeight = value; }
  void setSeat(int value) { seat = value; }
  void setYear(int value) { year = value; }
  void setType(std::string value) { type = value; }
  void setBrand(std::string value) { brand = value; }
  void setModel(std::string value) { model = value; }
  void setPlate(std::string value) { licensePlate = value; }
}; // class Vehicle

class Contract
{
protected:
  int licenseID, timeStart, timeEnd;
  std::string name, locStart, locEnd;
  Vehicle *vehicle;

public:
  Contract() {}
  Contract(int licID, int timeStart, int timeEnd, std::string name, std::string locStart, std::string locEnd, Vehicle *vehicle = nullptr) : licenseID(licID), timeStart(timeStart), timeEnd(timeEnd), name(name), locStart(locStart), locEnd(locEnd), vehicle(vehicle) {}

public:
  int getID() const { return licenseID; }
  int getTimeStart() const { return timeStart; }
  int getTimeEnd() const { return timeEnd; }
  std::string getName() const { return name; }
  std::string getLocStart() const { return locStart; }
  std::string getLocEnd() const { return locEnd; }
  Vehicle *getVehicle() const { return vehicle; }
  void setID(int value) { licenseID = value; }
  void setTimeStart(int value) { timeStart = value; }
  void setTimeEnd(int value) { timeEnd = value; }
  void setName(std::string value) { name = value; }
  void setLocStart(std::string value) { locStart = value; }
  void setLocEnd(std::string value) { locEnd = value; }
  void setVehicle(Vehicle *value) { vehicle = value; }

public:
  Vehicle *operator*() const { return vehicle; }
}; // class Contract

class BookAndRent : public IBookAndRent
{
protected:
  std::vector<Contract *> rentals;
  std::vector<Contract *> bookings;

public:
  ;

}; // class BookAndRent
