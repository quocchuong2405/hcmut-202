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

#include <string>
#include <deque>

class IRentalService
{
public:
  virtual ~IRentalService() {}
  virtual int newRent() = 0;
}; // class IRentalService

class RentalService : public IRentalService
{
protected:
  class Vehicle;
  class Renter;
  class Rental;

protected:
  enum VehicleType
  {
    Car,
    VanNTruck,
    Prestige,
  };
  std::deque<Rental *> RentMgmt;

protected:
  class Vehicle
  {
  protected:
    VehicleType type;
    std::string licensePlate;

  public:
    Vehicle(std::string lp, VehicleType tp = Car) : licensePlate(lp), type(tp) {}
  }; // class Vehicle

  class Renter
  {
  protected:
    std::string location;
    int startDate;
    int returnDate;

  public:
    Renter(std::string loc, int pick, int ret) : location(loc), startDate(pick), returnDate(ret) {}
  }; // class Renter

  class Rental
  {
  protected:
    Renter *renter;
    Vehicle *vehicle;

  public:
    Rental(std::string loc, int pick, int ret, std::string lp, VehicleType tp = Car)
    {
      renter = new Renter(loc, pick, ret);
      vehicle = new Vehicle(lp, tp);
    }
  }; // class Rental

public:
  int newRent(std::string loc, int pick, int ret, std::string lp, VehicleType tp = Car)
  {
    RentMgmt.push_back(new Rental(loc, pick, ret, lp, tp));
  }
}; // class RentalService
