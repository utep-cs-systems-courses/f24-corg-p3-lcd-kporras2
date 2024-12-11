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
![start_screen](https://github.com/user-attachments/assets/05fbcf8f-9b26-410f-b426-0427f76ba1f1)

### Cop Car Animation
![cop_car](https://github.com/user-attachments/assets/a3492044-2660-4e4f-a727-d13d37897126)

### Mary Had a Little Lamb
![marry_had_lamb](https://github.com/user-attachments/assets/e0f387c6-c6f4-4d34-8cc6-56fa576c38d0)

### Twinkle Twinkle Little Star
![twinkle_star](https://github.com/user-attachments/assets/b73c1ded-be05-43da-87b9-c6a51c493882)

### Stop Image
![stop](https://github.com/user-attachments/assets/f14bc4bd-c90b-4df5-97cb-a627d009a91f)
