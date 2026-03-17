# CUB3D

```text
░████████████ ░██       ░██ ░█████████    ░██████████    ░██████████
░██           ░██       ░██ ░██      ░██            ░██  ░██       ░██
░██           ░██       ░██ ░██      ░██            ░██  ░██       ░██
░██           ░██       ░██ ░█████████      ░█████████   ░██       ░██
░██           ░██       ░██ ░██      ░██            ░██  ░██       ░██
░██           ░██       ░██ ░██      ░██            ░██  ░██       ░██
░████████████ ░████████████ ░█████████    ░██████████    ░██████████
```

> **Cub3D** is a 42 school project that explores the ray-casting technique, inspired by the 90s classic *Wolfenstein 3D*. The goal is to create a dynamic 3D view inside a maze using mathematical principles and the MiniLibX graphical library.

---

## 🎮 Controls

### Mandatory Part
| Action | Key (QWERTY / AZERTY) |
| :--- | :---: |
| Move Forward | `W` / `Z` |
| Move Backward | `S` |
| Move Left | `A` / `Q` |
| Move Right | `D` |
| Exit Game | `ESC` or `✕` window button |

### Bonus Part
| Action | Key |
| :--- | :---: |
| Rotate Camera Left | `←` Left Arrow |
| Rotate Camera Right | `→` Right Arrow |
| Increase Mouse Sensitivity | `↑` Up Arrow |
| Decrease Mouse Sensitivity | `↓` Down Arrow |
| Look around | `Mouse Movement` |

---

## 🛠️ Compilation

Use the provided `Makefile` to compile the project.

**Mandatory version:**
```bash
make
```

**Bonus version:**
```bash
make bonus
```

**Other available rules:**
* `make clean` : Removes object files.
* `make fclean` : Removes object files and the executable.
* `make re` : Recompiles the entire project.

---

## 🚀 Execution

To run the game, you need to provide a `.cub` map file as an argument:

```bash
./cub3D maps/map1.cub
```

### Quick Testing
You can also use the custom Makefile rules to quickly launch tests:
```bash
# Run mandatory test
make test

# Run bonus test
make testbonus
```

---

## 🐛 Debugging & Memory Check

To ensure there are no memory leaks, you can run the program through Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D maps/map1.cub
```

---

## 📝 Evaluation

Useful links for the correction:
* [42 Evaluation Sheet - Cub3d](https://wormav.github.io/42_eval/Cursus/Cub3d/index.html)
