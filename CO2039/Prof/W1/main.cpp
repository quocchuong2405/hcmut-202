// g++ -v >> gcc version 10.2.1 20210110 (Debian 10.2.1-6)
// clang -v >> Debian clang version 11.0.1-2

#include "main.hpp"
#include <iostream>

int main(int, char **)
{
  int opt = 0;
  bool working = true;
  std::string input;
  IStudentMgmt *StudentList = new StudentMgmt();

  while (working) // Task 5 done
  {
    std::cout << "Here are your options:" << std::endl
              << "\t1: Add an entry" << std::endl
              << "\t2: Remove all matching entries" << std::endl
              << "\t3: List all entries" << std::endl
              << "\tAnything else: Exit" << std::endl
              << "Your choice? ";
    std::cin >> opt;

    switch (opt)
    {
    case 1:
      std::cout << "Your name, with whitespaces if you're feeling special: ";
      std::cin.ignore();
      std::getline(std::cin, input);

      StudentList->addStudent(input);
      break;

    case 2:
      std::cout << "It seems that you don't need someone." << std::endl
                << "Give me a name and I will erase their existence: ";
      std::cin.ignore();
      std::getline(std::cin, input);

      StudentList->removeStudent(input);
      break;

    case 3:
      StudentList->exportStudent();
      break;

    default:
      std::cout << "I'll see you in the afterlife.";
      working = false;
      break;
    }
  }

  return 0;
}
