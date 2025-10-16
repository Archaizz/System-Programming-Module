#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<iomanip>
#include <random>

using std::cout;
using std::string;
using std::vector;
using std::accumulate;
using std::endl;



class Student{

    string firstName;
    string lastName;
    vector<int>grade;
    int exam;
    double finalResult;
    public:
    
    Student()
    {
        firstName = "John";
        lastName = "Doe";
        /*grade = {1,2,3,4,5,6,7,7,9,6,7,5};
        exam = 10;
        res();*/
         std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);

    for (int i = 0; i < 10; ++i) {
        grade.push_back(distr(gen));
    }

    exam = distr(gen); // random exam grade too
    res();
    };
  
    Student(string A, string B, vector<int>C, int D)
    {
        firstName = A;
        lastName = B;
        grade = C;
        exam = D;
        res();
    };
    Student(const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;
        grade = studentObj.grade;
        exam = studentObj.exam;
        res();
    };
    Student& operator= (const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;
        grade = studentObj.grade;
        exam = studentObj.exam;
        res();
        return *this;
    };

    void res()
    {
        finalResult = (static_cast<double>(accumulate(grade.begin(), grade.end(), 0)) / grade.size()) * 0.4 + exam * 0.6;;
    }
    ~Student()
    {
        firstName.clear();
        lastName.clear();
        grade.clear();
        exam = 0;
        finalResult = 0;
    };
    
    void output()
    {
        cout<< firstName <<" | "<< lastName <<" | "<< std::setprecision(2) << finalResult << std::endl;
  
    };
    friend std::ostream &operator<<(std::ostream& out,const Student& studentObj);
    friend std::istream &operator>>(std::istream& in , Student& studentObj);
};

std::ostream &operator<<(std::ostream& out,const Student& studentObj)
{  
    out << "First Name: " << studentObj.firstName
        << " | Last Name: " << studentObj.lastName
        << " | Grades: ";

    for (int g : studentObj.grade)
        out << g << " ";

    out << "| Exam: " << studentObj.exam
        << " | Final Result: " << std::fixed << std::setprecision(2) << studentObj.finalResult
        << endl;

    return out;
};
std::istream &operator>>(std::istream& in , Student& studentObj)
{
   cout << "Enter first name, last name, number of grades, then grades, and exam: ";

    int numGrades;
    in >> studentObj.firstName >> studentObj.lastName >> numGrades;

    studentObj.grade.clear();
    for (int i = 0; i < numGrades; ++i) {
        int g;
        in >> g;
        studentObj.grade.push_back(g);
    }

    in >> studentObj.exam;
    studentObj.res();  // Recalculate final result

    return in;
};
int main()
{
    vector<Student>group;
    
    for (int i = 0 ; i<5; i++)
    {  
    Student student1;
    
    group.push_back(student1);
    }
    for(auto Z: group )Z.output();
    
    Student student1;
    Student student2;
    Student student3;

    student2=student1;
    student3=student1;
    
    return 0;
}
