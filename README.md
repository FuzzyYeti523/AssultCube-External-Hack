# AssaultCube External Hack

External hack project for AssaultCube built in C++ using WinAPI.

This project focuses on interacting with another process externally by reading and writing memory using custom utility functions and pointer resolution techniques.

---

## 🚀 Features

* External process attachment via process name
* Module base address retrieval
* Dynamic pointer resolution (multi-level pointer / DMA)
* Read / Write process memory abstraction
* Logging system using spdlog
* Hotkey-based feature toggling

---

## 🎮 Controls

| Key | Function        |
| --- | --------------- |
| F1  | No Recoil       |
| F2  | Infinite Health |
| F3  | Infinite Ammo   |

---

## 🧩 Core Components

### 🔹 Process & Memory Utilities (submodule)

Located in:

```
lib/Utility/external/
```

Includes:

* FindProcessID
* GetBaseModuleAddress
* FindDMAAddy
* Memory read/write wrappers

---

### 🔹 Logging

* Uses spdlog for structured logging

---

## 🏗️ Project Structure

```
/lib
├── Utility/              # External memory utility (submodule)
│   └── external/
│       ├── include/
│       └── src/
├── spdlog/               # Logging library (submodule)

/src
├── main.cpp              # Entry point
```

---

## ⚙️ Requirements

* Windows
* C++17 or higher
* CMake
* Visual Studio

---

## 🔧 Build

```bash
git clone https://github.com/FuzzyYeti523/AssultCube-External-Hack.git
cd AssultCube-External-Hack

git submodule update --init --recursive

mkdir build
cd build
cmake ..
cmake --build .
```

---

## ▶️ Usage

1. Launch AssaultCube
2. Run the executable
3. Use hotkeys to toggle features:

   * F1 → No Recoil
   * F2 → Infinite Health
   * F3 → Infinite Ammo

---

## ⚠️ Disclaimer

This project is for educational purposes only.

* Do NOT use in multiplayer environments
* Do NOT use to gain unfair advantage

---

## 🧑‍💻 Author

* GitHub: https://github.com/FuzzyYeti523
