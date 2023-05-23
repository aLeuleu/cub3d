# Cub3d

Welcome to Cub3d! This project is a basic implementation of a 3D maze using the Raycasting technique. It is inspired by the classic game Wolfenstein 3D and serves as an introduction to the world of graphic programming.

## Prerequisites

To run this project, you need to have the following dependencies installed on your system:

- C compiler (e.g., gcc)
- Make build system
- minilibx (a simple graphics library)

## Getting Started

Follow the instructions below to get the project up and running on your local machine.

1. Clone the repository:

   ```shell
   git clone <repository-url>
   ```

2. Navigate to the project directory:

   ```shell
   cd Cub3d
   ```

3. Build the project:

   ```shell
   make
   ```

4. Run the program:

   ```shell
   ./Cub3d <map-file>
   ```

   Replace `<map-file>` with the path to a valid map file in the required format (see the Map Format section).

## Map Format

The map is defined in a text file. Each character represents a different element of the map. Here's a brief overview:

- '0': Empty space
- '1': Wall
- '2': Sprite
- 'N', 'S', 'E', 'W': Player starting position and orientation

For example:

```
1111111
1002001
100N001
1002001
1111111
```

## Controls

Use the following controls to interact with the program:

- **W**: Move forward
- **A**: Rotate left
- **S**: Move backward
- **D**: Rotate right
- **ESC**: Quit the program

## Resources


## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).