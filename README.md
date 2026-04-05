# 🚦 Traffic Rule Analyzer

A compiler-based system built using **Lex & Yacc**, designed to analyze and validate traffic rules with an integrated **web-based interface** for visualization.

---

## 🧠 Project Overview

The **Traffic Rule Analyzer** is a hybrid system combining compiler design concepts with modern web technologies.
It parses traffic-related input using **Lex & Yacc**, processes rules through a custom **C-based rule engine**, and displays results via a **Node.js backend** and interactive **frontend UI**.

---

## ⚙️ Tech Stack

### 🔹 Core System

* C Programming (Lex & Yacc)
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

* 🧾 Lexical Analysis using **Lex**
* 🧩 Syntax Parsing using **Yacc**
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

## 🚀 How to Run

### 🔹 Step 1: Compile (Lex & Yacc)

```bash
lex lexer.l
yacc -d parser.y
gcc lex.yy.c parser.tab.c main.c rule_engine.c -o analyzer
```

---

### 🔹 Step 2: Run Analyzer

```bash
./analyzer
```

---

### 🔹 Step 3: Start Backend Server

```bash
node server.js
```

---

### 🔹 Step 4: Open Frontend

Open `index.html` in your browser.

---

## 📊 Output

* Processes traffic rules from input file
* Generates analyzed report
* Displays results in web interface

---

## 🎯 Learning Outcomes

* Deep understanding of **Compiler Design (Lex & Yacc)**
* Backend-Frontend integration
* Real-world problem solving with C
* Building full-stack hybrid systems

---

## 👨‍💻 Author

**Sadman Shakib**
Aspiring Full Stack Developer | CSE Student

---

## ⭐ Support

If you find this project useful, consider giving it a ⭐ on GitHub!
