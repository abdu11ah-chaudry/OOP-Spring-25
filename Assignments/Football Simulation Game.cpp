#include<iostream>
#include<string>
#include<tuple>
using namespace std;

class Ball{
private:
    int x;
    int y;
public:
    Ball(){
        x=0;
        y=0;
    }    

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void move(int dx, int dy){
        x+=dx;
        y+=dy;
    }

    tuple<int,int> getPosition(){
        return make_tuple(x,y);
    }

};

class Robot{
private:
    string name;
    int numOfHits;

public:
    Robot(){
        name="";
        numOfHits=0;
    }

    Robot(string n){
        name=n;
        numOfHits=0;
    }

    void hitBall(int &ballX, int &ballY, const string &direction){

        if(direction=="up"){
            ballY++;
        }
        else if(direction=="down"){
            ballY--;
        }
        else if(direction=="left"){
            ballX--;
        }
        else if(direction=="right"){
            ballX++;
        }
        numOfHits++;
    }

    int getHits(){
        return numOfHits;
    }
    
};

class Team{
private:
    string name;
    Robot *r;
public:
    Team(){}

    Team(string n, Robot *r1){
        name=n;
        r=r1;
    }

    Robot* getRobot(){
        return r;
    }

    string getTeamName(){
        return name;
    }

};

class Goal{
private:
    int x;
    int y;
public:   
    
    Goal(){
        x=3;
        y=3;
    }

    int isGoalReached(int ballX, int ballY){
        if(ballX==x && ballY==y){
            return 1;
        }
        else{
            return 0;
        }
    }

};

class Game{
private:
    Team *team1;
    Team *team2;
    Ball ball;
    Goal goal;    
public:
    Game(Team *t1, Team *t2){
        team1=t1;
        team2=t2;
    }

    void play(Team *team){
        Robot *robot=team->getRobot();
        cout<<"---------------------------------------------"<<endl;
        cout<<"Team "<<team->getTeamName()<<" will play now: "<<endl;

        while(!goal.isGoalReached(ball.getX(),ball.getY())){
            string direction;
            cout<<"Enter the direction you want to hit the ball(up,down,right,left): "<<endl;
            cin>>direction;
            if(direction=="up" || direction=="down" || direction=="right" || direction=="left"){
            }
            else{
                cout<<"Invalid Direction. kindly rewrite the direction: "<<endl;
                continue;
            }
            int ballX=ball.getX();
            int ballY=ball.getY();
            robot->hitBall(ballX,ballY,direction);
            ball.move(ballX-ball.getX(),ballY-ball.getY());
            cout<<"Current Ball Position: ("<<ball.getX()<<","<<ball.getY()<<")."<<endl;
        }
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Team "<<team->getTeamName()<<" Has scored goal in "<<robot->getHits()<<" hits !!"<<endl;
        ball= Ball();
    }

    void declareWinner(){
        int hits_1=team1->getRobot()->getHits();
        int hits_2=team2->getRobot()->getHits();

        cout<<"|---------------------------------------------------------------------------|"<<endl;
        cout<<"After tremondous display from both teams it is the time for Final Result: "<<endl;
        cout<< team1->getTeamName()<<" has scored goal in "<<hits_1<<" hits"<<endl;
        cout<< team2->getTeamName()<<" has scored goal in "<<hits_2<<" hits"<<endl;

        if(hits_1<hits_2){
            cout<<endl<<"Team "<<team1->getTeamName()<<" is the winner of the game"<<endl;
        }else if(hits_1>hits_2){
            cout<<endl<<"Team "<<team2->getTeamName()<<" is the winner of the game"<<endl;
        }else{
            cout<<endl<<"It is a tie!"<<endl;
        }
        cout<<"|----------------------------------------------------------------------------|"<<endl;
    }

    void startGame(){
        play(team1);
        play(team2);
        declareWinner();
    }

};
int main(){

    Robot robot1("Cristiano Ronaldo");
    Robot robot2("Lionel Messi");

    Team team1("Real Madrid", &robot1);
    Team team2("Barcelona", &robot2);

    Game game(&team1, &team2);
    game.startGame();

    return 0;
}
