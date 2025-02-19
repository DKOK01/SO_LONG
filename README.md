# 🎮 So_Long - 42 Project

## 📌 Description
**So_Long** is a 2D game built using the **MiniLibX** graphics library.  
The goal is to collect all collectibles (`C`) and reach the exit (`E`) while avoiding enemies (`X`).  

This project focuses on **window management, rendering images, and event handling** using MiniLibX.  

---

## 🎮 Features
- 🔲 **Tile-based game with a maze-like map**
- 🎨 **Graphical interface using MiniLibX**
- 🏆 **Collectibles & animated sprites**
- 🚪 **Exit opens when all collectibles are collected**
- ❌ **Enemies patrol or chase the player**
- 🏁 **Valid path checking to ensure a solvable map**
- 🖥 **Memory leak-free (checked with Valgrind)**

---

## ⚙️ Installation & Usage

### 🎠 **1. Compile the Game**
Run the `Makefile`:
```bash
make
```
This compiles the `so_long` executable.

### 🎮 **2. Run the Game**
```bash
./so_long maps/map1.ber
```
Replace `map1.ber` with your custom `.ber` map file.

### 🟠 **3. Custom Maps**
Maps must follow these rules:
- **Surrounded by walls (`1`)**
- **Contains 1 player (`P`), 1 exit (`E`), at least 1 collectible (`C`)**
- **Can include enemies (`X`)**
- **Valid path from `P` to `E` with all `C` accessible**

---

## 🎮 Controls
| Key | Action |
|-----|--------|
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ESC` | Exit Game |

---

## 🛠 Dependencies
- **MiniLibX** (provided by 42)
- **gcc** compiler
- **Makefile** for compilation
- **Linux/macOS** (Windows is not supported)

---

## 🚀 Notes
- **Check for memory leaks** before submitting:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map1.ber
```
- **To clean up compiled files:**
```bash
make clean  # Removes object files
make fclean # Removes executable & objects
make re     # Recompiles the project
```

---

## 🏆 Author
- **ayman sadeq**  
- **42 Login: aysadeq**  

