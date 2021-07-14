# Cub3D

A 3d game engine implemented using raycasting.
Raycasting calculations are based on angles with cosine, sinine and tangent instead of vectors.

This project features a default 3D game engine and a more elaborated 3D game engine (the bonus part).

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
- S (for Sprite): texture for sprites
- F (for Floor colors): RGB components of the floor color
- C (for Ceiling colors): RGB components of the ceiling color
- Map Configuration:
  - 1 indicates a 1x1 plain wall
  - 0 indicate no wall
  - N or W or E or S indicates the facing direction of the player
  - 2 indicates a sprite

The map_example.cub has a basic configuration.

## Usage

### Launch the default game engine

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

Use the Makefile to compile the project

```bash
make
```

Launch the project

```bash
./Cub3D map_example.cub
```

### Launch the bonus game engine

Bonus features:

- HUD implemented with healthbar
- Sprites move (through walls as well!) to catch you
- Sprites if near you reduce your healthbar
- User can sprint now
- User has a cursor
- Minimap on the top left corner

Added keys in game:

- Shift: sprint

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
