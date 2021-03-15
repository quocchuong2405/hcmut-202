/*
 * OOP W1 Lab 1 C++

 * Prepared by Dr Han Duy Phan.

 * Requirements:
 * Implement a simple C++ student management program. For this week you only need to keep the information of each student's name.
 * (1) Use C++ array data structure to store the list of all students' names.
 * (2) Implement a function that allows users to add a new student to the list of all students.
 * (3) Implement a function to display the list of all students.
 * (4) Bonus: Implement a function to remove a student from the list of all students based on the name input from user. If the student name does not exist in the current list of all students, inform the user about that.
 * (5) Bonus: Use C++ WHILE loop to create a text-based menu that allows users to choose the above functionalities or to exit the program.

 * Submission:
 * Create a zip file of all your .cpp and .h project files.
 * Make sure to name your zip file using the following format
 * [StudentID]_[StudentFullName]_[ClassName]_Lab1.zip
 * Submit your zip file before the deadline using the corresponding link on Moodle for your class (each class has a different deadline).

 * Marking criteria:
 * Each lab is worth 3% of total mark.
 * No attempt 0 mark, serious attempt 1 mark, working attempt 2 marks, good attempt 3 marks.

 * Resources:
 * (1) Weekly slides
 * (2) C++ How to Program, 9th Edition, Paul Deitel
 * (3) Object-Oriented Programming in C++, 4th Edition, Robert Lafore
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IStudentMgmt
{
protected:
  std::vector<std::string> studentNames; // Task 1 done

public:
  virtual void addStudent(std::string) = 0;    // Task 2 done
  virtual void removeStudent(std::string) = 0; // Task 3 done
  virtual void exportStudent() = 0;            // Task 4 done
}; // end class IStudentMgmt

class StudentMgmt : public IStudentMgmt
{
public:
  void addStudent(std::string name)
  {
    studentNames.push_back(name);
    return;
  }

  void exportStudent()
  {
    for (std::string name : studentNames)
      std::cout << name << std::endl;
    return;
  }

  void removeStudent(std::string name)
  {
    if (studentNames.size() == 0)
      return;

    int initSize = studentNames.size();

    studentNames.erase(std::remove(studentNames.begin(), studentNames.end(), name), studentNames.end());

    if (initSize == studentNames.size())
      std::cout << "Sorry, this dude does not exist." << std::endl;
    else
      std::cout << "Done." << std::endl;
  }
}; // end class StudentMgmt
