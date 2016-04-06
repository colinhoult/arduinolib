#ifndef Music_h

#define Music_h
#include "Arduino.h"

class Music
{
   public:
        Music(int pin, int tempo);
        void Intro();
        
        void PlayNote(char note, int duration);
        void PlayTone(int tone, int duration);
        void Rest(int beats);
        void Play(char note, int beats);

    private:  
        int _pin;
        int _tempo;
};

#endif
