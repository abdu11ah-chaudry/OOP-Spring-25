#include<iostream>
using namespace std;

class Level{
private:
    string name;
    string difficulty; 
public:
    Level(){}

    Level(string n,string d):name(n),difficulty(d){}
    
    void displayLevel(){
        cout<<"Level name: "<<name<<endl;
        cout<<"Level Difficulty: "<<difficulty<<endl;
    }
};

class VideoGame{
private:
    string title;
    string genre;
    Level levels[5];
    int nooflevels;
public:
    VideoGame(){}
    
    VideoGame(string t, string g):title(t),genre(g),nooflevels(0){}

    void addLevels(string n,string d){
        levels[nooflevels++]=Level(n,d);
    }

    void displayVideogame(){
        cout<<"--------------------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"Levels: "<<endl;
        for(int i=0; i<nooflevels; i++){
            levels[i].displayLevel();
        }
    }
};
int main(){

    VideoGame g("FC football","Sports");

    g.addLevels("Beginner","Easy");
    g.addLevels("Amatuer","Medium");
    g.addLevels("World Class","Hard");

    g.displayVideogame();
    return 0;
}
