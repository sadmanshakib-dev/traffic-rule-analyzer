# 🚦 Traffic Rule Analyzer

A compiler-based system built using **Lex & Yacc (implemented using Flex & Bison)**, designed to analyze and validate traffic rules with an integrated **web-based interface** for visualization.

---

## 🧠 Project Overview

The **Traffic Rule Analyzer** is a hybrid system combining compiler design concepts with modern web technologies.
It parses traffic-related input using **Lex & Yacc (implemented using Flex & Bison)**, processes rules through a custom **C-based rule engine**, and displays results via a **Node.js backend** and interactive **frontend UI**.

---

## ⚙️ Tech Stack

### 🔹 Core System

* C Programming **Lex & Yacc (implemented using Flex & Bison)**
* Rule Engine Implementation
* File Handling

### 🔹 Backend

* Node.js

### 🔹 Frontend

* HTML5
* Tailwind CSS
* JavaScript

---

## ✨ Key Features

* 🧾 Lexical Analysis using **Flex**
* 🧩 Syntax Parsing using **Bison**
* ⚙️ Custom Rule Engine in C
* 📂 Input & Output File Processing
* 🌐 Web-based Result Visualization
* 🔗 Backend-Frontend Integration

---

## 📁 Project Structure

```
Traffic_Rule_Analyzer/
│
├── backend/
│   ├── lexer.l
│   ├── parser.y
│   ├── main.c
│   ├── rule_engine.c
│   ├── rule_engine.h
│   ├── lex.yy.c
│   ├── parser.tab.c
│   ├── parser.tab.h
│   ├── input.txt
│   └── report.txt
│
├── frontend/
│   ├── index.html
│   ├── result.html
│   ├── analytics_dashboard.html
│   ├── style.css
│   └── script.js
│
├── server.js
├── package.json
└── README.md
```

---

## 🚀 How to Run the Project

### 🔹 Step 1: Navigate to Backend

```bash
cd backend
```

---

### 🔹 Step 2: Generate Lexer & Parser (Optional)

```bash
flex lexer.l        # Optional (if lex.yy.c not already generated)
bison -d parser.y   # Optional (if parser files not already generated)
```

---

### 🔹 Step 3: Compile the Project

```bash
gcc lex.yy.c parser.tab.c main.c rule_engine.c -o traffic.exe
```

---

### 🔹 Step 4: Go Back to Root Directory

```bash
cd ..
```

---

### 🔹 Step 5: Start Backend Server

```bash
node server.js
```

---

### 🔹 Step 6: Open in Browser

```
http://localhost:3000
```

---

## ⚠️ Notes

* Make sure **Flex & Bison (or Win Flex-Bison)** are installed
* Ensure **Node.js** is installed
* Run commands in terminal (VS Code / CMD / PowerShell)


## 📊 Output

* Processes traffic rules from input file
* Generates analyzed report
* Displays results in web interface

---

## 🎯 Learning Outcomes

* Deep understanding of **Compiler Design Lex & Yacc (implemented using Flex & Bison)**
* Backend-Frontend integration
* Real-world problem solving with C
* Building full-stack hybrid systems

---

## 👨‍💻 Author

**Sadman Shakib**
| Aspiring Full Stack Developer | CSE Student

---

## ⭐ Support

If you find this project useful, consider giving it a ⭐ on GitHub!
