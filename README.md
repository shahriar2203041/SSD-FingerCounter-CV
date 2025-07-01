# CV Finger Counter for 7-Segment Display

This project uses a webcam to count the number of fingers held up (from 1 to 10) and displays the result on a physical 7-segment display connected to an Arduino Uno.



## Features
- Real-time hand and finger detection using MediaPipe.
- Counts fingers from one or two hands.
- Sends the count to an Arduino via Serial communication.
- Displays numbers 1-9 on a 7-segment display.

## Hardware Required
- Arduino Uno (or compatible board)
- 7-Segment Display (Common Cathode)
- Jumper Wires
- A computer with a webcam

## Software & Setup Instructions

### Part 1: Arduino Setup
1.  Connect your 7-segment display to the Arduino according to the wiring map inside the code. The map for this project is:
    - Segment **g** -> pin **4**
    - Segment **f** -> pin **6**
    - Segment **a** -> pin **9**
    - Segment **b** -> pin **10**
    - Segment **e** -> pin **5**
    - Segment **d** -> pin **3**
    - Segment **c** -> pin **12**
2.  Open the `arduino_code/finger_counter_sketch.ino` file in the Arduino IDE or PlatformIO.
3.  Upload the sketch to your Arduino Uno.

### Part 2: Python Setup
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/your-username/CV-Finger-Counter.git
    cd CV-Finger-Counter
    ```
2.  **Create a virtual environment** (this keeps your project's libraries separate):
    ```bash
    python -m venv venv
    ```
3.  **Activate the virtual environment:**
    - On Windows: `.\venv\Scripts\activate`
    - On Mac/Linux: `source venv/bin/activate`
4.  **Install the required libraries** using the `requirements.txt` file:
    ```bash
    pip install -r requirements.txt
    ```

### Part 3: Running the Project
1.  Connect your Arduino to the computer. Find its COM port (e.g., `COM5` in the Arduino IDE).
2.  Open the `main.py` file and change the `PORT_NAME` variable to your Arduino's port.
    ```python
    PORT_NAME = 'COM5'  # <--- Change this!
    ```
3.  Run the script from your terminal:
    ```bash
    python main.py
    ```
4.  Show your hands to the camera and watch the 7-segment display light up!
