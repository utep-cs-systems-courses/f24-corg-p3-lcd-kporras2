#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <math.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "images.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >>1;
}

void buzzer_off(){
  buzzer_set_period(0);
}

void playCop(int *notes, int *tempo, int totalNotes){
  int state = switch_state;
  for(int i =0; i < totalNotes; i++){
    buzzer_set_period(notes[i]);
    int durration = tempo[i] *10000;
    
    while(durration--){
      switch_interrupt_handler();
      if(state != switch_state){
	      goto update;
      }
    }
  }
  goto done;
  
  update:
    update_image();

  done:
    buzzer_set_period(0);
}

void playSong(int *notes, int*tempo, int totalNotes){
  int state = switch_state;
  for(int i = 0; i < totalNotes; i++){
    switch_interrupt_handler();
    if(state != switch_state){
      goto done;
    }
    buzzer_set_period(notes[i]);
    int durration = tempo[i] * 10000;
    int j = 500;
    while(durration--){
      switch_interrupt_handler();
      if(state != switch_state){
	      goto update;
      }
      if(durration % 100 == 0){
        while(j--){
	
        }
      }
    }
 }
  goto done;

  update:
    update_image();

  done:
    buzzer_set_period(0);
}

void marry_had_a_little_lamb() {
    // Note frequencies and duration
  int notes[] = {700, 800, 900, 800, 700, 690, 680, 800, 810, 820, 700, 600, 599};
  int note_durations[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2};
  // Iterate through the notes and play them
  int total_notes = sizeof(notes) / sizeof(notes[0]);
  playSong(notes, note_durations, total_notes);
}

void twinkle_twinkle_little_star() {
  int notes[] = {900, 910, 600, 599, 530, 529, 600, 665, 664,701, 700, 800, 801, 900};
  int note_durations[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,1, 1, 2};
  int total_notes = sizeof(notes) / sizeof(notes[0]);
  playSong(notes, note_durations, total_notes);
}

void cop(){
  int notes[] = {1000, 800, 1000, 800, 1000, 800, 1000, 800, 1000, 800, 1000, 800, 1000, 800};
  int note_durations[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int total_notes = sizeof(notes) / sizeof(notes[0]);
  playCop(notes, note_durations, total_notes);
}

