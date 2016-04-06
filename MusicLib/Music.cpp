#include "Arduino.h"
#include "Music.h"

#define NOTE_C4 261
#define NOTE_D4 293
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A5 440
#define NOTE_B5 493
#define NOTE_C5 523


Music::Music(int pin, int tempo)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _tempo = tempo;
}

void Music::Intro()
{
  tone(_pin,262,250);
  delay(325);
  tone(_pin,196,125);
  delay(162.5);
  tone(_pin,196,125);
  delay(162.5);
  tone(_pin,220,250);
  delay(325);
  tone(_pin,196,250);
  delay(325);
  tone(_pin,0,250);
  delay(325);
  tone(_pin,247,250);
  delay(325);
  tone(_pin,262,250);
  delay(325);
}

void Music::PlayTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(_pin, LOW);
    delayMicroseconds(tone);
  }
}

void Music::PlayNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
//  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  int tones[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A5, NOTE_B5, NOTE_C5 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
       tone(_pin, tones[i], duration);
   //   PlayTone(tones[i], duration);
    }
  }
}

void Music::Rest(int beats){
    delay(beats * _tempo);
    delay(_tempo / 2);
}

void Music::Play(char note, int beats){
    PlayNote(note, beats * _tempo);
    delay(_tempo / 2);
}

