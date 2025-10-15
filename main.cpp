#include<iostream>
#include<string>
#include<vector>
#include<numeric>

using namespace std;
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
  grade = {1,2,3,4,5,6,7,8,9,6,7,4};
  exam = 10;
  res();
};;
Student(string A, string B, vector<int>C, int D)
{
  firstName = A;
  lastName = B;
  grade = C;
  exam = D;
  res();
};
void res()
{
  result = accumulate(grade.begin(), grade.end(), 0) / grade.size() * 0.4 + exam *0.6;
}
~Student()
{
  firstName.clear();
  lastName.clear();
  grade.clear();
  exam = 0;
  result = 0;
};
}
int main()
{

  
  return 0;
}
