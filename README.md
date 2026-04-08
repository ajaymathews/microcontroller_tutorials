# Microcontroller : Tutorial Series

A comprehensive repository of register-level and application-level code for three major microcontroller architectures: **ARM Cortex-M4**, **ATmega328P**, and **PIC16F877A**.

This repository is designed as a learning resource for embedded systems developers, transitioning from basic GPIO manipulation to advanced communication protocols and RTOS.

## 🚀 Repository Structure

### 1. ARM Cortex-M4 (STM32F4 Series)
- **REG_LEVEL:** Deep-dive into register manipulation for GPIO, ADC, PWM, UART, SPI, and Timers.
- **RTOS:** Real-time Operating System implementations.
- **TouchGFX:** Graphical user interface development examples.

### 2. ATmega328P (AVR)
- **Peripherals:** ADC, PWM, Timers, and External Interrupts.
- **Communication:** Standard UART/I2C/SPI interfaces.
- **Interface:** Character LCDs and 7-segment displays.

### 3. PIC16F877A (Microchip)
- **Core Tutorials:** Standard ADC, PWM, and Timer setups.
- **Communication:** UART TX/RX logic with robust baud rate calculations.
- **Interface:** Basic sensor and actuator interfacing.

## 🛠 Prerequisites
- **ARM:** Keil uVision 5 or STM32CubeIDE.
- **AVR:** Atmel Studio 7 or Microchip Studio.
- **PIC:** MPLAB X IDE with XC8 Compiler.
- **Simulation:** Proteus Design Suite (for included `.pdsprj` files).

## 📝 Usage Note
This repository contains a mix of optimized production-ready logic and educational "unoptimized" examples (such as software-based delay loops) intended to demonstrate underlying timing mechanics. Please check individual file comments for architectural context.

## ⚖ License
Distributed under the MIT License. See `LICENSE` for more information.

---
*Maintained for educational purposes. Happy Coding!*
