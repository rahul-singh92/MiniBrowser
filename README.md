# MiniBrowser (C++)

MiniBrowser is a beginner-friendly browser engine project built in **C++**.
It loads a local HTML file, tokenizes it, parses it into a DOM tree, and renders basic elements inside a real window using **SDL2**.

This is NOT based on Chromium/CEF/QtWebEngine — it is a custom mini browser engine built from scratch.

---

## Features (Current)

- Load local HTML file (`test_pages/index.html`)  
- HTML Tokenizer  
- HTML Parser  
- DOM Tree creation  
- Render HTML using SDL2 Window  
- Supports basic tags:
-- `<h1>`
-- `<p>`

---

## Folder Structure
MiniBrowser/
│
├── src/
│ ├── main.cpp
│ │
│ ├── core/
│ │ ├── FileLoader.h
│ │ ├── FileLoader.cpp
│ │
│ ├── html/
│ │ ├── Token.h
│ │ ├── Tokenizer.h
│ │ ├── Tokenizer.cpp
│ │ ├── DOMNode.h
│ │ ├── DOMNode.cpp
│ │ ├── Parser.h
│ │ ├── Parser.cpp
│ │
│ ├── render/
│ │ ├── Renderer.h
│ │ ├── Renderer.cpp
│ │ ├── SDLWindow.h
│ │ ├── SDLWindow.cpp
│ │ ├── SDLRenderer.h
│ │ ├── SDLRenderer.cpp
│
├── test_pages/
│ ├── index.html
│
├── build/
│ ├── MiniBrowser (generated)
│
└── README.md


---

## Requirements

### macOS
- Homebrew
- g++ / clang++
- SDL2
- SDL2_ttf

Install dependencies:

```bash
brew install sdl2 sdl2_ttf
```

## How to Run

### Step 1: Compile (for mac)
```bash
mkdir -p build

g++ -std=c++17 \
src/main.cpp \
src/core/FileLoader.cpp \
src/html/Tokenizer.cpp \
src/html/Parser.cpp \
src/html/DOMNode.cpp \
src/render/SDLWindow.cpp \
src/render/SDLRenderer.cpp \
-o build/MiniBrowser \
-I/opt/homebrew/include \
-L/opt/homebrew/lib \
-lSDL2 -lSDL2_ttf

```

### Step 2: Run
```bash
./build/MiniBrowser
```

## Test Page
Edit the html file and use only <h1> and <p>:
```bash
test_pages/index.html
```

## How the Browser Works

### 1. File Loading
The browser reads the html file using:
- FileLoader.cpp (This uses fstream and other file reading libraries)

### 2. Tokenizer
Converts html file into token like:
- OPEN_TAG(<h1>)
- CLOSE_TAG(</h1>)
- TEXT(Hihahihahiha)

File:
- Tokenizer.cpp(use string method like substr and find to get the content of tag and comments)

### 3. Parser
Build a DOM Tree using stack-based parsing.

File:
- Parser.cpp(use staack to push the open tags and text inside it and then pop for closing tags)

## Notes
- The browser only supports a very small HTML tags i.e. <h1> and <p>.
- Modern website will not work(no JavaScript engine, no layout engine like flexbox, etc.).
- The goal is to learn browser internals, not replacing chrome.
