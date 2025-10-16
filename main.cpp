#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<iomanip>


using std::cout;
using std::string;
using std::vector;
using std::accumulate;

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
    grade = {1,2,3,4,5,6,7,7,9,6,7,5};
    exam = 10;
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
    finalResult = accumulate(grade.begin(), grade.end(), 0) / grade.size() * 0.4 + exam *0.6;
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
friend std:: ostream& operator<<(std:: ostream& os ,const Student& studentObj);
friend std:: istream& operator<<(std:: istream& is ,const Student& studentObj);

};
 ostream &operator<<( ostream& out,const Student& studentObj)
{  
        out<<"Name "<<studentObj.firstName<<"Last Name "<<studentObj.lastName <<"Grade "<< studentObj.grade <<"Exam "<< studentObj.exam<<"Final result "<<res()<< endl;
        return *out;
};
 istream &operator>>( istream& in ,const Student& studentObj)
{
        in>>studentObj.firstName>>studentObj.lastName>>studentObj.grade>>studentObj.exam;
        return *in;
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
