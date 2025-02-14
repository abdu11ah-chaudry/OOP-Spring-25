#include<iostream>
using namespace std;

class MusicPlayer{

private:
    string currentPlayingSong;
    string playlist[20];
    int count=0;

public:

    void addSong(string song){
        playlist[count++]=song;
    }

    void removeSong(string song){
        bool found=false;

        for(int i=0; i<count; i++){
            if(playlist[i]==song){
                found=true;
                for(int j=i; j<count-1; j++){
                    playlist[j]=playlist[j+1];
                }
                count--;
                cout<<"The song "<<song<<" has been removed from your playlist"<<endl;
                break;
            }
        }

        if(!found){
            cout<<"The song "<<song<<" is not present in your playlist"<<endl;
        }

    }

    void playSong(string song){
        bool found=false;
        for(int i=0; i<count; i++){
            if(playlist[i]==song){
                found=true;
                currentPlayingSong=song;
                cout<<"Playing song, "<<song<<endl;
                break;
            }
        }

        if(!found){
            cout<<"The song "<<song<<" is not present in the Playlist.";
        }
    }

    void displayPlaylist(){
        cout<<"Songs Playlist: "<<endl;
        for(int i=0; i<count; i++){
            cout<<i+1<<". "<<playlist[i]<<endl;
        }
    }


};
int main(){

    MusicPlayer m1;
    m1.addSong("Love In The Dark");
    m1.addSong("Atlantis");
    m1.addSong("There is a light that never goes out");
    m1.addSong("Hello");
    m1.addSong("Coastline");
    m1.displayPlaylist();
    m1.removeSong("Coastline");
    m1.displayPlaylist();
    m1.playSong("Atlantis");

    return 0;
}
