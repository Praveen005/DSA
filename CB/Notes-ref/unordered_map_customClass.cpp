#include <iostream>
#include<unordered_map>
using namespace std;
class student{
    public:
    string firstName;
    string lastName;
    string rollNumber;

    //constructor
    student(string fn, string ln, string roll){
        firstName=fn;
        lastName=ln;
        rollNumber=roll;
    }

    //compare between the two current student to the student provided as argument
    /*
        this is required because the hash cannot rely on the fact that 
        the hash function will always provide a unique hash value for every 
        distinct key (i.e., it needs to be able to deal with collisions), 
        so it needs a way to compare two given keys for an exact match.
    */
    /*
        Done Rahul Kumar ka index same hoga, but jab comparison hoga tab, 
        roll number compare karega.
    */
    /*
    Do remember the following syntax for operator overloading inside a class.
    since we are not changing any data member of the class, so make the function a const function
    */
    bool operator==(const student &s)const{
        return rollNumber==s.rollNumber;
    }
};

/*
size_t :

Alias of one of the fundamental unsigned integer types.
It is a type able to represent the size of any object in bytes: size_t is the type returned by the sizeof operator.
it cannot represent any negative values(<0).


*/

class HashFunction{
public:
    size_t operator()(const student &s)const{
        return s.firstName.length() +s.lastName.length();
    }
};
int main() {
    unordered_map<student, int, HashFunction>student_map;

    student s1("Prateek", "Mishra", "01");
    student s2("Rahul", "Kumar", "11");
    student s3("Sanjeev", "Baneerjee", "05");
    student s4("Rahul", "Kumar", "12");
    student s5("Santosh", "Diwedi", "22");
    student s6("Rakesh", "Maria", "31");
    //Add student-marks pair to hashmap
    student_map[s1]= 76;
    student_map[s2]= 55;
    student_map[s3]= 43;
    student_map[s4]= 62;
    student_map[s5]= 65;
    student_map[s6]= 70;

    for(auto s:student_map){
        cout<<s.first.firstName<<" "<<s.first.lastName<<" "<<s.first.rollNumber<<"--> " <<s.second<<endl;
    }

    cout<<"Marks of student 4 :";
    auto it=student_map.find(s4);  //returns the iterator to pair<student, marks>
    cout<<(*it).second<<endl;

    cout<<student_map[s4]<<endl;
}

/*

output:

Rakesh Maria 31--> 70
Rahul Kumar 11--> 55
Rahul Kumar 12--> 62
Prateek Mishra 01--> 76
Santosh Diwedi 22--> 65
Sanjeev Baneerjee 05--> 43
Marks of student 4 :62
62

*/

