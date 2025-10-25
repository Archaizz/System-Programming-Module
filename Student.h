#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "MyLib.h"
class Student {

    string firstName;
    string lastName;
    int numberHomework;
    vector<int>grade;
    int exam;
    double finalResult;
    double medianResult;
public:
    Student();
    Student(string A, string B, int F, vector<int>C, int D);
    Student(const Student& studentObj);
    Student& operator= (const Student& studentObj);

    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName() const { return lastName; }

    void static randomStudentGenerator(std::vector<Student>& students);
    void static randomPartiallyStudentGenerator(std::vector<Student>& students);
    void randomExamGenerator();
    void res();
    void med();
    ~Student();                                              //deconstrucor
    void output();
    friend void manualInput(std::vector<Student>& students);
    friend void generateRandomStudentInfo(std::vector<Student>& students);
    friend void readFromFile(std::vector<Student>& students);
    friend void generateRandomFile();
    friend std::ostream& operator<<(std::ostream& out, const Student& studentObj);                   //friending outside functions of cin cout overloaded operators
    friend std::istream& operator>>(std::istream& in, Student& studentObj);

};


#endif // STUDENT_H_INCLUDED
