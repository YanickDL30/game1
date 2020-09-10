
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"
#include <stdio.h> 
#include <stdlib.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// main function, run after console reset
void main(void) {
  int lives = 3;  //lives counter
  int i;	  //loop counter
  int score = 0;  //score counter
  char str[] =""; //score to char string 

  // set palette colors
  pal_col(0,0x16);	// set screen to red
  //pal_col(1,0x14);	// fuchsia
  //pal_col(2,0x20);	// grey
  pal_col(3,0x30);	// white
  
  // write text to name table
  vram_adr(NTADR_A(2,2));		// set address
  vram_write("      CUP GUESSING GAME!", 24);// write bytes to video RAM
 
  vram_adr(NTADR_A(2,6));
  vram_write("Please choose a cup: ",20);
  
  vram_adr(NTADR_A(2,10));
  vram_write("\x1f Cup 1",7);
  
  vram_adr(NTADR_A(2,12));
  vram_write("\x1f Cup 2",7);
  
  vram_adr(NTADR_A(2,14));
  vram_write("\x1f Cup 3",7);
  
  vram_adr(NTADR_A(2,22));
  vram_write("Lives remaining: ",17);
  for(i=0; i<lives; i++)
  {
  	vram_fill(0x15, 1);	
  }
  vram_adr(NTADR_A(2,24));
  vram_write("Score: ",8);
  
  sprintf(str, "%d", score);  //int score to char []
  vram_write(str,3); //keeps score up to 3 digits if not overflow
  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1) ;
}
