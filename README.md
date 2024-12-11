# arch1-project3-lcd

This project demonstrates the use of an LCD screen and a buzzer with an MSP430 microcontroller. It creates an interactive experience with different visual and audio outputs triggered by button presses.

## Features

* **Interactive LCD Display:** Displays different images based on button input.
* **Sound Effects:** Plays corresponding sounds for each image displayed on the LCD.
* **Button Control:** Four buttons (SW1-SW4) control the image and sound output.

## Functionality

When the MSP430 starts up, it displays a start screen and plays a continuous beep.  Here's how the buttons function:

* **SW1 (Cop Car):** Displays a cop car animation and plays a police siren sound.
* **SW2 (Mary Had a Little Lamb):** Displays an image related to the nursery rhyme "Mary Had a Little Lamb" and plays the tune. 
* **SW3 (Twinkle Twinkle Little Star):** Displays an image related to the nursery rhyme "Twinkle Twinkle Little Star" and plays the tune.
* **SW4 (Stop):** Displays a stop image and disables all sound from the buzzer.

## Running the Project

This project requires a development kit (dev kit) for the MSP430 microcontroller and the ability to run the `make` command in a BASH terminal.

**Steps:**

1. **Prerequisites:** Ensure you have a development kit and the ability to run `make` in a BASH terminal.

2. **Build:**
   - Open a BASH terminal and navigate to the project's main directory.
   - Run the command: `make all`

3. **Load the Program:**
   - Navigate to the `project/toy` directory: `cd project/toy`
   - Run the command: `make load`
   - Wait for the process to finish and the program to load.

4. **Run the Project:**
   - Enjoy!

## Images 

### Start Screen
(add image here)

### Cop Car Animation
(add image here)

### Mary Had a Little Lamb
(add image here)

### Twinkle Twinkle Little Star
(add image here)

### Stop Image
(add image here)
