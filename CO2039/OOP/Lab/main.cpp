#include "car_rental.hpp"
#include <iostream>
#include <string>
#include <string.h> // for strcmp()
#include <unistd.h> // for system()

int main(int argc, char **argv)
{
  char choice;
  bool running = true;
  std::string name, socialID, licenseID, dob;
  bool male;
  IBookAndRent *BnR = new BookAndRent();

  std::string foo;
  int opt = 0;

#pragma region Init Vehicles
  std::vector<Vehicle *> vehicles;
  vehicles.push_back(new Sedan(550, 4, 450, 2010, "Toyota", "Corolla", "IDGAF"));
  vehicles.push_back(new SUV(1080, 7, 900, 2016, "Toyota", "Rush", "DEADBEEF"));
  vehicles.push_back(new Coupe(990, 4, 400, 2018, "Lexus", "LC 500", "STAT200", "4x4"));
  vehicles.push_back(new Sedan(1200, 4, 340, 1994, "Ford", "Mustang", "THUG"));
  vehicles.push_back(new Van(2400, 16, 1000, 2012, "Toyota", "Hiace", "HITHERE"));
  vehicles.push_back(new Truck(3500, 2, 1200, 2019, "Ford", "F150", "MISBEHAVE"));
  vehicles.push_back(new Truck(10500, 4, 10000, 1984, "Tatra", "IDK", "DMZ", "8x8"));
  vehicles.push_back(new Truck(20000, 3, 18000, 2008, "MAC", "GAZ", "UCME", "4x8"));
  vehicles.push_back(new Sedan(1600, 4, 1100, 2018, "Tesla", "Model 3", "BACON"));
  vehicles.push_back(new Sedan(550, 4, 400, 1981, "Reliant Robin", "Mk3", "ROLLER", "2x3"));

  for(Vehicle* vehicle:vehicles)
    vehicle->addMileage(rand() % 7000);
#pragma endregion

#pragma region Init Contracts

#pragma endregion

  while (running)
  {
    std::cout << "Hey there handsome." << std::endl
              << "Since you're here, do you want to" << std::endl
              << "[0] Exit the program and kill yourself" << std::endl
              << "[1] Rent a car" << std::endl
              << "[2] Book a car" << std::endl
              << "[3] Show all vehicles" << std::endl
              << "[4] Increase mileage" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
#pragma region Exit
    case '0':
      running = false;
      system("clear");
      break;
#pragma endregion

#pragma region Rent
    case '1':
      std::cout << "Gotcha. Getting you there right now." << std::endl;
      sleep(1);
      system("clear");

      std::cout << "We will need some information from you. Please fill in the following form." << std::endl;
      std::cin.ignore();

      std::cout << "Your name: ";
      std::getline(std::cin, name);

      std::cout << "Your date of birth: ";
      std::getline(std::cin, dob);

      std::cout << "Your social ID: ";
      std::getline(std::cin, socialID);

      std::cout << "Your license ID: ";
      std::getline(std::cin, licenseID);

      std::cout << "We are almost finished. Now we just want to know if you are male or female" << std::endl
                << "(1/0), defaults to male: ";
      std::getline(std::cin, foo);
      male = foo.compare(std::to_string(1)) == 0 ? true : false;

      system("clear");
      std::cout << "Well done. Choose a vehicle and we are ready to go." << std::endl;
      for (int i = 0; i < vehicles.size(); i += 1)
      {
        if (vehicles[i]->isAvailable())
          std::cout << "[" << i << "] "
                    << vehicles[i]->getYear() << " "
                    << vehicles[i]->getBrand() << " "
                    << vehicles[i]->getModel() << " "
                    << vehicles[i]->getType() << ", "
                    << vehicles[i]->getMileage() << " miles" << std::endl;
      }
      std::cout << "Your choice? ";
      std::getline(std::cin, foo);
      opt = stoi(foo);

      system("clear");
      if (BnR->newRent(name, socialID, licenseID, dob, male, vehicles[opt]) != 0)
        std::cout << "Sorry. Something went wrong with the rental." << std::endl;
      else
        std::cout << "Your contract has been recorded." << std::endl;
      break;
#pragma endregion

#pragma region Book
    case '2':
      std::cout << "Gotcha. Getting you there right now." << std::endl;
      sleep(1);
      system("clear");

      std::cout << "We will need some information from you. Please fill in the following form." << std::endl;
      std::cin.ignore();

      std::cout << "Your name: ";
      std::getline(std::cin, name);

      std::cout << "Your date of birth: ";
      std::getline(std::cin, dob);

      std::cout << "Your social ID: ";
      std::getline(std::cin, socialID);

      std::cout << "Your license ID: ";
      std::getline(std::cin, licenseID);

      std::cout << "We are almost finished. Now we just want to know if you are male or female" << std::endl
                << "(1/0), defaults to male: ";
      std::getline(std::cin, foo);
      male = foo.compare(std::to_string(1)) == 0 ? true : false;

      system("clear");
      std::cout << "Well done. Choose a vehicle and we are ready to go." << std::endl;
      for (int i = 0; i < vehicles.size(); i += 1)
      {
        if (vehicles[i]->isAvailable())
          std::cout << "[" << i << "] "
                    << vehicles[i]->getYear() << " "
                    << vehicles[i]->getBrand() << " "
                    << vehicles[i]->getModel() << " "
                    << vehicles[i]->getType() << ", "
                    << vehicles[i]->getMileage() << " miles" << std::endl;
      }
      std::cout << "Your choice? ";
      std::getline(std::cin, foo);
      opt = stoi(foo);

      system("clear");
      if (BnR->newBook(name, socialID, licenseID, dob, male, vehicles[opt]) != 0)
        std::cout << "Sorry. Something went wrong with the booking." << std::endl;
      else
        std::cout << "Your contract has been recorded." << std::endl;
      break;
#pragma endregion

#pragma region List
    case '3':
      std::cout << "Gotcha. Getting you there right now." << std::endl;
      sleep(1);
      system("clear");

      for (int i = 0; i < vehicles.size(); i += 1)
        std::cout << "[" << i << "] "
                  << vehicles[i]->getYear() << " "
                  << vehicles[i]->getBrand() << " "
                  << vehicles[i]->getModel() << " "
                  << vehicles[i]->getType() << ", "
                  << vehicles[i]->getMileage() << " miles, "
                  << (vehicles[i]->isAvailable() ? "Available now" : "Is currently busy")
                  << std::endl;
      std::cout << "############" << std::endl;
      getchar();
      break;
#pragma endregion

#pragma region Add Mileage
    case '4':
      std::cout << "Gotcha. Getting you there right now." << std::endl;
      sleep(1);
      system("clear");

      for (int i = 0; i < vehicles.size(); i += 1)
        std::cout << "[" << i << "] "
                  << vehicles[i]->getYear() << " "
                  << vehicles[i]->getBrand() << " "
                  << vehicles[i]->getModel() << " "
                  << vehicles[i]->getType() << " "
                  << vehicles[i]->getMileage() << std::endl;
      std::cout << "############" << std::endl;
      getchar();
      break;
#pragma endregion

    default:
      std::cout << "Sorry but we don't serve that kind. Pick something more reasonable." << std::endl;
      sleep(1);
      system("clear");
      break;
    }
  }

  delete BnR;

  return 0;
}
