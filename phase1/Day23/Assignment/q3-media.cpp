#include <iostream>
#include <cstring> 
using namespace std;

class Media {
protected:
    char* title;
    char* creator;

public:
    Media(const char* t, const char* c) {
        title = new char[strlen(t) + 1]; 
        strcpy(title, t);  

        creator = new char[strlen(c) + 1];
        strcpy(creator, c);  

        cout << "Media Constructor: Title = " << title << ", Creator = " << creator << endl;
    }

    virtual ~Media() {
        cout << "Media Destructor: Title = " << title << ", Creator = " << creator << endl;
        delete title;  /
        delete creator; 
    }

   
    virtual void play() = 0;
    virtual void pause() = 0;
};


class AudioBook : public Media {
protected:
    char* narrator;
    double* length; 

public:
   
    AudioBook(const char* t, const char* c, const char* n, double l) 
        : Media(t, c) {
        narrator = new char[strlen(n) + 1]; 
        strcpy(narrator, n);  

        length = new double; 
        *length = l; 

        cout << "AudioBook Constructor: Narrator = " << narrator << ", Length = " << *length << " hours" << endl;
    }

    ~AudioBook() {
        cout << "AudioBook Destructor: Narrator = " << narrator << ", Length = " << *length << " hours" << endl;
        delete narrator;  
        delete length;     
    }

   
    void play() override {
        cout << "Playing audiobook: " << title << " by " << narrator << endl;
    }

   
    void pause() override {
        cout << "Pausing audiobook: " << title << endl;
    }
};

int main() {
  
    cout << "Static Object: \n";
    AudioBook staticAudioBook("The Great Adventure", "John Doe", "Jane Smith", 5.2);

  
    staticAudioBook.play(); 
    staticAudioBook.pause(); 

    cout << "\nDynamic Object: \n";
    Media* dynamicMedia = new AudioBook("The Great Journey", "Alice Brown", "Michael Green", 7.4);

    dynamicMedia->play();  
    dynamicMedia->pause(); 

    delete dynamicMedia;

    return 0;
}
