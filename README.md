Here’s a **clean README.md** you can use for your **OpenGL Basic Shape Rendering with Camera Movement** project. It’s written in a way that looks **good on GitHub and on a resume**. 🚀

---

# OpenGL Basic Shape Rendering with Camera Movement

## Overview

This project demonstrates basic **3D rendering using OpenGL** along with **interactive camera movement**. It renders simple shapes and allows the user to navigate the scene using keyboard and mouse controls.

The goal of this project is to understand the fundamentals of the modern OpenGL pipeline including:

* Vertex buffers and vertex arrays
* Shader programs
* Transformations (Model, View, Projection)
* Camera movement
* Basic 3D scene navigation

---

## Features

* Rendering of basic 3D shapes
* Modern OpenGL (Core Profile)
* Shader-based rendering pipeline
* Camera movement in a 3D scene
* Keyboard controls for navigation
* Mouse input for camera direction
* Perspective projection

---

## Technologies Used

* **C++**
* **OpenGL 3.3+**
* **GLFW** – Window creation and input handling
* **GLAD** – OpenGL function loader
* **GLM** – Mathematics library for transformations
* **stb_image** *(optional if textures used)*

---

## Controls

| Key   | Action        |
| ----- | ------------- |
| W     | Move Forward  |
| S     | Move Backward |
| A     | Move Left     |
| D     | Move Right    |
| Mouse | Look Around   |
| ESC   | Exit Program  |

---

## Project Structure

```
OpenGL-Basic-Rendering
│
├── src
│   └── main.cpp
│
├── shaders
│   ├── vertex.glsl
│   └── fragment.glsl
│
├── include
│   ├── shaderClass.h
│   ├── VAO.h
│   ├── VBO.h
│   └── texture.h
│
├── resources
│   └── textures
│
└── README.md
```

---

## How to Build and Run

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/opengl-shape-rendering.git
cd opengl-shape-rendering
```

### 2. Compile

Example using **g++**:

```bash
g++ main.cpp -lglfw -lGL -lGLU -o app
```

(Compilation steps may vary depending on your system and libraries.)

### 3. Run

```
./app
```

---

## Concepts Demonstrated

* OpenGL rendering pipeline
* Vertex Buffer Objects (VBO)
* Vertex Array Objects (VAO)
* Shader compilation and linking
* Transformation matrices
* Camera view matrix
* Perspective projection

---

## Future Improvements

* Texture mapping
* Lighting (Phong / Blinn-Phong)
* Model loading
* Skybox
* Shadow mapping
* Multiple light sources

---

## Learning Resources

* LearnOpenGL
* OpenGL Documentation
* GLFW Documentation

---

## Author

Albert

Computer Science Student interested in **Graphics Programming and Systems Development**



