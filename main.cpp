#include "Student.h"

    void manualInput();
    void generateRandomStudentInfo();
    void readFromFile();
    void generateRandomFile();


int main()
{

    int choice;
    Student s;
    vector<Student>students;

    do
    {
        std::cout << "\n=== Student Management Menu ===\n";
        std::cout << "1 - Enter students manually \n";
        std::cout << "2 - Generate some or all random student info\n";
        std::cout << "3 - Read students from file \n";
        std::cout << "4 - Generate random student file\n";
        std::cout << "5 - Sort the current students by last name and first name\n";
        std::cout << "0 - Exit and Output\n";
        std::cout << "Select option: ";
        std::cin >> choice;

        switch (choice){
            case 1:
                manualInput(students);
                break;
            case 2:
                generateRandomStudentInfo(students);
                break;
            case 3:
                readFromFile(students);
                break;
            case 4:
                generateRandomFile();
                break;
            case 5:
                std::cout<<"student Sorting \n";
                std::sort(students.begin(), students.end(),
                [](const Student& a, const Student& b) {
                if (a.getLastName() == b.getLastName())
                return a.getFirstName() < b.getFirstName();
                return a.getLastName() < b.getLastName();
                });
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

    std::cout << std::left << std::setw(15) << "First Name"<< std::setw(15) << "Last Name"
    << std::right << std::setw(10) << "Final"<<std::right << std::setw(10) << "Median"<< std::endl;
    std::cout << std::string(50, '-') << std::endl;

        for ( auto& s : students)
        s.output();
    return 0;
}
