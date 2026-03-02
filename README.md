# Spirograph

## Building

```
make
```

This compiles `spiro.cpp` and produces five PDF files: `spiro1.pdf` through `spiro5.pdf`.

## Usage

```
./spiro <ring_teeth> <ring_radius>
```

The program reads drawings from standard input, one per line:

```
r g b wheel_teeth start_angle hole_distance
```

- `ring_teeth` — teeth on the fixed ring
- `ring_radius` — radius of the fixed ring
- `r g b` — RGB color (0.0 to 1.0)
- `wheel_teeth` — teeth on the rolling wheel (must be less than ring_teeth)
- `start_angle` — starting angle in degrees
- `hole_distance` — pen hole position as fraction of wheel radius (0.0 = center, 1.0 = edge)

Output is jgraph on stdout.

## Example

```
echo "1.0 0.0 0.0 63 0 0.8" | ./spiro 96 10.0 | jgraph -P | ps2pdf - output.pdf
```
