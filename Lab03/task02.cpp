#include<iostream>
using namespace std;
class FitnessTracker{
    private:
        string userName;
        int dailyStepsGoal;
        int stepTaken;
        float caloriesBurned;

    public:
        FitnessTracker(){
            dailyStepsGoal=10000;
        }
        FitnessTracker(string n,int s){
            userName=n;
            stepTaken=s;
        }
        string progress[10];
        int i=0;
        void steps(int s){
            stepTaken+=s;
            progress[i++]="you have taken "+to_string(s)+" steps";
        }
        void Coloriesburned(){
            caloriesBurned=(float)stepTaken*0.04;
            cout<<"Total calories burned: "<<caloriesBurned<<endl;
        }
        string wetherGoalAchieved(){
            if(stepTaken>=dailyStepsGoal){
                return "your daily step goal has been achieved\n";
            }
            else{
                return "your daily step goal has not been achieved\n";
            }
        }

        void Progress(){
            for(int j=0;j<i;j++){
                cout<<progress[j]<<endl;
            }
        }

        int getstepTakken(){
            return stepTaken;
        }

};

int main()
{
    FitnessTracker d1("Laiba",100);
    cout<<"Steps taken: "<<d1.getstepTakken()<<endl;
    d1.steps(1000);
    d1.steps(5000);
    d1.steps(3000);
    d1.Progress();
    cout<<d1.wetherGoalAchieved();
    d1.Coloriesburned();
    
    return 0;
}
