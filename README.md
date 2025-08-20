# Terminal Pixel Graphics (by Pawan Kumar)

A lightweight C++ header-style library for drawing simple graphics directly in the terminal using **ANSI escape codes**.  
This is **not a GUI toolkit** — it's meant for terminal graphics (pixel art, prototypes, simple visualizations).

---

## Features
- Draw a single pixel with a chosen color.
- Draw adjustable rectangular blocks with a chosen color.
- Works in most modern terminals (Linux, macOS, WSL).
- Supports **256 ANSI colors**.

---

## Usage

### 1. Include
Copy `pixel.cpp` into your project and include it:
```cpp
#include "pixel.cpp"
````

### 2. Functions

#### Draw a single pixel

```cpp
pixel.single(row, column, colour_code);
```

* `row`, `column`: Position in terminal (1-based index).
* `colour_code`: 0–255 (ANSI 256 color code).

Example:

```cpp
pixel.single(5, 10, 196);  // Red pixel at row 5, column 10
```

#### Draw a rectangle

```cpp
pixel.adjustable(row_1, column_1, row_2, column_2, colour_code);
```

* `(row_1, column_1)`: Top-left corner.
* `(row_2, column_2)`: Bottom-right corner.
* `colour_code`: 0–255.

Example:

```cpp
pixel.adjustable(2, 2, 5, 10, 46); // Green rectangle from (2,2) to (5,10)
```

-------------------------------------------------------------------------------------------------------------

## Notes

* Rows/columns start at **1**, not 0.
* Works best in terminals sized around **200–300 columns** and **100–150 rows**.
* For colors, search: *ANSI 256 color codes chart*.

-------------------------------------------------------------------------------------------------------------

## Example Program

```cpp
#include "pixel.cpp"
int main() {
    pixel.single(3, 3, 34);            // Blue pixel
    pixel.adjustable(5, 5, 8, 15, 196); // Red rectangle
}

-------------------------------------------------------------------------------------------------------------

## License
MIT License – free to use and modify.
Do you want me to also prepare a **LICENSE file (MIT)** for you, so you just drop it in alongside this?
