# Student Record System (C Programming)

A menu-driven console application built in C for managing basic student records. Developed as a first-semester programming project to demonstrate procedural programming, file input/output, structures, and basic CRUD operations.

---

## 📌 Project Overview

This project provides a simple terminal interface to store and manage student information without relying on third-party database engines. Records are persisted locally in a plain text file (`students.txt`) using structured comma-separated formatting.

---

## 🚀 Features

- **Add Student Record:** Enter student Roll Number, Name, and Marks.
- **Display Records:** Tabular view of all registered students with record count.
- **Search Record:** Fast search by Roll Number.
- **Delete Record:** Remove an existing student entry using temporary file swap.
- **Persistent Storage:** Data is retained across sessions in `students.txt`.

---

## 🛠️ Technical Details

- **Language:** C (Standard C99 / C11)
- **Compiler:** GCC (MinGW-w64 on Windows / Linux gcc)
- **Concepts Implemented:**
  - `struct` definitions
  - File handling (`fopen`, `fprintf`, `fscanf`, `fclose`, `remove`, `rename`)
  - Control flow (`switch-case`, `while` loops)
  - String manipulation and formatted I/O

---

## 💻 How to Compile and Run

### 1. Clone the repository
```bash
git clone https://github.com/anu20-g/student-management-system.git
cd student-management-system
```

### 2. Compile with GCC
```bash
gcc -o student_system main.c
```

### 3. Run the executable

**On Windows:**
```bash
.\student_system.exe
```

**On Linux / macOS:**
```bash
./student_system
```

---

## 📂 Project Structure

```text
student-management-system/
├── main.c           # Complete source code
├── README.md        # Documentation and run instructions
└── .gitignore       # Ignores compiled binaries and runtime text files
```

---

## 📄 License
Open source under the [MIT License](LICENSE).
