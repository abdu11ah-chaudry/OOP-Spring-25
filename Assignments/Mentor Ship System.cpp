#include<iostream>
using namespace std;

class Skill{
private:

    int skillId;
    string name;
    string description;
public:

    Skill(){
        skillId=0;
        name="Unknown";
        description="none";
    }

    Skill(int id, string n, string descrip){
        skillId=id;
        name=n;
        description=descrip;
    }

    void displayskill(){
        cout<<"--------------------------"<<endl;
        cout<<"Skill ID: "<<skillId<<endl;
        cout<<"Skill name: "<<name<<endl;
        cout<<"Skill Description: "<<description<<endl;

    }

    void updateDescription(string descrip){
        description=descrip;
    }

    int getSKillID(){
        return skillId;
    }

};

class Sport{
private:

    int sportId;
    string name;
    string description;
    Skill requiredskill[3];
    int numofskills=0;

public:
    Sport(){
        sportId=0;
        name="Unkown";
        description="none";
    }

    Sport(int id, string n, string descrip){
        sportId=id;
        name=n;
        description=descrip;
    }

    void addskill(Skill s){
        if(numofskills<3)
        {
            requiredskill[numofskills++]=s;
        }
        else{
            cout<<"Skills required has reached it maximum limit."<<endl;
        }
    }

    void removeskill(Skill s){
        bool found=false;
        for(int i=0; i<numofskills; i++){
            if(requiredskill[i].getSKillID()==s.getSKillID()){
                found==true;
                for(int j=i; j<numofskills-1; j++){
                    requiredskill[j]=requiredskill[j+1];
                }
                cout<<"Skill removed successfully."<<endl;
                numofskills--;
                break;
            }
        }
        if(!found){
            cout<<"This skill was not found for deletion."<<endl;
        }
    }

    void displaysport(){
        cout<<"--------------------------"<<endl;
        cout<<"Sport ID: "<<sportId<<endl;
        cout<<"Sport name: "<<name<<endl;
        cout<<"Sport Description: "<<description<<endl;

    }

    int getSportId(){
        return sportId;
    }
    

};

class Mentor;


class Student{
private:
    int studentId;
    string name;
    int age;
    Sport sportsInterest[3];
    Mentor *mentorAssigned;
    int numofsports=0;

public:
    
    Student(){
        studentId=0;
        name="Unknown";
        age=0;
        mentorAssigned=nullptr;
    }

    Student(int id, string n, int a){
        studentId=id;
        name=n;
        age=a;
        mentorAssigned=nullptr;
    }

    void updateInterest(Sport s){
        if(numofsports<3){
            sportsInterest[numofsports++]=s;
        }
        else{
            cout<<"Interest Limit has already reached."<<endl;
        }
    }

    void registerForMentor(Mentor &m);

    int getStudentId(){
        return studentId;
    }
    
    void viewMentorDetails();

    void displayStudent(){
        cout<<"--------------------------"<<endl;
        cout<<"Student ID: "<<studentId<<endl;
        cout<<"Student name: "<<name<<endl;
        cout<<"Student Age: "<<age<<endl;
        cout<<"Student's Sports Interests: "<<endl;
        for(int i=0; i<numofsports; i++){
            sportsInterest[i].displaysport();
        }
    }
};

class Mentor{
 
private:
    int mentorId;
    string name;
    int maxLearner;
    Student *assignedLearners;
    Sport sportExpertise[3];
    int numoflearners=0;
    int numofsports=0;
    
public:

    Mentor(){
        mentorId=0;
        name="Unknown";
        maxLearner=3;
        assignedLearners=new Student[maxLearner];
    }

    Mentor(int id, string n, int maxL){
        mentorId=id;
        name=n;
        maxLearner=maxL;
        assignedLearners=new Student[maxL];
    }

    void assignLearner(Student &s){
        if(numoflearners<maxLearner){
            assignedLearners[numoflearners++]=s;
        }
        else{
            cout<<"Maximum number of learners are already registered."<<endl;
        }
    }

    void removeLearner(Student s){
        bool found=false;
        for(int i=0; i<numoflearners; i++){
            if(assignedLearners[i].getStudentId()==s.getStudentId()){
                found=true;
                for(int j=i; j<numoflearners-1; j++){
                    assignedLearners[j]=assignedLearners[j+1];
                }
                cout<<"Learner removed Successfully."<<endl;
                numoflearners--;
                break;
            }
        }
        if(!found){
            cout<<"The learner asked to be removed is not assigned here."<<endl;
        }
    }

    void displayMentor(){
        cout<<"--------------------------"<<endl;
        cout<<"Mentor ID: "<<mentorId<<endl;
        cout<<"Mentor name: "<<name<<endl;
    }

    void viewLearners(){
        cout<<"Learners: "<<endl;
        for(int i=0; i<numoflearners; i++){
            assignedLearners[i].displayStudent();
        }
    }

    void addSportsExpertise(Sport s){
        if(numofsports<3){
            sportExpertise[numofsports++]=s;
        }
        else{
            cout<<"Maximum limit of sports expertise has already been reached."<<endl;
        }
    }

    ~Mentor(){
        delete[] assignedLearners;
    }
};    

void Student::registerForMentor(Mentor &m){
    mentorAssigned=&m;
    m.assignLearner(*this);
}

void Student::viewMentorDetails(){
    if(mentorAssigned){
        mentorAssigned->displayMentor();
    }
    else {
        cout<<"No Mentor is assigned."<<endl;
    }
}


int main(){

    Skill s1(1,"Vision","Abililty to observe the pitch");
    Skill s2(2,"Pace","Run Faster");

    Sport football(10,"Football","A game played with foot and ball");
    
    football.addskill(s1);
    football.addskill(s2);

    cout<<"Football Details: "<<endl;
    football.displaysport();

    Student st1(101,"Ali",17);
    Student st2(102,"Rehman",19);

    st1.updateInterest(football);
    st2.updateInterest(football);

    cout<<"Student Details: "<<endl;
    st1.displayStudent();
    st2.displayStudent();

    Mentor m1(201,"Mentor Asif",3);
    st1.registerForMentor(m1);
    st2.registerForMentor(m1);

    cout<<"Mentor Details: "<<endl;
    m1.displayMentor();
    m1.viewLearners();

    cout<<"Example of Removing Student from Mentor list: "<<endl;
    m1.removeLearner(st2);
    m1.viewLearners();

    return 0;
}
