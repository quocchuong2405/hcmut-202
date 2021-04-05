/*
 * A car rental company offers vehicles for rent. It manages a fleet of vehicles and a set of rental contracts. Demonstrate how you code in C++ to implement a management system for this car rental company. Explain how you respect the following guidelines you learned in the lecture.
 *
 * Knowing the difference between the interface and implementation
 * Thinking more abstractly
 * Giving the user the minimal interface possible
 * EuropCar
 * Dollar Rent A Car
 * Enterprise Rent-A-Car
 */

/*
 * Let's revisit the OO design for a car rental company.
 *
 * Provide multiple constructors for creating a car rent. Define multiple methods that add a vehicle to the fleet of the said car rental company.
 */

#ifndef CAR_RENTAL_HPP
#define CAR_RENTAL_HPP

#include <string>
#include <vector>

class Vehicle
{
public:
  Vehicle();
  Vehicle(int, int, int, std::string, std::string, std::string, std::string);

public:
  int getWeight() const;
  int getSeat() const;
  int getYear() const;
  std::string getType() const;
  std::string getBrand() const;
  std::string getModel() const;
  std::string getPlate() const;
  void setWeight(int);
  void setSeat(int);
  void setYear(int);
  void setType(std::string);
  void setBrand(std::string);
  void setModel(std::string);
  void setPlate(std::string);
}; // class Vehicle

class Contract
{
public:
  Contract();
  Contract(int, int, int, std::string, std::string, std::string, Vehicle *);

public:
  int getID() const;
  int getTimeStart() const;
  int getTimeEnd() const;
  std::string getName() const;
  std::string getLocStart() const;
  std::string getLocEnd() const;
  Vehicle *getVehicle() const;
  void setID(int);
  void setTimeStart(int);
  void setTimeEnd(int);
  void setName(std::string);
  void setLocStart(std::string);
  void setLocEnd(std::string);
  void setVehicle(Vehicle *);

public:
  Vehicle *operator*();
}; // class Contract

class IBookAndRent
{
public:
  virtual int netRent() = 0;
  virtual int newBook() = 0;
  virtual int getRent() = 0;
  virtual int getBook() = 0;
}; // class IBookAndRent

class BookAndRent : public IBookAndRent
{
public:
  int newRent(Contract *);
  int newBook(Contract *);
}; // class BookAndRent

#endif
