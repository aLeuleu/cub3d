# Cub3d

Welcome to Cub3d! This project is a basic implementation of a 3D maze using the Raycasting technique. It is inspired by the classic game Wolfenstein 3D and serves as an introduction to the world of graphic programming.

## Prerequisites

To run this project, you need to have the following dependencies installed on your system:

- C compiler (e.g., cc)
- Make build system

## Getting Started

Follow the instructions below to get the project up and running on your local machine.

1. Clone the repository:

   ```shell
   git clone https://github.com/aLeuleu/cub3d.git
   ```

2. Navigate to the project directory:

   ```shell
   cd cub3d
   ```

3. Build the project:

   ```shell
   make
   ```

4. Run the program:

   ```shell
   ./cub3D maps/<map-file>
   ```

   Replace `<map-file>` with the path to a valid map file in the required format (see the Map Format section).

## Map Format

The map must have a `.cub` file extension and must contain the path of the **NO**, **SO**, **WE** and **EA** textures of the walls in `.xpm` format like this:

```
NO ./textures/NO.xpm
SO ./textures/SO.xpm
EA ./textures/EA.xpm
WE ./textures/WE.xpm
```

Without forgetting that the color of the floor and the ceiling must be provided in ***RGB*** code like this:

- **C**: Ceiling color
- **F**: Floor color

```
C 27,27,27
F 112,112,100
```

The map is defined in a text file. Each character represents a different element of the map. Here's a brief overview:

- **0**: Empty space
- **1**: Wall
- **N**, **S**, **E**, **W**: Player starting position and orientation

For example:

```
1111111
1000001
100N001
1000001
1111111
```

> **Warning**:
> The description of the map must always be at the end of the file, after
> having defined the path of the textures and the colors.

## Controls

Use the following controls to interact with the program:

- **W**: Move forward
- **S**: Move backward
- **A**: Move left
- **D**: Move right
- **Q** / **LEFT_ARROW**: Rotate left
- **E** / **RIGHT_ARROW**: Rotate right
- **MOUSE**: Rotate the view
- **ESC**: Quit the program

## Credits

The program was entirely developed by [Aurelien](https://github.com/aLeuleu) and [Leon](https://github.com/LeonPupier). With the help of the mlx.

See you soon on other projects ;)