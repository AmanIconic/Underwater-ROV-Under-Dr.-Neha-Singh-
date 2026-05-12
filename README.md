# Underwater-ROV-Under-Dr.-Neha-Singh-

An Arduino-based **Underwater Remotely Operated Vehicle (ROV)** built using **BLDC motors**, **ESCs**, and serial command control.
This project is designed for underwater movement in multiple directions such as forward, backward, upward, and downward using six thrusters.

---

# 🚀 Features

* Control 6 BLDC motors using ESCs
* Forward and backward movement
* Upward and downward movement
* Individual motor testing
* Live motor speed tuning
* ESC calibration support
* Serial command-based control
* Modular and expandable design

---

# 🛠 Components Used

| Component               | Quantity    |
| ----------------------- | ----------- |
| Arduino UNO             | 1           |
| BLDC Motors             | 6           |
| BLHeli 40A ESC          | 6           |
| LiPo Battery            | 1           |
| PVC/Frame Body          | 1           |
| Waterproof Enclosure    | 1           |
| Jumper Wires            | Multiple    |
| Breadboard / Connectors | As required |

---

# ⚙️ Pin Configuration

| Motor   | Function         | Arduino Pin |
| ------- | ---------------- | ----------- |
| Motor 1 | Forward/Backward | D6          |
| Motor 2 | Forward/Backward | D9          |
| Motor 3 | Up/Down          | D10         |
| Motor 4 | Up/Down          | D11         |
| Motor 5 | Up/Down          | D3          |
| Motor 6 | Up/Down          | D5          |

---

# 🎮 Serial Commands

| Command | Action                 |
| ------- | ---------------------- |
| `f`     | Move Forward           |
| `b`     | Move Backward          |
| `u`     | Move Up                |
| `d`     | Move Down              |
| `s`     | Stop All Motors        |
| `1-6`   | Test Individual Motors |
| `+`     | Increase Motor 6 Speed |
| `-`     | Decrease Motor 6 Speed |

---

# 🧠 How I Made This Project

## 1. Project Idea

I wanted to build a simple underwater drone (ROV) that could move underwater using BLDC motors.
The main goal was to control multiple thrusters using Arduino and ESCs.

The project was inspired by:

* Underwater exploration robots
* ROV systems
* Marine robotics
* DIY autonomous vehicles

---

## 2. Frame Design

I created the body/frame using lightweight materials so the ROV could float properly underwater.

The design included:

* Two horizontal thrusters for forward/backward motion
* Four vertical thrusters for up/down stability and depth control
* Waterproof placement for electronics

---

## 3. Motor and ESC Connection

Each BLDC motor was connected to a separate ESC.

The ESC signal wires were connected to Arduino PWM pins:

* D6
* D9
* D10
* D11
* D3
* D5

I used the Arduino Servo library because ESCs accept servo-like PWM signals.

---

## 4. ESC Calibration

One major issue was that one motor was not behaving correctly.

To solve this:

* I individually calibrated the ESC connected to pin D5
* Sent maximum throttle signal
* Then minimum throttle signal
* Waited for ESC beep confirmation

After calibration, all motors started responding properly.

---

## 5. Programming Logic

I wrote the Arduino code to:

* Read serial commands from Serial Monitor
* Control specific motors based on commands
* Stop all motors before changing direction
* Tune speed dynamically

The system works completely through serial communication.

---

## 6. Movement Control

### Forward Movement

Two horizontal thrusters rotate together.

### Backward Movement

Motors run at reverse-compatible throttle values.

### Upward Movement

All four vertical thrusters activate together.

### Downward Movement

Vertical thrusters reduce thrust for downward motion.

---

## 7. Individual Motor Testing

To debug wiring and ESC issues, I added:

* Motor testing commands (`1` to `6`)
* 2-second motor activation test

This helped identify:

* Incorrect wiring
* Faulty ESCs
* Calibration problems

---

# 🔌 Upload Instructions

1. Open Arduino IDE
2. Install Servo Library
3. Connect Arduino UNO
4. Select correct COM Port
5. Upload the code
6. Open Serial Monitor
7. Set baud rate to `9600`
8. Send commands

---

# 🧪 Technologies Used

* Arduino UNO
* Embedded C++
* Servo Library
* PWM Motor Control
* ESC Calibration
* Serial Communication

---

# 👨‍💻 Author

Aman Yadav
BTech-MTech Student

---

# ⭐ Conclusion

This project helped me learn:

* BLDC motor control
* ESC calibration
* PWM signal generation
* Serial communication
* Underwater robotics basics
* Hardware debugging

It was a great hands-on project for learning robotics and embedded systems.
