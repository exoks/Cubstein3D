# Cubstein3D - A Raycasting Game Inspired by Wolfenstein 3D #
add image for cub3d

## Table of Contents ##
1. **[Project Overview](#project-overview)** 
2. **[Features](#features)**
3. **[Technologies Used](#technologies-used)**
4. **[How it Works](#how-it-works)**
5. **[Project Structure](#project-structure)** 
6. **[Game Controls](#game-controls)**
7. **[Map Format](#map-format)**
8. **[Getting Started](#getting-started)**
9. **[Future Improvements](#future-improvements)**
10. **[License](#license)**

## Project Overview ##
Cubstein3D is a raycasting-based game inspired by the iconic Wolfenstein 3D, the first-ever FPS. Built in C using the MLX42 library, it brings classic 2.5D graphics to life, cub3d focused on low-level graphics programming and game mechanics.

## Features ##
- Raycasting engine to render walls and textures.
- Smooth player movement and rotation.
- Collision detection.
- Texture mapping
- Minimap.
- Door system.
- Weapon animation.

## Technologies Used ##
- Language: `C`
- Graphics Library: [MLX42](https://github.com/codam-coding-college/MLX42)
- Math: Vector arithmetic, Trigonometry.
- Build System: `Makefile`
- OS: `macOS`

## How it Works ##
Cub3D uses raycasting to project 2D maps into a 3D perspective:
  1. The world is represented as a 2D grid map.
  2. The player is a point with a direction and field of view (FOV).
  3. For each vertical stripe on the screen, a ray is cast in the direction of the player's view.
  4. When the ray hits a wall, the distance is calculated and used to draw a vertical slice (wall) with the correct height and texture.
  5. Repeat for all rays to fill the screen and simulate a 3D environment.

## Project Structure ##
add image for project structure

## Game Controls ##
<table>
  <thead>
    <tr>
      <th>Key / Mouse</th>
      <th>Action</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>W</code></td>
      <td>Move forward</td>
    </tr>
    <tr>
      <td><code>S</code></td>
      <td>Move backward</td>
    </tr>
    <tr>
      <td><code>A</code></td>
      <td>Strafe left</td>
    </tr>
    <tr>
      <td><code>D</code></td>
      <td>Strafe right</td>
    </tr>
    <tr>
      <td><code>&larr; (Left Arrow)</code></td>
      <td>Turn left</td>
    </tr>
    <tr>
      <td><code>&rarr; (Right Arrow)</code></td>
      <td>Turn right</td>
    </tr>
    <tr>
      <td><code>ESC</code></td>
      <td>Exit game</td>
    </tr>
    <tr>
      <td><code>M</code></td>
      <td>Toggle minimap</td>
    </tr>
    <tr>
      <td><code>Mouse Move Left/Right</code></td>
      <td>Rotate camera</td>
    </tr>
    <tr>
      <td><code>Mouse Move Up/Down</code></td>
      <td>Move camera up/down</td>
    </tr>
    <tr>
      <td><code>Left Mouse Button</code></td>
      <td>Aim weapon</td>
    </tr>
    <tr>
      <td><code>Right Mouse Button</code></td>
      <td>Fire weapon</td>
    </tr>
    <tr>
      <td><code>R</code></td>
      <td>Reload weapon</td>
    </tr>
  </tbody>
</table>

## Map Format ##
Cub3D reads maps from .cub files with the following structure:

```bash
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm

F 220,100,0
C 225,30,0

1111111111111111111
1000000000110000001
1011010001111111111
1001000000000000001
1111111110110000001
1000000000110000001
1000000000000000001
1111111111111111111
```
> Elements:  
> - `NO`, `SO`, `WE`, `EA`: Paths to wall textures.
> - `F`: RGB color of the floor.
> - `C`: RGB color of the ceiling.
> - The map is a matrix of:
>   * `1`: Wall
>   * `0`: Empty space
>   * `N`, `S`, `E`, `W`: Player starting position and direction

## Getting Started ##
### Prerequisties : ###
1. macOS
2. clone and Build 

### Usage : ###
##### Building the project : #####
1. Clone Cubstein3D repository : 
```bash
git clone https://www.github.com/exoks/Cubstein3D.git
cd Cubstein3D
```
2. Comple the `cub3d` executable: 
```bash
make
```
3. run `cub3d`: 
```bash
./cub3d <path_to_map.cub>
```
##### Cleanup #####
- Remove Object files: 
```bash
make clean
```
- Remove all binaries and object files:
```bash
make fclean
```

## Future Improvements ##
Door mechanism: Open/close interactive doors.
Sprite rendering: Add enemies or objects.
Weapon & HUD animation.
Dynamic lighting & fog effect.
Sound effects (background music, shooting, footsteps).
Multiple weapon systems.
AI bots or enemies.

## License ##
This project is for educational purposes and is not intended for commercial use.
Feel free to fork and experiment!
