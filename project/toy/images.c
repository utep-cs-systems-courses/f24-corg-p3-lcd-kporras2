#include <msp430.h>
#include <libTimer.h>
#include <stdlib.h>
#include "images.h"
#include "led.h"
#include "stateMachines.h"
#include "switches.h"
#include "images.h"
#include "lcdtypes.h"
#include "lcddraw.h"
#include "lcdutils.h"

short redrawScreen = 1;

void draw_init(){
  // Clear the screen to set a background color
  clearScreen(COLOR_BLACK);

  // Draw a centered rectangle for the title text
  u_char rectWidth = 60;  // Width of the rectangle
  u_char rectHeight = 20; // Height of the rectangle
  u_char rectCol = (screenWidth - rectWidth) / 2;
  u_char rectRow = (screenHeight - rectHeight) / 4; // Top quarter of the screen

  fillRectangle(rectCol, rectRow, rectWidth, rectHeight, COLOR_BLACK);
  drawRectOutline(rectCol, rectRow, rectWidth, rectHeight, COLOR_WHITE);

  // Draw the title text inside the rectangle (centered)
  char *title = "WELCOME";
  u_char titleLength = 7; // Length of "WELCOME"
  u_char titleStartCol = rectCol + (rectWidth - (titleLength * 6)) / 2;
  u_char titleStartRow = rectRow + (rectHeight - 7) / 2; // Center vertically in rectangle
  drawString5x7(titleStartCol, titleStartRow, title, COLOR_WHITE, COLOR_BLACK);

  // Draw thinner bar below the title rectangle
  u_char barHeight = 5;
  u_char barWidth = 60;
  u_char barCol = (screenWidth - barWidth) / 2;
  u_char barRow = rectRow + rectHeight + 5;
  fillRectangle(barCol, barRow, barWidth, barHeight, COLOR_DARK_GREEN);

  // Draw a two-eighth notes symbol
  u_char noteCol = (screenWidth - 13) / 2;
  u_char noteRow = barRow + barHeight + 45; 
  draw_eighth_notes(noteCol, noteRow, COLOR_DARK_GREEN);

  // Draw centered instruction message at the bottom
  char *message = "Press to Start";
  u_char messageLength = 14; // Length of the string
  u_char fontWidth = 6;      // Width of each character (5 pixels + 1 pixel spacing)
  u_char startCol = (screenWidth - (messageLength * fontWidth)) / 2;

  drawString5x7(startCol, screenHeight - 10, message, COLOR_WHITE, COLOR_BLACK);

}

void draw_eighth_notes(u_char col, u_char row, u_int color) {
  // Draw the first note head (left circle)
  fillRectangle(col, row, 5, 5, color);

  // Draw the first stem (vertical line)
  fillRectangle(col + 4, row - 10, 2, 10, color);

  // Draw the second note head (right circle, slightly offset)
  fillRectangle(col + 8, row + 3, 5, 5, color); // Offset for second head

  // Draw the second stem (vertical line)
  fillRectangle(col + 12, row - 10, 2, 16, color); // Align with second head

  // Draw the connecting bar (horizontal line at the top of the stems)
  fillRectangle(col + 4, row - 10, 10, 2, color);
}
void draw_cloud(u_char startCol, u_char startRow) {
  	fillRectangle(startCol, startRow, 15, 8, COLOR_WHITE);       // Main part of the cloud
  	fillRectangle(startCol + 10, startRow - 3, 10, 8, COLOR_WHITE); // Upper right
  	fillRectangle(startCol - 8, startRow - 3, 10, 8, COLOR_WHITE); // Upper left
	}

void draw_cop_car() {
	// Set the background to light blue (sky)
	clearScreen(COLOR_LIGHT_BLUE);

	// Place clouds in the sky
	draw_cloud(30, 20);  // Cloud 1
	draw_cloud(80, 15);  // Cloud 2
	draw_cloud(130, 25); // Cloud 3
  

  // Car base dimensions
  u_char carWidth = 60;          // Total width of the car
  u_char carHeight = 20;         // Height of the car's main body
  u_char carTopWidth = 35;       // Width of the top section (roof)
  u_char carTopHeight = 10;      // Height of the top section (roof)
  u_char wheelRadius = 10;        // Radius of the wheels
  u_char lightHeight = 3;        // Height of the top lights
  u_char lightWidth = 8;         // Width of each light
  
  u_char carStartCol = (screenWidth - carWidth) / 2;  // Center horizontally
  u_char carStartRow = screenHeight / 2;             // Position near middle of the screen

  // Draw the car body (main rectangle)
  fillRectangle(carStartCol, carStartRow, carWidth, carHeight, COLOR_BLUE);

  // Draw the car roof
  u_char roofStartCol = carStartCol + (carWidth - carTopWidth) / 2;
  u_char roofStartRow = carStartRow - carTopHeight;
  fillRectangle(roofStartCol, roofStartRow, carTopWidth, carTopHeight, COLOR_BLUE);

  // Draw windows on the roof
  u_char windowWidth = 10, windowHeight = 8;
  fillRectangle(roofStartCol + 3, roofStartRow + 1, windowWidth, windowHeight, COLOR_LIGHT_BLUE);
  fillRectangle(roofStartCol + carTopWidth - windowWidth - 3, roofStartRow + 1, windowWidth, windowHeight, COLOR_LIGHT_BLUE);

  // Draw the wheels (two filled circles with rims)
  u_char wheel1Col = carStartCol + 5;  // Left wheel
  u_char wheel2Col = carStartCol + carWidth - 15;  // Right wheel
  u_char wheelRow = carStartRow + carHeight;       // Below the car body

  // Draw outer black wheels
  fillRectangle(wheel1Col, wheelRow, wheelRadius, wheelRadius, COLOR_BLACK);
  fillRectangle(wheel2Col, wheelRow, wheelRadius, wheelRadius, COLOR_BLACK);
  // Draw inner white rims
  fillRectangle(wheel1Col + 2, wheelRow + 2, wheelRadius - 5, wheelRadius - 5, COLOR_WHITE);
  fillRectangle(wheel2Col + 2, wheelRow + 2, wheelRadius - 5, wheelRadius - 5, COLOR_WHITE);

  // Draw headlights and tail lights
  fillRectangle(carStartCol - 3, carStartRow + 3, 3, 7, COLOR_RED);
  fillRectangle(carStartCol + carWidth -2, carStartRow + 3, 3, 7, COLOR_YELLOW); 
  //fillRectangle(carStartCol - 3, carStartRow + carHeight - 8, 3, 5, COLOR_RED);
  //fillRectangle(carStartCol + carWidth, carStartRow + carHeight - 8, 3, 5, COLOR_RED); // Right tail light

  // Draw the top lights (alternating red and blue for a flashing effect)
  u_char lightRow = roofStartRow - lightHeight; // Above the roof
  u_char redLightCol = roofStartCol + 5;        // Red light
  u_char blueLightCol = roofStartCol + carTopWidth - 10; // Blue light

  fillRectangle(redLightCol, lightRow, lightWidth, lightHeight, COLOR_RED);
  fillRectangle(blueLightCol, lightRow, lightWidth, lightHeight, COLOR_BLUE);

  // Add text "POLICE" to the side of the car
  char *label = "POLICE";
  u_char textStartCol = carStartCol + 10; // Offset from the left side of the car
  u_char textStartRow = carStartRow + 5; // Centered vertically on the car body
  drawString5x7(textStartCol, textStartRow, label, COLOR_WHITE, COLOR_BLUE);
  


  // Drawing road and yellow lines
  u_char roadHeight = 20;                              // Height of the road
  u_char roadStartRow = carStartRow + carHeight + 10;  // Start just below the car

  fillRectangle(0, roadStartRow, screenWidth, roadHeight, COLOR_BLACK);

  u_char dashWidth = 10;  // Width of each dash
  u_char dashHeight = 2;  // Height of each dash
  u_char dashSpacing = 15; // Space between dashes


  for (u_char col = 0; col < screenWidth; col += dashWidth + dashSpacing) {
  	fillRectangle(col, roadStartRow + roadHeight / 2 - dashHeight / 2, dashWidth, dashHeight, COLOR_YELLOW);
  }

  // Draw grass below the road
	u_char grassHeight = 40;                             // Height of the grass
	u_char grassStartRow = roadStartRow + roadHeight;    // Starts just below the road
	fillRectangle(0, grassStartRow, screenWidth, grassHeight, COLOR_GREEN);
}


void draw_lamb() {
  // Clear the screen with a light blue background
  clearScreen(COLOR_LIGHT_BLUE);

  // Draw the sun
  draw_sun(10, 10);

  // Draw some clouds
  draw_cloud(20, 20);  // Cloud 1
  draw_cloud(55, 15);  // Cloud 2
  draw_cloud(95, 25);  // Cloud 3

  // Define positions and sizes
  u_char grassStartRow = 100;
  u_char headCol = 70, headRow = 50, headWidth = 20, headHeight = 20;
  u_char eyeSize = 3, leftEyeCol = headCol + 3, eyeRow = headRow + 5, rightEyeCol = headCol + 13;
  u_char earSize = 4, leftEarCol = headCol, earRow = headRow - 5, rightEarCol = headCol + 15;
  u_char noseWidth = 5, noseHeight = 2, noseCol = headCol + 8, noseRow = headRow + 10;
  u_char bodyCol = 45, bodyRow = 70, bodyWidth = 40, bodyHeight = 30;
  u_char fluffWidth = 10, fluffHeight = 5, fluffOffset = 5;
  u_char footWidth = 7, footHeight = 5, leftFootCol = bodyCol, footRow = bodyRow + bodyHeight - 1;
  u_char rightFootCol = bodyCol + bodyWidth - footWidth, tailCol = bodyCol, tailRow = bodyRow;
  u_char beigeCutWidth = 30, beigeCutHeight = 6, beigeCutCol = bodyCol + 5, beigeCutRow = bodyRow + bodyHeight - 6;

  // Draw grass on the bottom
  fillRectangle(0, grassStartRow, screenWidth, screenHeight - grassStartRow, COLOR_GREEN);

  // Draw flowers on the grass
  draw_flower(20, grassStartRow + 5);
  draw_flower(50, grassStartRow + 10);
  draw_flower(80, grassStartRow + 8);
  draw_flower(110, grassStartRow + 7);

  // Draw the lamb's head
  fillRectangle(headCol, headRow, headWidth, headHeight, COLOR_WHITE);

  // Add blush on the lamb's cheeks
  fillRectangle(leftEyeCol - 5, eyeRow + 5, 4, 2, COLOR_PINK);  // Left blush
  fillRectangle(rightEyeCol + 5, eyeRow + 5, 4, 2, COLOR_PINK); // Right blush

  // Draw the lamb's eyes
  fillRectangle(leftEyeCol, eyeRow, eyeSize, eyeSize, COLOR_BLACK);   // Left eye
  fillRectangle(rightEyeCol, eyeRow, eyeSize, eyeSize, COLOR_BLACK);  // Right eye

  // Draw the lamb's ears
  fillRectangle(leftEarCol, earRow, earSize, earSize, COLOR_WHITE);   // Left ear
  fillRectangle(rightEarCol, earRow, earSize, earSize, COLOR_WHITE);  // Right ear
  drawRectOutline(leftEarCol, earRow, earSize, earSize, COLOR_BLACK);
  drawRectOutline(rightEarCol, earRow, earSize, earSize, COLOR_BLACK);

  // Draw the lamb's nose
  fillRectangle(noseCol, noseRow, noseWidth, noseHeight, COLOR_BLACK); // Horizontal bar
  fillRectangle(noseCol + 1, noseRow, noseHeight, noseWidth, COLOR_BLACK); // Vertical bar

  // Draw the lamb's body
  fillRectangle(bodyCol, bodyRow, bodyWidth, bodyHeight, COLOR_WHITE);

  // Add extra fluff layers for detail


  draw_fluff(bodyCol - 2, bodyRow + 7, 10, 5);
  draw_fluff(bodyCol - 4, bodyRow + 10, 10, 5); // Left-side extra fluff
  draw_fluff(bodyCol - 3, bodyRow + 15, 10, 5);
  draw_fluff(bodyCol - 2, bodyRow + 20, 10, 5);

  draw_fluff(bodyCol + 6, bodyRow - 1, 10, 5); // Top-side extra fluff
  draw_fluff(bodyCol + 10, bodyRow - 2, 10, 5);
  draw_fluff(bodyCol + 15, bodyRow - 3, 10, 5);

  draw_fluff(bodyCol + bodyWidth - 5, bodyRow , 10, 5);    // Right-side extra fluff
  draw_fluff(bodyCol + bodyWidth - 7, bodyRow + 5, 10, 5);
  draw_fluff(bodyCol + bodyWidth - 8, bodyRow + 10, 10, 5); 
  draw_fluff(bodyCol + bodyWidth - 9, bodyRow + 15, 10, 5);

  // Cut the bottom of the lamb for a rounded effect
  fillRectangle(beigeCutCol, beigeCutRow, beigeCutWidth, beigeCutHeight, COLOR_LIGHT_BLUE);

  // Draw the lamb's feet
  fillRectangle(leftFootCol, footRow, footWidth, footHeight, COLOR_BLACK);   // Left foot
  fillRectangle(rightFootCol, footRow, footWidth, footHeight, COLOR_BLACK); // Right foot

  // Draw the lamb's tail
  fillRectangle(tailCol, tailRow, fluffHeight, fluffHeight, COLOR_BLACK);
}

// Draw the sun
void draw_sun(u_char col, u_char row) {
  fillRectangle(col, row, 15, 15, COLOR_YELLOW); // Sun
}

// Draw a flower
void draw_flower(u_char col, u_char row) {
  fillRectangle(col, row, 2, 2, COLOR_RED);  // Petal
  fillRectangle(col + 2, row + 2, 2, 2, COLOR_RED); // Petal
  fillRectangle(col + 1, row + 1, 2, 2, COLOR_YELLOW); // Center
}

// Add extra fluff
void draw_fluff(u_char col, u_char row, u_char width, u_char height) {
  fillRectangle(col, row, width, height, COLOR_WHITE);
}


void draw_star() {
  // Clear the screen with a dark blue background (night sky)
  clearScreen(COLOR_NAVY);

  // Draw the main large star
  draw_large_star(screenWidth / 2, screenHeight / 2, 20, COLOR_YELLOW);

  // Scatter smaller stars around the screen
  for (u_char i = 0; i < 20; i++) {
    draw_small_star(rand() % screenWidth, rand() % (screenHeight / 2), COLOR_WHITE); // Random stars in the upper half
  }

  // Add a shooting star
  draw_shooting_star(100, 120, 50, COLOR_WHITE); // Start col, row, and length
}

// Function to draw a large five-point star
void draw_large_star(u_char centerX, u_char centerY, u_char size, u_int color) {
  // Draw the star using filled triangles
  for (u_char i = 0; i < size; i++) {
    // Top triangle
    drawPixel(centerX - i, centerY - i * 2, color);
    drawPixel(centerX + i, centerY - i * 2, color);

    // Bottom triangle
    drawPixel(centerX - i, centerY + i * 2, color);
    drawPixel(centerX + i, centerY + i * 2, color);

    // Left triangle
    drawPixel(centerX - i * 2, centerY - i, color);
    drawPixel(centerX - i * 2, centerY + i, color);

    // Right triangle
    drawPixel(centerX + i * 2, centerY - i, color);
    drawPixel(centerX + i * 2, centerY + i, color);
  }
}

// Function to draw a small star
void draw_small_star(u_char col, u_char row, u_int color) {
  fillRectangle(col, row, 2, 2, color); // Tiny square stars
}

// Function to draw a shooting star with a smooth trail
void draw_shooting_star(u_char col, u_char row, u_char length, u_int color) {
  // Draw the head of the shooting star
  fillRectangle(col, row, 5, 5, color);

  // Draw the trail
  for (u_char i = 0; i < length; i++) {
    drawPixel(col - i, row + i / 2, color); // Smoother diagonal trail
    drawPixel(col - i, row + i / 2 + 1, COLOR_GRAY); // Fading effect
  }
}

void draw_stop(){
  // Clear the screen with a white background
  clearScreen(COLOR_BLACK);
  // Define the stop sign dimensions
  u_char signCenterCol = screenWidth / 2;// Center column
  u_char signCenterRow = screenHeight / 2; // Center row
  u_char signSize = 60;// Approximate size of the stop sign

  // Draw a red octagon (approximation using a filled rectangle)

  fillRectangle(signCenterCol - signSize / 2, signCenterRow - signSize / 2, signSize, signSize, COLOR_RED);
  
  //Bottom bars
  fillRectangle(signCenterCol - 35, signCenterRow-20, 10, 40, COLOR_RED);
  fillRectangle(signCenterCol + 25, signCenterRow-20, 10, 40, COLOR_RED);

  //Top Bars
  fillRectangle(signCenterCol - 19, signCenterRow-34, 40, 10, COLOR_RED);
  fillRectangle(signCenterCol - 19, signCenterRow+25, 40, 10, COLOR_RED);

  // Write "STOP" in the center of the octagon
  char *message = "STOP";
  u_char fontWidth = 11; // Width of each character
  u_char fontHeight = 16; // Height of each character
  u_char textLength = 4; // Length of "STOP"

  // Calculate the starting position for the text to center it
  u_char textStartCol = signCenterCol - (textLength * fontWidth) / 2;
  u_char textStartRow = signCenterRow - fontHeight / 2;
  
  // Draw the text
  drawString11x16(textStartCol, textStartRow, message, COLOR_WHITE, COLOR_RED);
}






void drawChar11x16(u_char rcol, u_char rrow, char c, 
     u_int fgColorBGR, u_int bgColorBGR) 
{
  u_char col = 0;
  u_char row = 0;
  unsigned short rowBits;
  unsigned short colMask;
  u_char oc = c - 0x20; // Offset to map ASCII to font array index

  lcd_setArea(rcol, rrow, rcol + 10, rrow + 15); /* Define drawing area for 11x16 font */
  
  while (row < 16) { /* Process 16 rows */
    rowBits = (1 << row); /* Process bits from LSB to MSB (top to bottom) */
    while (col < 11) { /* Process 11 columns per row */
      colMask = font_11x16[oc][col];
      u_int colorBGR = (colMask & rowBits) ? fgColorBGR : bgColorBGR; /* Check bitmask */
      lcd_writeColor(colorBGR);
      col++;
    }
    col = 0; // Reset column for the next row
    row++;
  }
}



void drawString11x16(u_char col, u_char row, char *string,
    u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while (*string) {
    drawChar11x16(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 12;
  }
}

void update_image(){
	switch(switch_state){
		case 1:
			draw_cop_car();
			break;

		case 2:
			draw_lamb();
			break;

		case 3:
			draw_star();
			break;

		case 4:
			draw_stop();
			break;

		default:
			draw_init();
			break;
	}
}
