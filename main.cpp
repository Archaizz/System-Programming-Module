#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<iomanip>
#include <random>
#include <algorithm>


using std::cout;
using std::string;
using std::vector;
using std::accumulate;
using std::endl;
using std::sort;


class Student{
    public:
    string firstName;
    string lastName;
    int numberHomework;
    vector<int>grade;
    int exam;
    double finalResult;
    int medianResult;
    bool average;                   //bool check to see if they want the median or average
   
    
    Student()
    {
        firstName = "John";
        lastName = "Doe";
        /*grade = {1,2,3,4,5,6,7,7,9,6,7,5};
        exam = 10;
        res();*/
        numberHomework=10;
        average = true;
        
        std::random_device rd;                          //Random number generation std based on computer hardware inbetween 1-10
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);   

        for (int i = 0; i < 10; ++i) {                      //grade generation at random
        grade.push_back(distr(gen));
        }

    exam = distr(gen);                          // random exam grade generation as well
    res(); 
    med();
    };
  
    Student(string A, string B,int F, vector<int>C, int D, bool E)
    {
        firstName = A;
        lastName = B;    
        numberHomework = F;                                                        //intended constructor
        grade = C;
        exam = D;
        average = E;
        res(); 
        med();
        
       
    };
    Student(const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;                     //copy constructor
        numberHomework=studentObj.numberHomework;
        grade = studentObj.grade;
        exam = studentObj.exam;
        average = studentObj.average;
        res(); 
        med();
    };
    Student& operator= (const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;
        numberHomework = studentObj.numberHomework;
        grade = studentObj.grade;                           //assignment operator
        exam = studentObj.exam;
        average = studentObj.average;
       res(); 
        med();
        return *this;
    };

    void res()
    {
        finalResult = (static_cast<double>(accumulate(grade.begin(), grade.end(), 0)) / grade.size()) * 0.4 + exam * 0.6;;  //finalResult calculator if bool average is true
    }
    void med()
    {   
        sort(grade.begin(), grade.end());
        cout<<"median triggered "<<endl;
        numberHomework=grade.size();
        if (grade.size()%2==0){
            
            int num2 =(grade.size()/2) ;  
            int num1 = (grade.size()/2)-1 ;                                 //if bool average is not true calculates the median based on if its divisible by 2
                  cout<<"even grades  "<<grade.size()<<endl;
            medianResult = (grade[num1]+grade[num2])/2;
        }
       else { 
            cout<<"odd grades  "<<grade.size()<<endl;
           int num = (grade.size()/2);
           medianResult = grade[num];}
    }
    ~Student()                                              //deconstrucor
    {
        firstName.clear();                                                  
        lastName.clear();
        grade.clear();
        exam = 0;
        average = true;
        finalResult = 0;
    };
    
    void output()
    {
        if (average)cout<< firstName <<" | "<< lastName <<" | "<< std::setprecision(2) << finalResult << std::endl;         //output depends on bool average
        else cout<< firstName <<" | "<< lastName <<" | "<< std::setprecision(2) << medianResult << std::endl;
  
    };
    friend std::ostream &operator<<(std::ostream& out,const Student& studentObj);                   //friending outside functions of cin cout overloaded operators
    friend std::istream &operator>>(std::istream& in , Student& studentObj);
};

std::ostream &operator<<(std::ostream& out,const Student& studentObj)
{  
    out << "First Name: " << studentObj.firstName
        << " | Last Name: " << studentObj.lastName
        << " | Grades: ";                                                                           //overloaded cout operator

    for (int g : studentObj.grade)
        out << g << " ";
    if (studentObj.average){
    out << "| Exam: " << studentObj.exam
        << " | Final Result: " << std::fixed << std::setprecision(2) << studentObj.finalResult      //output is based on the boolean average
        << endl;}
    else{
        out << "| Exam: " << studentObj.exam
        << " | Final median Result: " << std::fixed << std::setprecision(2) << studentObj.medianResult
        << endl;
    }
    return out;
};
std::istream &operator>>(std::istream& in , Student& studentObj)
{
   cout << "Enter first name, last name, and type 1 to input the number of homework and 0 if number is uncertain"<<endl;                //overloaded cin operator
    bool gradeNum;
    
    int numGrades;
    in >> studentObj.firstName >> studentObj.lastName >> gradeNum;
    
    if (gradeNum){
    cout<<"Enter number of grades, then grades, and exam: "; 
    in>>numGrades;
    studentObj.grade.clear();
    for (int i = 0; i < numGrades; ++i) {
        int g;
        in >> g;
        studentObj.grade.push_back(g);
    }

    in >> studentObj.exam;
    cout<<"To calculate the average type 1, for the median 0: "<<endl;
    in>>studentObj.average;
    studentObj.res();
    studentObj.med();
        
    } // Recalculate final result
    else {
        studentObj.grade.clear();
        cout<<"Enter grades, when finished type -1"; 
        int g;
        while (g !=-1)
        {
             
           
            in >> g;
           if (g!=-1) studentObj.grade.push_back(g);
            
        }
        studentObj.res();
        studentObj.med();
        
        cout<<"Enter exam grade and 1 to calculate the average, 0 for the median: "<<endl;
        in>>studentObj.exam>>studentObj.average;
        
        }
    return in;
    };
    


int main()
{
    /*vector<Student>group;
    
    for (int i = 0 ; i<5; i++)
    {  
    Student student1;               //making copies of student1 
    
    group.push_back(student1);          //some weird push of student1 copies to the back of the 'list' called group?
    }
    for(auto Z: group )Z.output();          //auto output for every member of the group?
    */
   // Student student1;
    //Student student2;
    //Student student3;
    Student student4;
    Student student5;

    //student2=student1;
    //student3=student1;
    student4.firstName = "Alice";
    student4.lastName = "Wonderland";           //testing intended constructor with the output operator change
    student4.grade={5,6,2,8,2,6,9,10,6};
    student4.med();
    student4.exam=4;
    student4.average=false;
    cout<<student4;
    
    std::cin>>student5;
    cout<<student5;
    return 0;
    }
