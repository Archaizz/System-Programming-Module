#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "MyLib.h"
#include <list>
#include <deque>
class Student {

    string firstName;
    string lastName;
    int numberHomework;
     std::vector<int>grade;
    int exam;
    double finalResult;
    double medianResult;
public:
    Student();
    Student(string A, string B, int F, std::vector<int>C, int D);
    Student(const Student& studentObj);
    Student& operator= (const Student& studentObj);

    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName() const { return lastName; }

    void static randomStudentGenerator(std::vector<Student>& studentsVector);
    void static randomPartiallyStudentGenerator(std::vector<Student>& studentsVector);
    void randomExamGenerator();
    void res();
    void med();
    ~Student();                                              //deconstrucor
    void output();
    friend void manualInput(std::vector<Student>& studentsVector);
    friend void generateRandomStudentInfo(std::vector<Student>& studentsVector);
    friend void readFromFile(std::vector<Student>& students);
    friend void generateRandomFileMenu();
    friend void randomStudentFileGenerator(std::vector<Student>& students, int n);
    friend std::ostream& operator<<(std::ostream& out, const Student& studentObj);                   //friending outside functions of cin cout overloaded operators
    friend std::istream& operator>>(std::istream& in, Student& studentObj);

};


#endif // STUDENT_H_INCLUDED
