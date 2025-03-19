# Cubstein3D - A Raycasting Game Inspired by Wolfenstein 3D #
<img width="1000" alt="Image" src="https://github.com/user-attachments/assets/9350ee63-90e4-4f32-a6f0-6eef6f3595e5" />

---

## **Table of Contents** ##
1. **[Project Overview](#project-overview)** 
2. **[Features](#features)**
3. **[Project Structure](#project-structure)** 
4. **[Technologies Used](#technologies-used)**
5. **[How it Works](#how-it-works)**
6. **[Game Controls](#game-controls)**
7. **[Map Format](#map-format)**
8. **[Future Improvements](#future-improvements)**
9. **[Getting Started](#getting-started)**
10. **[License](#license)**

---

## **Project Overview** ##
**Cubstein3D** is a **raycasting-based** game inspired by the iconic **Wolfenstein 3D**, the first-ever FPS. Built in `C` using the [MLX42](https://github.com/codam-coding-college/MLX42) library, it brings classic **2.5D graphics** to life, **Cubstein3D** focused on **low-level graphics programming** and game **mechanics**.

## **Features** ##
- **Raycasting engine** to render walls and textures.
- Smooth player movement and rotation.
- **Collision** detection.
- **Texture** mapping
- **Minimap**.
- **Door** system.
- **Weapon** animation.

## **Project Structure** ##
<img width="320" alt="Image" src="https://github.com/user-attachments/assets/4774b865-a1a8-4389-b5dc-0708d1667a6f" />

## **Technologies Used** ##
- **Language**: `C`
- **Graphics Library**: [MLX42](https://github.com/codam-coding-college/MLX42)
- **Math**: Vector arithmetic, Trigonometry.
- **Build System**: `Makefile`
- **OS**: `macOS`

## **How it Works** ##
Cub3D uses ray-casting to project 2D maps into a 3D perspective:
  1. The world is represented as a **2D grid map**.
  2. The player is a point with a direction and field of view (FOV).
  3. For each vertical stripe on the screen, a **ray** is cast in the direction of the player's view.
  4. When the **ray** hits a wall, the **distance** is calculated and used to draw a vertical slice (wall) with the correct **height** and **texture**.
  5. **Repeat** for all **rays** to fill the screen and simulate a **3D environment**.

## **Game Controls** ##
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
      <td><code>R</code></td>
      <td>Reload weapon</td>
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
      <td><code>ESC</code></td>
      <td>Exit game</td>
    </tr>
  </tbody>
</table>

## **Map Format** ##
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
1111111112111111111
1000000N00110000001
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
>   * `2`: Door
>   * `N`, `S`, `E`, `W`: Player starting position and direction

## **Future Improvements** ##
<table>
  <thead>
    <tr>
      <th>Category</th>
      <th>Feature</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <!-- Graphics & Visuals -->
    <tr>
      <td rowspan="5"><strong>Graphics & Visuals</strong></td>
    </tr>
    <tr>
      <td>Day/Night Cycle</td>
      <td>Cycle between day and night to enhance immersion</td>
    </tr>
    <tr>
      <td>Skybox Implementation</td>
      <td>Textured sky (stars, clouds) for realistic environments</td>
    </tr>
    <tr>
      <td>Weather Effects</td>
      <td>Rain, snow, fog simulation</td>
    </tr>
    <tr>
      <td>Animated Textures</td>
      <td>Animated doors, moving water, flickering lights</td>
    </tr>
    <!-- Gameplay Mechanics -->
    <tr>
      <td rowspan="3"><strong>Gameplay Mechanics</strong></td>
      <td>Weapon System</td>
      <td>Multiple weapons, ammo pickups, and weapon switching</td>
    </tr>
    <tr>
      <td>Health & Damage System</td>
      <td>Health bar, damage system, pickups for health</td>
    </tr>
    <tr>
      <td>Enemy AI</td>
      <td>Enemies with pathfinding and attack behaviors</td>
    </tr>
    <!-- UI & HUD -->
    <tr>
      <td rowspan="3"><strong>UI & HUD</strong></td>
    </tr>
    <tr>
      <td>Animated HUD</td>
      <td>Dynamic HUD with health, ammo, weapon indicators</td>
    </tr>
    <tr>
      <td>Pause Menu</td>
      <td>In-game pause, settings, controls adjustments</td>
    </tr>
    <!-- Audio -->
    <tr>
      <td rowspan="2"><strong>Audio</strong></td>
      <td>3D Positional Audio</td>
      <td>Directional sounds (footsteps, enemies, weapons)</td>
    </tr>
    <tr>
      <td>Background Music & Ambient Sounds</td>
      <td>Dynamic music and environmental sound effects</td>
    </tr>
    <!-- Map Features -->
    <tr>
      <td rowspan="2"><strong>Map Features</strong></td>
      <td>Multiple Levels/Maps</td>
      <td>Ability to load and play various levels</td>
    </tr>
    <tr>
      <td>Level Editor</td>
      <td>Tool to design and create new maps</td>
    </tr>
    <!-- Performance Enhancements -->
    <tr>
      <td rowspan="2"><strong>Performance</strong></td>
    </tr>
    <tr>
      <td>Optimized Rendering</td>
      <td>Improve rendering performance and efficiency</td>
    </tr>
    <!-- Multiplayer -->
    <tr>
      <td><strong>Multiplayer</strong></td>
      <td>Online Multiplayer</td>
      <td>Multiplayer mode for local or online play</td>
    </tr>
  </tbody>
</table>

## **Getting Started** ##
### **Prerequisties :** ###
- macOS

### Usage : ###
##### **Building the project** #####
1. Clone Cubstein3D repository : 
```bash
git clone https://www.github.com/exoks/Cubstein3D.git
cd Cubstein3D
```
2. Compile the `cub3d` executable: 
```bash
make
```
3. run `cub3d`: 
```bash
./cub3d <path_to_map.cub>
```
##### **Cleanup** #####
- Remove Object files: 
```bash
make clean
```
- Remove all binaries and object files:
```bash
make fclean
```

## **License** ##
- This project is for educational purposes and is not intended for commercial use.
Feel free to fork and experiment! 🤝

---
