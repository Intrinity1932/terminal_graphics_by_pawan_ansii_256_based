````markdown
# terminal_graphics_by_pawan_ansii_256_based

A minimal, low-level toolkit for **256-color terminal graphics** using pure ANSI escape codes (**48;5** only).  
No GUI. No frameworks. Just **rows, columns, and color** — exactly as the terminal allows.

---

## What this project is

- A **precision tool** for painting the terminal with **ANSI 256 colors**.
- A **C / C++ friendly** codebase: single-file includes, zero external deps.
- A foundation you can extend with **math-driven shapes** (lines, circles, arcs, fills) using `<cmath>`.

**Not** a curses wrapper. **Not** a truecolor engine. **Not** a game framework.  
It’s the **bare-metal terminal canvas** you control.

---

## Guarantees & constraints

- **Color model:** strictly **48;5** (ANSI 256). No RGB, no 24-bit.
- **Coordinate system:** 1-based `(row, column)`. You draw where you say.
- **Surface:** your terminal grid (typical ranges: ~200–300 columns × ~100–150 rows).
- **Portability:** works on modern UNIX-like terminals (Linux, macOS, WSL).  
  Windows 10+ is fine if **Virtual Terminal** sequences are enabled.

---

## Why this exists

Because sometimes you don’t need a framework — you need **direct control**.  
Because creative limits (fixed cells, 256 colors) force **clarity and intent**.  
Because the terminal can be more than a log window.

---

## Getting started

Clone the repo and include the file that matches your language:

- **C++**: `#include "pixel.cpp"`
- **C**:   `#include "pixel.c"`

Build with your usual compiler:
```bash
# C++
g++ demo.cpp -O2 -std=c++17 -o demo

# C
gcc demo.c -O2 -std=c11 -o demo
````

> Tip (Windows): enable ANSI sequences once per session:
>
> ```powershell
> reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f
> ```
>
> Or call the WinAPI flag to enable VT processing in your app.

---

## Quick demo (feel the grid)

```cpp
#include "pixel.cpp"

int main() {
    // paint a few cells and a small block — 256-color only
    pixel.single(3, 3, 34);          // deep blue-ish
    pixel.single(3, 4, 196);         // red
    pixel.adjustable(6, 6, 10, 20, 46); // green rectangle
}
```

No dependencies. No hidden state. You tell the terminal what to draw — it draws.

---

## Design principles

* **Do one thing well:** 48;5 background color blocks on a terminal grid.
* **Predictable I/O:** ANSI sequences, explicit cursor moves, explicit resets.
* **Small surface area:** keep the API tight; power lives in composition.
* **Math first:** upcoming shapes rely on deterministic integer algorithms.

---

## Shape roadmap (math-driven, 48;5 only)

* **Lines:** Bresenham (integer error accumulation).
* **Rectangles:** filled and outlined (already grounded).
* **Circles:** Midpoint circle algorithm (integer, symmetric plotting).
* **Ellipses / arcs:** midpoint variants.
* **Triangles:** scanline fill (integer spans).
* **Flood fills:** stack-safe bounded fill on a discrete grid.
* **Text overlay:** foreground 38;5 with background 48;5 (still 256-only).

Everything remains **48;5**. No 24-bit detours.

---

## Performance notes

* Terminal renders best with **row-wise writes** and **minimal resets**.
* Set color once per span, then emit spaces; reset at row/shape end.
* Avoid flushing per cell. Flush **per operation** (or per “frame” if you later animate).
* The grid is small; correctness beats micro-premature optimization.

---

## Compatibility checklist

* **Linux/macOS/WSL terminals:** iTerm2, kitty, Alacritty, GNOME Terminal, etc. ✔️
* **Windows 10+ terminal:** ✔️ (with VT sequences enabled)
* **Old/basic shells without ANSI:** Not supported (by design)

---

## License

**MIT** — use it, remix it, break it, ship it.

---

## Author

Built by **Pawan Kumar** — for people who like to work close to the metal,
and don’t need permission to paint the terminal.
