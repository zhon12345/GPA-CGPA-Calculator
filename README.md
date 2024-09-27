# GPA/CGPA Calculator

This project is an assignment for the **AACS1074 Programming Concepts and Design I** course. The goal is to create a GPA/CGPA calculator for Kolej Pasar, helping students and staff easily compute academic scores.

## Features

-   Staff Portal
    -   Secure login system for staff members.
    -   Calculate GPA for individual semesters based on course grades and credit hours.
    -   Calculate the cumulative CGPA across all semesters.
-   Student Portal
    -   Secure login system for students.
    -   View GPA for each individual semesters.
    -   View overall CGPA for across all semesters.

## Admin Credentials

-   **Username:** admin
-   **Password:** admin123!

## Run Locally

Clone the project

```bash
  git clone https://github.com/zhon12345/GPA-CGPA-Calculator.git
```

Go to the project directory

```bash
  cd GPA-CGPA-Calculator
```

Compile `main.c`

```bash
  gcc -o main main.c
```

Start the program

```bash
  ./main
```

## Appendix

-   **Setting up MinGW-w64 via MSYS2**:

    1. Download and install [MSYS2](https://www.msys2.org/).

    2. Open the MSYS2 terminal and run the following command:

    ```bash
      $ pacman -S mingw-w64-ucrt-x86_64-gcc
    ```

-   **Online compilers or an IDEs:**

    -   Online compilers: [Replit](https://replit.com/), [OnlineGDB](https://www.onlinegdb.com/)

    -   IDEs: [Visual Studio](https://visualstudio.microsoft.com/downloads/)