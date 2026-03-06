# Employee Payroll System

A simple **C++ program** that calculates and displays **gross pay** for employees based on their hours worked and pay rate. The program also creates a backup of employee payroll data in a text file.

---

## Features

- Prompts the user to input:
  - Hours worked for each employee
  - Pay rate for each employee
- Validates inputs:
  - Hours must be positive
  - Pay rate must be between **$20.00 and $29.00**
- Calculates **gross pay**, including **overtime** (1.5× pay rate for hours over 40)
- Displays formatted payroll information in the console
- Saves a backup file (`PayrollDataBackup.txt`) with employee ID, hours, and pay rate

---

## Technologies Used

- C++ Standard Library:
  - `iostream` for input/output
  - `iomanip` for formatting output
  - `fstream` for file operations
- Arrays for storing employee data
- Functions for modular and organized code

---

## How to Use

1. Clone the repository:
   ```bash
   git clone <repository_url>
2. g++ PayrollSystem.cpp -o PayrollSystem
3. ./PayrollSystem
4. Enter hours worked and pay rate for each employee when prompted.
5. View the formatted payroll output in the console.
6. Check the PayrollDataBackup.txt file for a backup of all entered data.
   
