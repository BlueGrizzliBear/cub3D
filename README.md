# Cub3D

A 3D game engine implemented using raycasting.
Raycasting is based on angles' cosine, sinine and/or tangent calculations instead of vectors' calculations.

This project features:
- a default 3D game engine
- a 3D game engine with additional features to turn it into a small 3D video game

## Context

This project is part of the cub3d project of 42 Software Engineering program.

## Configuration

The program should be given on the first argument the path to a .cub configuration file.

Configurable elements in this file include:

- R (for game Resolution): length and height of the screen, in pixels.
- NO (for North texture): path to texture file of object facing north in the game.
- SO (for South texture)
- WE (for West texture)
- EA (for East texture)
- S (for Sprite): path to texture file for sprites objects
- F (for Floor colors): RGB components of the floor color (numbers between 0 and 255)
- C (for Ceiling colors): RGB components of the ceiling color (numbers between 0 and 255)
- Map Configuration:
  - 1 indicates a 1x1 plain wall
  - 0 indicate no wall
  - N or W or E or S indicates the position and facing direction of the player
  - 2 indicates the position of a sprite

The map_example.cub has a basic configuration.

## Usage

### Default game engine

The default game engine features:

- No collisions between player and objects
- Immobile sprites

Basic keys in game:

- ESC: quits the game
- W: move forward
- S: move backward
- A: strafe left
- D: strafe right
- <-: rotate left
- ->: rotate right

<img width="1281" alt="basic_game_engine_screenshot" src="https://user-images.githubusercontent.com/49372605/125628390-1937b2f0-7f1b-4586-9d17-c40a1d2325e3.png">

Use the Makefile to compile the project

```bash
make
```

Launch the project

```bash
./Cub3D map_example.cub
```

### Bonus features

Bonus features:

- HUD implemented with healthbar
- Sprites move (through walls as well!) to catch you
- Sprites if near you reduce your healthbar
- User can sprint now
- User has a cursor
- Minimap on the top left corner

Added keys in game:

- Shift: sprint

<img width="1281" alt="bonus_features_screenshot" src="https://user-images.githubusercontent.com/49372605/125628407-253aa75e-d6a1-4519-8c79-73ff7f02ae84.png">

Use the Makefile to compile the project

```bash
make bonus
```

Launch the project

```bash
./Cub3D map_example.cub
```

## Known Issues

User can experience FPS drop when:

- Sprite is near the player
- Resolution is large
