#include<iostream>
using namespace std;
class MusicPlayer{
    string playlist[100]={"Introduction","Afsaanay","Coldnights","Dark sides","The end"};
    int playlist_count=5;
    string current_song;
    public:
    MusicPlayer(){

        current_song="No song is playing";
    }
    MusicPlayer(string song){
        current_song=song;
    }
    void add_song(string song){
        playlist[playlist_count]=song;
        playlist_count++;
    }
    void remove_song(string song){
        for(int i=0;i<playlist_count;i++){
            if(playlist[i]==song){
                for(int j=i;j<playlist_count;j++){
                    playlist[j]=playlist[j+1];
                }
                playlist_count--;
                break;
            }
        }
    }
    void play_song(string song){
        for(int i=0;i<playlist_count;i++){
            if(playlist[i]==song){
                current_song=song;
                cout<<song<<" is playing"<<endl;
                break;
            }
        }
    }   
    void display_playlist(){
        cout<<"Playlist :"<<endl;
        for(int i=0;i<playlist_count;i++){
            cout<<playlist[i]<<endl;
        }
    }
};
int main(){
    string song;
    cout<<"Enter the song name : ";
    cin>>song;
    MusicPlayer player1(song);
    player1.display_playlist();
    string add_song;
    cout<<"Enter the song name to add in playlist : ";
    cin>>add_song;
    player1.add_song(add_song);
    player1.display_playlist();
    string remove_songs;
    cout<<"Enter the song name to remove from playlist : ";
    cin>>remove_songs;
    player1.remove_song(remove_songs);
    player1.display_playlist();
    player1.play_song("Introduction");
    return 0;
}