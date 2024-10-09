# cub3D
![42](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)

cub3D is my first RayCaster implemented in C using the MiniLibX graphical library. The project aims to create a 3D graphical representation of the inside of a maze from a first-person perspective, inspired by the classic game Wolfenstein 3D.First Raycasting using miniLibX.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Game Mechanics](#game-mechanics)
- [Graphic Management](#graphic-management)
- [Map Structure](#map-structure)

## Project Overview

The cub3D project aims to enhance our skills in graphics, window management, and event handling using the MiniLibX library. The goal is to create a ray-casting engine to navigate through a maze.

## Features

- Realistic 3D rendering using ray casting
- Player movement with keyboard inputs (WASD and arrow keys)
- Wall textures based on direction (North, South, East, West)
- Smooth window management
- Floor and ceiling color customization

## Requirements

- Written in C and compliant with the Norm.
- All memory must be properly managed and freed; no memory leaks are tolerated.
- Makefile: The project must include a Makefile with at least the following rules: NAME, all, clean, fclean, re, and bonus if applicable.
- Compilation: Use `cc` with the flags `-Wall`, `-Wextra`, and `-Werror`.
- External functions: open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday, all functions of the math library, and MiniLibX functions.
- MiniLibX must be installed. [This doc explains how to install it.](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

## Installation

To build and run cub3D you need a c++ compiler, make and MiniLibX must be installed. [This doc explains how to install it.](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

Then, follow these steps:

1. Clone the repository:
```
git clone https://github.com/yourusername/cub3D.git
```
2. Change into the cloned directory:
```
cd cub3D
```
3. Build the project:
```
make
```

The Makefile includes the following targets:
- `NAME`: Compiles the project
- `all`: Compiles the project
- `clean`: Removes object files
- `fclean`: Removes object files and the executable
- `re`: Rebuilds the project

## Usage

After building the project, you can start it by running:
./cub3D [path to the map file]
For example:
./cub3D maps/map.cub
This will open the game window with the specified map.

## Game Mechanics

- The player's goal is to navigate the maze and avoid walls.
- Use the W, A, S, and D keys to move the character.
- The left and right arrow keys allow the player to look around.
- Pressing ESC or clicking the window's close button will exit the game cleanly.

## Graphic Management

- The window must remain responsive to minimize, maximize, and switch between applications.
- The program should use images provided by MiniLibX for wall textures and must manage graphics smoothly.

## Map Structure

- The map consists of walls, empty spaces, and the player's starting position.
- Valid characters:
  - `0` for an empty space
  - `1` for a wall
  - `N`, `S`, `E`, or `W` for the player's start position and direction

### Example Map
```
111111
100101
101001
1100N1
111111
```

- The map must be surrounded by walls; if not, the program should return an error.
- The program must be able to parse any valid map file that follows the rules.

If any misconfiguration is found in the map file, the program must exit properly and display "Error\n" followed by an appropriate error message.


You can find maps in the map directory
