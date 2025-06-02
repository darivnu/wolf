# Wolf3D

A modern implementation of the classic Wolf3D raycasting engine built in C with CSFML. Features real-time 3D rendering, textured environments, animated weapons, and immersive 3D audio.

![Wolf3D Demo](https://img.shields.io/badge/Status-In%20Development-yellow)
![License](https://img.shields.io/badge/License-MIT-blue)
![Language](https://img.shields.io/badge/Language-C-orange)
![Graphics](https://img.shields.io/badge/Graphics-CSFML-red)

## ✨ Features

- **3D Raycasting Engine**: Classic first-person perspective with textured walls
- **Weapon System**: Dual spell types (Blue/Orange) with mana management
- **Immersive Audio**: 3D positional sound with background music
- **Interactive HUD**: Health/mana bars, minimap, and spell selection
- **Animation System**: Smooth weapon and UI animations
- **Custom OOP**: Object-oriented architecture implemented in C

## 🚀 Quick Start

### Prerequisites
- GCC compiler and CSFML libraries

#### Linux
- Ubuntu/Debian: `sudo apt install gcc make libcsfml-dev`
- Arch Linux: `sudo pacman -S gcc make csfml`

#### macOS
- `brew install gcc make csfml`

### Building & Running
```bash
git clone https://github.com/darivnu/wolf3d.git
cd wolf3d
make
./wolf3d
```

## 🎮 Controls

### Movement
- **W** - Move forward
- **S** - Move backward
- **A** - Strafe left
- **D** - Strafe right
- **Mouse** - Look around
- **← →** - Rotate left/right (keyboard)

### Combat
- **Left Click** - Cast spell (consumes mana)
- **1** - Switch to Blue spell
- **2** - Switch to Orange spell

### System
- **ESC** - Exit game

## 🏗️ How It Works

### Object-Oriented Architecture
Custom OOP system in C with key components:
- **GameClass_t**: Main game controller
- **RayClass_t**: Raycasting calculations using DDA algorithm
- **RenderClass_t**: Graphics rendering and texture mapping
- **PlayerClass_t**: Movement, collision detection
- **WeaponClass_t**: Spell system with animations
- **SoundClass_t**: 3D positional audio management

### Raycasting Pipeline
1. **Ray Generation**: Cast rays for each screen column
2. **Wall Detection**: DDA algorithm finds intersections
3. **Texture Mapping**: Calculate texture coordinates
4. **Rendering**: Draw textured wall strips with proper depth

## 🗺️ Map Format
Maps are text files with numeric values:
```
5 5
1 1 1 1 1
1 0 0 0 1
1 0 2 0 1
1 0 0 0 1
1 1 1 1 1
```
- `0`: Empty space
- `1-12`: Different wall textures
