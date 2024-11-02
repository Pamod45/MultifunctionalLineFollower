# 🌟 Multi-Functional Line Follower Robot 🌟

Welcome to the **Multi-Functional Line Follower Robot** project! This robot is an advanced line-following system with enhanced capabilities to detect and avoid obstacles by picking them up and moving them aside. Designed for industrial applications, it ensures safe transport of goods by avoiding collisions on its designated path.

---

## ✨ Features
- **Line Following**: Follows a designated path using infrared (IR) sensors.
- **Object Detection and Avoidance**: Equipped with an ultrasonic sensor to detect obstacles and a robotic arm for obstacle removal.
- **Energy Efficient**: Designed to minimize motor and sensor usage for power-saving efficiency.
- **Automatic Lighting System**: LDRs activate LED lights in low-light environments, making it operable day or night.

---

## 🧩 Components
- **Microcontroller**: Arduino Uno
- **Motor Driver**: L293D
- **Sensors**: IR sensors, ultrasonic sensor, LDR sensor
- **Actuators**: Servo motors (x4 for the robotic arm), gear motors (x2 for wheels)
- **Battery**: Two 3.7V Lithium-Ion batteries

---

## ⚙️ Building and Setup
### 🔩 Hardware Assembly
Assemble the robot in three stages:
1. **Chassis and Line Following Setup**:
   - Construct the chassis using Rigi-Foam, and attach motors, IR sensors, and wheels.
   - Mount the Arduino Uno and L293D motor driver.
2. **Object Detection and Arm Control**:
   - Attach the ultrasonic sensor and robotic arm, and connect servo motors to the PCA9685 driver.
3. **Automatic Lighting System**:
   - Attach LDR sensors and LED lights to the front of the chassis.

### 🖥️ Software Setup
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/multi-functional-line-follower.git
   
1. **Open Arduino IDE**:
   - Ensure you have the latest version of the [Arduino IDE](https://www.arduino.cc/en/software) installed.
   - Connect your Arduino Uno to your computer via USB.

2. **Select the Correct Board and Port**:
   - In the Arduino IDE, go to **Tools > Board** and select **Arduino Uno**.
   - Then, go to **Tools > Port** and select the port corresponding to your Arduino.

3. **Upload the Code**:
   - Open the code file in the Arduino IDE.
   - Click the **Upload** button (the right arrow icon) to compile and upload the code to the Arduino board.

4. **Verify Successful Upload**:
   - Look for the "Done uploading" message at the bottom of the IDE.
   - If there are errors, double-check connections and ensure all libraries are installed.

---

## 🚀 Usage
- **Line Following Mode**: The robot autonomously follows a black line on a white surface.
- **Obstacle Handling**: When an obstacle is detected, the robot stops, activates the arm to move the object aside, and then resumes its path.
- **Lighting**: LEDs automatically illuminate when the environment is dark, allowing the robot to operate in low-light conditions.

---

## ⚠️ Limitations
- The robot can only pick up objects within a specified weight range.
- It detects only black lines on white surfaces, limiting its usability on different backgrounds.
- Speed adjustments are necessary to ensure smooth operation.

---

## 💡 Recommendations for Improvement
- **Camera-Based Detection**: Adding a camera for object and line detection could enhance the robot's versatility and accuracy.
- **Bluetooth Control**: Including Bluetooth capability would allow for manual control, especially useful in situations where the robot encounters objects it cannot pick up.

---

## 📜 License
This project is open-source under the MIT License. Contributions and suggestions are welcome!

---

## 🙏 Acknowledgments and Thanks
Thank you for your interest in the Multi-Functional Line Follower Robot project! Your support and contributions are invaluable. We hope this project inspires innovation and problem-solving in the field of robotics. If you have any suggestions, feedback, or would like to collaborate, feel free to reach out!

Happy coding, and thank you for being part of our journey! 😊
