#include "iostream"
#include "string"
#include "vector"

using namespace std;


class Calculator {
private:
    int noOfCourses;
    vector <int> creditHour;
    vector <double> grade;

public:
    Calculator(int n, vector <int> ch, vector <double> g) {
        noOfCourses = n;
        creditHour = ch;
        grade = g;
    }

    void display() {
        cout<<endl;
        cout<<"=== DISPLAY RESULT ===\n";
        for(int i = 0; i < noOfCourses; i++) {
            cout<<"Course: " << i + 1 << " -" <<" Credit Hour " <<creditHour[i]<< " | Grade "<<grade[i]<<endl;
        }
        
    }
    void calculateCGPA() {
        double totalQualityPoints = 0.0;
        int totalCreditHour = 0;

        for(int i = 0; i < noOfCourses; i++) {
            totalQualityPoints += grade[i] * creditHour[i];
            totalCreditHour += creditHour[i];

        }
        
        cout<<"CGPA = "<<totalQualityPoints / totalCreditHour;
    }
};


int main() {

int noOfCourses;

cout<<"Enter total number of courses: ";
cin>>noOfCourses;

if(cin.fail()) {
    cout << "Invalid input! Please enter a number." << endl;
    return 0;  // program band
}

vector <double> grade (noOfCourses);
vector <int> creditHour (noOfCourses);

cout<<"Enter grades and credit hours for each of the course"<<endl;

for(int i = 0; i < noOfCourses; i++) {
    cout<<"--- Course: "<< i + 1<<" ---"<<endl;
    cout<<"Credit Hours ";
    cin>>creditHour[i];

    if(cin.fail()) {
    cout << "Invalid input! Please enter a number." << endl;
    return 0;  // program band
    }

    if(creditHour[i] <= 0 || creditHour[i] >= 10) {
        cout<<"Invalid Credit Hour";
        return 0;
    }

    cout<<"Grade ";
    cin>>grade[i];

    if(cin.fail()) {
    cout << "Invalid input! Please enter a number." << endl;
    return 0;  // program band
    }
    
    if(grade[i] <= 0 || grade[i] > 4) {
        cout<<"Invalid Grade Points";
        return 0;
    }

}

Calculator c1(noOfCourses, creditHour, grade);
c1.display();
c1.calculateCGPA();



}