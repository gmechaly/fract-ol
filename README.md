# fract-ol - @42Born2Code

## ✏️ A personal word

fract-ol has been one of my favorite project from the early 42 Common Core. It allies some maths, some thinking logic and you can play with the program in real time. This was the first time I ever used inputs to control a program, so it was really fun to experience this new universe. It led me to do this project's bonuses and even implemented some functionnalities that were not required by the subject.
Grade : 125/100

## 💡 About

**Fract-ol** is a project centered around the exploration of the infinite beauty of fractals. Using the **MiniLibX** graphical library, this program renders complex mathematical sets in real-time, allowing users to navigate through them.

The project focuses on **mathematical precision**, **event handling** (mouse and keyboard), and **color rendering**.

> "Infinite complexity born from simple mathematical rules."

---

## 🛠️ Features (Including Bonuses)

* **Zoom**: Deep dive into the fractal at the mouse position, using the .
* **Real-time Navigation**: Move across the complex plane using the keyboard.
* **Multiple Fractals**: Support for **Mandelbrot**, **Julia**, and the bonus **Burning Ship** set.
* **Color Shifting**: Change the color palette dynamically.
* **Iteration Control**: Increase or decrease the rendering precision (max iterations) on the fly.
* **Parameter Tracking**: For the Julia set, the shape changes based on the variables given. Example : <./fractol julia -0.4 0.7>

---

## 🎮 Controls

The program is fully interactive. Use the following keys to explore:

| Key | Action |
| --- | --- |
| **W / A / S / D / Arrows** | Move **Up / Left / Down / Right** |
| **Mouse Scroll** | **Zoom In / Out** at the cursor position |
| **+ (Plus)** | **Increase Resolution** (More iterations) |
| **- (Minus)** | **Decrease Resolution** (Less iterations) |
| **C** | **Change Color** palette |
| **ESC** | **Exit** the program |

---

## 📐 Mathematical Overview

The core of the project relies on the escape time algorithm. For each pixel $(x, y)$, we map it to a complex number $c$ and iterate the function:


$$z_{n+1} = z_n^2 + c$$


The pixel's color is determined by how quickly the sequence $|z_n|$ diverges to infinity.

---

## 🚀 Usage

### Compilation

To compile the project, run:

```bash
make

```

### Execution

Run the program with the name of the fractal as an argument:

```bash
./fractol mandelbrot
./fractol julia
./fractol burningship

```

*Note: For the Julia set, you can also pass specific coordinates as arguments:*

```bash
./fractol julia -0.4 0.6

```

---

## 📋 Requirements

* **MiniLibX**: Make sure you have the library installed (X11 or Metal version depending on your OS).
* **Math Library**: Linked with `-lm`.

---
