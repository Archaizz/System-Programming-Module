#include "MyLib.h"
#include "Student.h"
#include <chrono>
#include <list>

using namespace std::chrono;

Student::Student()
{
    firstName = "John";
    lastName = "Doe";
    /*grade = {1,2,3,4,5,6,7,7,9,6,7,5};
    exam = 10;
    res();*/
    numberHomework = 10;


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


    Student::Student(string A, string B, int F, std::vector<int>C, int D)
    {
        firstName = A;
        lastName = B;
        numberHomework = F;                                                        //intended constructor
        grade = C;
        exam = D;

        res();
        med();


    };
    Student::Student(const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;                     //copy constructor
        numberHomework = studentObj.numberHomework;
        grade = studentObj.grade;
        exam = studentObj.exam;

        res();
        med();
    };
    Student& Student::operator= (const Student& studentObj)
    {
        firstName = studentObj.firstName;
        lastName = studentObj.lastName;
        numberHomework = studentObj.numberHomework;
        grade = studentObj.grade;                           //assignment operator
        exam = studentObj.exam;

        res();
        med();
        return *this;
    };
    void   Student::randomStudentGenerator(std::vector<Student>& studentsVector)
    {

        int count;
        Student s;
        std::cout<<"How many students to generate?\n";
        std::cin>>count;

        std::random_device rd;                          //Random number generation std based on computer hardware inbetween 1-10
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);
        for (int i = 0; i<count; i++)
            {

            s.grade.clear();
            s.firstName = "Student" + std::to_string(i + 1);
            s.lastName = "Random";

            int a = distr(gen);                             // random grade number generation
            for (int i = 0; i < a; ++i)                     //random grade generation
                {
                s.grade.push_back(distr(gen));
                }
            s.randomExamGenerator();
            studentsVector.push_back(s);
            }
    }
    void   Student::randomPartiallyStudentGenerator(std::vector<Student>& studentsVector)
    {
        Student s;
        s.grade.clear();
        std::random_device rd;                          //Random number generation std based on computer hardware inbetween 1-10
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);

        int count;
        std::cout<<"Input the number of students to add\n";
        std::cin>>count;
        for(int i = 0; i< count; i++)
            {
            std::cout<<"Input name manually (1) or random (2)\n";
            int choice;
            choice=0;
            std::cin>>choice;
            if (choice==1)
                {
                std::cout<<"Input first name: \n";
                std::cin>>s.firstName;
                std::cout<<"Input last name: \n";
                std::cin>>s.lastName;
                }
            else
                {
                s.firstName = "Student" + std::to_string(i+1);
                s.lastName = "Random";
                }
            std::cout<<"Generate grades manually (1) or randomly(2)? \n";
            choice=0;
            std::cin>>choice;
            if (choice==1)
                {
                    std::cout<<"If the number of grades is known (1) if not (2)\n";
                    choice=0;
                    std::cin>>choice;
                    if (choice==1)
                        {
                            std::cout<<"Type in the number of grades\n";
                            int n;
                            std::cin>>n;
                            for(int i = 0; i<n; i++)
                                {
                                    int g;
                                    std::cin>>g;
                                    s.grade.push_back(g);
                                }
                        }
                    else {
                            std::cout<<"Proceed entering grades and type -1 when finished.\n";
                            int g =0;
                            while (g!=-1)
                                {
                                    std::cin>>g;
                                    if (g!=-1)s.grade.push_back(g);

                                }
                        }
                }
            else
                {


                std::cout<<"Generate a certain number of grades randomly (1) or keep the number random as well(2)?\n";
                choice=0;
                std::cin>>choice;
                if(choice==1)
                    {
                        int n;
                        std::cout<<"Enter the number of grades to generate randomly:\n";
                        std::cin>>n;
                        for (int i = 0; i<n; i++)
                            {
                                s.grade.push_back(distr(gen));
                            }
                    }
                else
                        std::cout<<"Generating a random number of grades from 1-10 and random grades...\n";
                        int n = distr(gen);
                        for (int i = 0; i<n; i++)
                            {
                                s.grade.push_back(distr(gen));
                            }
                }

                std::cout<<"Would you like to input exam grade manually(1) or generate a random grade(2)?\n";
                choice=0;
                std::cin>>choice;
                if (choice==1) std::cin>>s.exam;
                else {
                        s.exam=distr(gen);
                    }
                studentsVector.push_back(s);
                }

            }




    void Student::randomExamGenerator()
    {

        std::random_device rd;                          //Random number generation std based on computer hardware inbetween 1-10
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);
        //grade generation at random
        exam = distr(gen);
    }
    void  Student::res()
    {
        finalResult = (static_cast<double>(accumulate(grade.begin(), grade.end(), 0)) / grade.size()) * 0.4 + exam * 0.6;;  //finalResult calculator if bool average is true
    }
    void  Student::med()
    {
        sort(grade.begin(), grade.end());

        numberHomework = grade.size();
        if (grade.size() % 2 == 0) {

            int num2 = (grade.size() / 2);
            int num1 = (grade.size() / 2) - 1;                                 //if bool average is not true calculates the median based on if its divisible by 2

            medianResult = (grade[num1] + grade[num2]) / 2.0;
        }
        else {

            int num = (grade.size() / 2);
            medianResult = grade[num];
        }
    }

    Student::~Student()                                              //deconstrucor
    {
        firstName.clear();
        lastName.clear();
        grade.clear();
        exam = 0;

        finalResult = 0;
    };

    void  Student::output ()
    {


        std::cout << std::left << std::setw(15) << firstName << std::setw(15) << lastName<< std::right << std::setw(10) << std::fixed << std::setprecision(2) << finalResult
        <<std::right << std::setw(10) << std::fixed << std::setprecision(2) <<medianResult <<std::endl;


    };
    void manualInput(std::vector<Student>& studentsVector)
    {
        Student student;
        cout<<"1"<<endl;

        std::cout << "\n=== Manual Input Menu ===\n";
        std::cout << "- Enter students name and last name \n";
        std::cin>>student.firstName>>student.lastName;
        std::cout << "- Enter number of Homework\n";
        std::cin>>student.numberHomework;
        std::cout << "- Enter grades: \n";
        for (int i=0; i<student.numberHomework; i++)
            {
                int g;
                std::cin>>g;
                student.grade.push_back(g);
            }
        std::cout << "- Enter exam grade:\n";
        std::cin>>student.exam;
        student.res();
        student.med();
    }

    void generateRandomStudentInfo(std::vector<Student>& studentsVector)
    {
        Student student;
        int choice;
        cout<<"2"<<endl;
        do {
        std::cout << "\n=== Student Generation Menu ===\n";
        std::cout << "1 - Enter to generate all information randomly\n";
        std::cout << "2 - Generate some information randomly and some manually \n";
        std::cout << "0 - Back\n";
        std::cout << "Select option: ";

        std::cin >> choice;

        switch (choice){
            case 1:
                Student::randomStudentGenerator(studentsVector);
                break;
            case 2:
                Student::randomPartiallyStudentGenerator(studentsVector);
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }

        }
        while (choice != 0);
    }




    void readFromFile(std::vector<Student>& students)
    {


    std::cout<<"Enter the full path to the student file (e.g. C:\\Users\\Public\\students.txt): \n";
    std::string fileName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::getline(std::cin, fileName);  // get full line (handles spaces)

    if (fileName.empty()) {
    fileName = "kursiokai.txt";
    }


    std::cout<<"Reading students from: " + fileName<<endl;
    string headers;
    std::ifstream file(fileName);

    if (!file)
        {
            std::cerr<<"Error opening the file...\n";
            return;
        }
        //auto start = high_resolution_clock::now();  // start timer
    getline(file, headers);

    while(!file.eof())
        {
            Student s;
            s.grade.clear();

            file>>s.firstName>>s.lastName;
            std::vector<int>allNumbers;
            string line;
            std::getline(file, line);
            std::istringstream iss(line);

            int num;
            while (iss >> num) allNumbers.push_back(num);

            if (allNumbers.empty()) continue;   // skip if no grades

            s.exam = allNumbers.back();        // last number is exam
            allNumbers.pop_back();

            s.grade = allNumbers;               // remaining numbers are grades

            students.push_back(s);
        }
        //auto end = high_resolution_clock::now();    // stop timer
        //auto duration = duration_cast<milliseconds>(end - start);
        //std::cout << "Execution time: " << duration.count() << " ms\n";

    }
    void generateRandomFileMenu()
    {
        Student s;
        int choice;
        std::vector<Student>students;
        int n;

        do {
        std::cout << "\n=== Student File Generation Menu ===\n";
        std::cout << "1 - Enter to generate 1,000 records.\n";
        std::cout << "2 - Enter to generate 10,000 records.\n";
        std::cout << "3 - Enter to generate 100,000 records.\n";
        std::cout << "4 - Enter to generate 1,000,000 records.\n";
        std::cout << "5 - Enter to generate 10,000,000 records.\n";
        std::cout << "0 - Back\n";
        std::cout << "Select option: ";
        std::cin >> choice;
        //auto start = high_resolution_clock::now();  // start timer
        switch (choice){
            case 1:
                n = 1000;
                randomStudentFileGenerator(students, n);
                break;
            case 2:
                 n = 10000;
                randomStudentFileGenerator(students,n);
                break;
            case 3:
                 n = 100000;
                randomStudentFileGenerator(students,n);
                break;
            case 4:
                  n = 1000000;
                randomStudentFileGenerator(students,n);
                break;
            case 5:
                  n = 10000000;
                randomStudentFileGenerator(students,n);
                break;
            case 0:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }
        //auto end = high_resolution_clock::now();    // stop timer
        //auto duration = duration_cast<milliseconds>(end - start);
        //std::cout << "Execution time: " << duration.count() << " ms\n";
        }
        while (choice != 0);
    }
    void randomStudentFileGenerator(std::vector<Student>& students, int n)
    {

        Student s;
        std::random_device rd;                          //Random number generation std based on computer hardware inbetween 1-10
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(1, 10);

        for (int i = 0; i<n; i++)
        {

            s.grade.clear();
            s.firstName = "Student" + std::to_string(i + 1);
            s.lastName = "Random";

            int a = distr(gen);                             // random grade number generation
            for (int i = 0; i < a; ++i)                     //random grade generation
            {
                s.grade.push_back(distr(gen));
            }
            s.randomExamGenerator();
            students.push_back(s);
        }

        std::cout<<"To sort students into seperate files based on performance(1), generate file without sorting(2).\n";
        std::cout<<"e.g. Final grade < 5.0 - weak students, Final grade => 5.0 -strong students\n";
        int choice=0;
        std::cin>>choice;
        auto start = high_resolution_clock::now();  // start timer


        std::vector<Student> weak, strong;

            if (choice == 1)
            {
                std::ofstream fileWeak("weak_students"+std::to_string(n)+".txt");
                std::ofstream fileStrong("strong_students"+std::to_string(n)+".txt");

                for (auto& s : students)
                {
                    if (s.finalResult < 5.0)
                    weak.push_back(s);
                    else strong.push_back(s);
                }
                auto end = high_resolution_clock::now();    // stop timer
                auto duration = duration_cast<milliseconds>(end - start);
                std::cout << "Student Sorting Execution time: " << duration.count() << " ms\n";


                if (!fileWeak.is_open() || !fileStrong.is_open())
                {
                    std::cerr << "Could not open output files.\n";
                    return;
                }

                fileWeak << std::left << std::setw(15) << "First Name"<< std::setw(15) << "Last Name"<< std::right << std::setw(10) << "Final"<<std::right << std::setw(10) << "Median"<< std::endl;
                fileWeak  << std::string(50, '-') << std::endl;
                fileStrong << std::left << std::setw(15) << "First Name"<< std::setw(15) << "Last Name"<< std::right << std::setw(10) << "Final"<<std::right << std::setw(10) << "Median"<< std::endl;
                fileStrong  << std::string(50, '-') << std::endl;
                //auto start = high_resolution_clock::now();  // start timer
                for ( auto& s : weak)
                {
                    fileWeak << std::left << std::setw(15) << s.firstName << std::setw(15) << s.lastName<< std::right << std::setw(10) << std::fixed << std::setprecision(2) << s.finalResult
                    <<std::right << std::setw(10) << std::fixed << std::setprecision(2) <<s.medianResult <<std::endl;
                }
                for ( auto& s : weak)
                {
                        fileStrong << std::left << std::setw(15) << s.firstName << std::setw(15) << s.lastName<< std::right << std::setw(10) << std::fixed << std::setprecision(2) << s.finalResult
                        <<std::right << std::setw(10) << std::fixed << std::setprecision(2) <<s.medianResult <<std::endl;
                }
                //auto end = high_resolution_clock::now();    // stop timer
                //auto duration = duration_cast<milliseconds>(end - start);
                //std::cout << "Creating File Execution time: " << duration.count() << " ms\n";
            }


            else {

                std::ofstream out("students_generated"+std::to_string(n)+".txt");
                if (!out.is_open())
                {
                std::cerr << "Failed to open file for writing!\n";
                return;
                }

                out << std::left << std::setw(15) << "First Name"<< std::setw(15) << "Last Name"<< std::right << std::setw(10) << "Final"<<std::right << std::setw(10) << "Median"<< std::endl;
                out << std::string(50, '-') << std::endl;
                //auto start = high_resolution_clock::now();  // start timer
                for ( auto& s : students)
                {
                    out << std::left << std::setw(15) << s.firstName << std::setw(15) << s.lastName<< std::right << std::setw(10) << std::fixed << std::setprecision(2) << s.finalResult
                    <<std::right << std::setw(10) << std::fixed << std::setprecision(2) <<s.medianResult <<std::endl;
                }
                //auto end = high_resolution_clock::now();    // stop timer
                //auto duration = duration_cast<milliseconds>(end - start);
                //std::cout << "Creating File Execution time: " << duration.count() << " ms\n";
            }

    }


    std::ostream& operator<<(std::ostream& out, const Student& studentObj);
    std::istream& operator>>(std::istream& in, Student& studentObj);


std::ostream& operator<<(std::ostream& out, const Student& studentObj)
{   cout<<"operator output "<<endl;
    out << "First Name: " << studentObj.firstName
        << " | Last Name: " << studentObj.lastName;
                                                                               //overloaded cout operator
        out << "| Exam: " << studentObj.exam
            << " | Final Result: " << std::fixed << std::setprecision(2) << studentObj.finalResult
            << " | Final median Result: " << std::fixed << std::setprecision(2) << studentObj.medianResult
            << endl;


    return out;
};
std::istream& operator>>(std::istream& in, Student& studentObj)
{   cout<<"operator input "<<endl;
    int numGrades;
    cout << "First name || Last name || Number of grades: ";
    in >> studentObj.firstName >> studentObj.lastName >> numGrades;
    studentObj.grade.clear();
        cout << "Enter grades: ";
            for (int i = 0; i < numGrades; ++i)
            {
                int g;
                in >> g;
                studentObj.grade.push_back(g);
            }


                cout << "Enter the exam grade: " << endl;
                in >> studentObj.exam;



        studentObj.res();
        studentObj.med();
    return in;
};
