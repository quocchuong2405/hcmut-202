/*
 * A car rental company offers vehicles for rent. It manages a fleet of vehicles and a set of rental contracts. Demonstrate how you code in C++ to implement a management system for this car rental company. Explain how you respect the following guidelines you learned in the lecture.
 *
 * Knowing the difference between the interface and implementation
 * Thinking more abstractly
 * Giving the user the minimal interface possible
 */

/*
 * Let's revisit the OO design for a car rental company.
 *
 * Provide multiple constructors for creating a car rent. Define multiple methods that add a vehicle to the fleet of the said car rental company.
 */

/*
 * For the sake of fleet maintenance, the car rental company would like to keep track the routine maintenance performed on its vehicles. More specifically, each vehicle has a service history telling how and when its engine, transmission and tires get serviced. In your source code, define the following methods as virtual for your superclass Vehicle. Override them in your subclasses. When implementing them, you should check if the vehicle, depending on its current mileage, really needs to have its engine / transmission / tires serviced. Vehicles of different types get serviced differently at different frequencies.
 *
 * serviceEngine // add a record to the vehicle history telling how the engine of the vehicle gets serviced (oil change, minor, major)
 *
 * serviceTransmission // add a record to the vehicle history telling how the transmission of the vehicle gets serviced (fluid change, minor, overhaul)
 *
 * serviceTires // add a record to the vehicle history telling how the tires of the vehicle get serviced (adjustment, replacement)
 *
 * Make sure that Vehicle is an abstract class that is connected to ServiceHistory via a composition.
 *
 * Your class CarRentalManagement has a method, called serviceFleet, that basically iterates through all vehicles it manages. For each vehicle, this operation calls the above methods to perform appropriate services if needed.
 */

/*
 *  BookAndRent is an interface that is implemented by CarRentalManagement
 *
 *  Should we have an interface that represents the job of getting the car fleet serviced?
 *
 *  Rent is a class that describes a car rental contract. Any interface being implemented by Rent?
 */

/*
 * Remember that a vehicle in your car rental management company is associated with a service history, which keeps track of all maintenance jobs that have been done to the vehicle in question. A maintenance job should record the following pieces of information: mileage of the vehicle and date/time when the job was carried out, kind of service being performed (e.g., tires, engine oil, transmission fluid), costs, garage where the job was done.
 *
 * In C++, overload the subtraction - operator to imply the distance the vehicle had been driven between any two maintenance jobs. Moreover, you may overload the comparison operators to see if a maintenance job takes place before or after another.
 *
 * Note: don't forget to check if the given two maintenance jobs were done for the same vehicle. The above-mentioned operators would go meaningless otherwise.
 */

/*
 * Create a document that captures a certain maintenance activity. Attempt to print the JSON document out to your console.
 *
 * Go further creating a JSON document that represents the whole service history of a vehicle.
 *
 * You are not expected to try parsing a JSON document you have created at this stage.
*/

#ifndef CAR_RENTAL_HPP
#define CAR_RENTAL_HPP

#include <string>
#include <vector>
#include <iostream>

#pragma region Vehicles
class IVehicle
{
public:
  virtual ~IVehicle() {}
  virtual int getWeight() const = 0;
  virtual int getSeat() const = 0;
  virtual int getYear() const = 0;
  virtual std::string getType() const = 0;
  virtual std::string getBrand() const = 0;
  virtual std::string getModel() const = 0;
  virtual std::string getPlate() const = 0;
}; // end class IVehicle

class Vehicle : public IVehicle
{
protected:
  int weight, seats, year, mileage, cargo_space;
  std::string type, // * Car, Truck, Van, SUV...
      brand,        // * Toyota, Ford...
      model,        // * Camry, Mustang...
      plate,        // * License plate
      drivetrain;   // * 2x2, 4x4, 2x6, 4x6, 6x6...
  bool available = true;

public:
  Vehicle(int weight, int seats, int cargo_space, int year, std::string type, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : weight(weight), seats(seats), cargo_space(cargo_space), year(year), type(type), brand(brand), model(model), plate(plate), drivetrain(drivetrain) {}

public:
  int getWeight() const { return weight; }
  int getSeat() const { return seats; }
  int getCargoSpace() const { return cargo_space; }
  int getYear() const { return year; }
  int getMileage() const { return mileage; }
  std::string getType() const { return type; }
  std::string getBrand() const { return brand; }
  std::string getModel() const { return model; }
  std::string getPlate() const { return plate; }
  bool isAvailable() const { return available; }
  void setWeight(int value) { weight = value; }
  void setSeat(int value) { seats = value; }
  void setType(std::string value) { type = value; }
  void setAvailability(bool value) { available = value; }

public:
  virtual void serviceEngine();
  virtual void serviceTransmission();
  virtual void serviceTires();
}; // end class Vehicle

class Sedan : public Vehicle
{
public:
  Sedan(int weight, int seats, int cargo_vroom, int year, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : Vehicle{weight, seats, cargo_vroom, year, "Sedan", brand, model, plate, drivetrain} {}
}; // end class Sedan

class SUV : public Vehicle
{
public:
  SUV(int weight, int seats, int cargo_vroom, int year, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : Vehicle{weight, seats, cargo_vroom, year, "SUV", brand, model, plate, drivetrain} {}
}; // end class SUV

class Coupe : public Vehicle
{
public:
  Coupe(int weight, int seats, int cargo_vroom, int year, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : Vehicle{weight, seats, cargo_vroom, year, "Coupe", brand, model, plate, drivetrain} {}
}; // end class Coupe

class Van : public Vehicle
{
public:
  Van(int weight, int seats, int cargo_vroom, int year, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : Vehicle{weight, seats, cargo_vroom, year, "Van", brand, model, plate, drivetrain} {}
}; // end class Van

class Truck : public Vehicle
{
public:
  Truck(int weight, int seats, int cargo_vroom, int year, std::string brand, std::string model, std::string plate, std::string drivetrain = "2x4") : Vehicle{weight, seats, cargo_vroom, year, "Truck", brand, model, plate, drivetrain} {}

}; // end class Truck
#pragma endregion

#pragma region Contract
class IContract
{
public:
  virtual ~IContract() {}
  virtual void who() const = 0;
  virtual void what() const = 0;
}; // end class IContract

class Contract : public IContract
{
protected:
  std::string name, socialID, licenseID, dob;
  bool male;
  Vehicle *vehicle;

public:
  Contract(std::string name, std::string socialID, std::string licenseID, std::string dob, bool male, Vehicle *vehicle) : name(name), socialID(socialID), licenseID(licenseID), dob(dob), male(male), vehicle(vehicle) {}
  Contract(std::string name, std::string socialID, std::string licenseID, std::string dob, Vehicle *vehicle) : name(name), socialID(socialID), licenseID(licenseID), dob(dob), male(true), vehicle(vehicle) {}

public:
  void who() const
  {
    std::cout << "Name: " << name << std::endl
              << "Social ID: " << socialID << std::endl
              << "License ID: " << licenseID << std::endl
              << "Date of birth: " << dob << "Gender: " << ((male) ? "Male" : "Female") << std::endl;
  }

  void what() const
  {
    std::cout << vehicle->getYear() << " " << vehicle->getBrand() << " " << vehicle->getModel() << " " << vehicle->getType() << std::endl;
  }
  Vehicle *operator*() { return vehicle; }
}; // end class Contract
#pragma endregion

#pragma region Rental Service
class IBookAndRent
{
public:
  virtual ~IBookAndRent() {}
  virtual int newRent(std::string name, std::string socialID, std::string licenseID, std::string dob, bool male, Vehicle *vehicle) = 0;
  virtual int newBook(std::string name, std::string socialID, std::string licenseID, std::string dob, bool male, Vehicle *vehicle) = 0;
  virtual int endRent() = 0;
  virtual int endBook() = 0;
}; // class IBookAndRent

class BookAndRent : public IBookAndRent
{
protected:
  std::vector<Contract *> bookings;
  std::vector<Contract *> rentals;

public:
  ~BookAndRent() { declare_bankruptcy(); }
  int newRent(std::string name, std::string socialID, std::string licenseID, std::string dob, bool male, Vehicle *vehicle)
  {
    vehicle->setAvailability(false);
    rentals.push_back(new Contract(name, socialID, licenseID, dob, male, vehicle));
    return 0;
  }
  int newBook(std::string name, std::string socialID, std::string licenseID, std::string dob, bool male, Vehicle *vehicle)
  {
    vehicle->setAvailability(false);
    bookings.push_back(new Contract(name, socialID, licenseID, dob, male, vehicle));
    return 0;
  }
  int endRent()
  {
    std::cout << "Thank you for using our service." << std::endl;
    return 0;
  }
  int endBook()
  {
    std::cout << "Thank you for using our service." << std::endl;
    return 0;
  }
  void declare_bankruptcy()
  {
    std::cout << "Thank you for being a part with us through all those years." << std::endl
              << "All good things must come to an end, and this is the end of our journey together." << std::endl
              << "We hope that we have created great memories for you to cherish." << std::endl
              << "RIP 2021 - 2021" << std::endl;
  }
  void serviceFleet();
}; // class BookAndRent
#pragma endregion

#endif
