import cv2
import mediapipe as mp
import serial
import time

# --- CONFIGURATION ---
PORT_NAME = 'COM5'  # <--- IMPORTANT: User must set this to their Arduino's port.

try:
    arduino = serial.Serial(port=PORT_NAME, baudrate=9600, timeout=0.1)
    print(f"Successfully connected to Arduino on {PORT_NAME}")
    time.sleep(2) 
except serial.SerialException as e:
    print(f"Error: Could not connect to Arduino on {PORT_NAME}.")
    exit()

# --- SETUP MEDIAPIPE ---
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=2, min_detection_confidence=0.5, min_tracking_confidence=0.5)
mp_draw = mp.solutions.drawing_utils
tip_ids = [4, 8, 12, 16, 20]

# --- START WEBCAM ---
cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)
last_sent_count = -1
print("Starting camera... Show one or two hands. Press 'q' to quit.")

while True:
    success, img = cap.read()
    if not success: continue
        
    img = cv2.flip(img, 1)
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)
    
    total_finger_count = 0
    num_hands_detected = 0

    if results.multi_hand_landmarks:
        num_hands_detected = len(results.multi_hand_landmarks)
        for hand_landmarks in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(img, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            fingers = []
            if hand_landmarks.landmark[tip_ids[0]].x < hand_landmarks.landmark[tip_ids[0] - 1].x:
                fingers.append(1)
            else:
                fingers.append(0)
            for id in range(1, 5):
                if hand_landmarks.landmark[tip_ids[id]].y < hand_landmarks.landmark[tip_ids[id] - 2].y:
                    fingers.append(1)
                else:
                    fingers.append(0)
            total_finger_count += fingers.count(1)

    if total_finger_count != last_sent_count:
        print(f"Hands: {num_hands_detected} | Total Fingers: {total_finger_count} | Sending to Arduino...")
        arduino.write(str(total_finger_count).encode())
        last_sent_count = total_finger_count
        
    info_text = f"Hands: {num_hands_detected}  Fingers: {total_finger_count}"
    cv2.putText(img, info_text, (20, 70), cv2.FONT_HERSHEY_PLAIN, 3, (0, 0, 255), 3)
    cv2.imshow("CV Finger Counter", img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'): break

# --- CLEANUP ---
print("Closing program.")
arduino.write(b'0')
arduino.close()
cap.release()
cv2.destroyAllWindows()






part 2

import cv2
import mediapipe as mp
import serial
import time

# =========================================================================
# ===  DOUBLE-CHECK YOUR ARDUINO'S PORT NAME                          ===
# =========================================================================
PORT_NAME = 'COM5'  # This should match your Arduino's port.

try:
    arduino = serial.Serial(port=PORT_NAME, baudrate=9600, timeout=0.1)
    print(f"Successfully connected to Arduino on {PORT_NAME}")
    time.sleep(2) 
except serial.SerialException as e:
    print(f"Error: Could not connect to Arduino on {PORT_NAME}.")
    exit()

# --- Setup MediaPipe ---
mp_hands = mp.solutions.hands

# =========================================================================
# ===  THIS IS THE FIX: Lowering detection confidence from 0.7 to 0.5   ===
# =========================================================================
hands = mp_hands.Hands(max_num_hands=2, min_detection_confidence=0.5, min_tracking_confidence=0.5)

mp_draw = mp.solutions.drawing_utils
tip_ids = [4, 8, 12, 16, 20]

# --- Start Webcam ---
cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

last_sent_count = -1

print("Starting camera... Show one or two hands. Press 'q' to quit.")

while True:
    success, img = cap.read()
    if not success:
        continue
        
    img = cv2.flip(img, 1)
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)
    
    total_finger_count = 0
    num_hands_detected = 0 # Variable to hold the number of hands

    if results.multi_hand_landmarks:
        # Get the number of hands detected in this frame
        num_hands_detected = len(results.multi_hand_landmarks)
        
        # Loop through each detected hand
        for hand_landmarks in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(img, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            
            fingers = []
            # This logic is simpler and works for both left/right hands
            # Check if thumb tip is further out than the knuckle below it
            if hand_landmarks.landmark[tip_ids[0]].x < hand_landmarks.landmark[tip_ids[0] - 1].x:
                fingers.append(1)
            else:
                fingers.append(0)

            # Other 4 fingers
            for id in range(1, 5):
                if hand_landmarks.landmark[tip_ids[id]].y < hand_landmarks.landmark[tip_ids[id] - 2].y:
                    fingers.append(1)
                else:
                    fingers.append(0)
            
            total_finger_count += fingers.count(1)

    # --- SEND DATA TO ARDUINO ---
    if total_finger_count != last_sent_count:
        print(f"Hands: {num_hands_detected} | Total Fingers: {total_finger_count} | Sending to Arduino...")
        arduino.write(str(total_finger_count).encode())
        last_sent_count = total_finger_count
        
    # --- ADDED DEBUG TEXT TO THE SCREEN ---
    # Now you can see how many hands and fingers are detected
    info_text = f"Hands: {num_hands_detected}  Fingers: {total_finger_count}"
    cv2.putText(img, info_text, (20, 70), cv2.FONT_HERSHEY_PLAIN, 3, (0, 0, 255), 3)
    cv2.imshow("CV to Arduino (2 Hands)", img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# --- Cleanup ---
print("Closing program.")
arduino.write(b'0')
arduino.close()
cap.release()
cv2.destroyAllWindows()
