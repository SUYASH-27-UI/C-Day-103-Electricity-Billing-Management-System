# C-Day-103-Electricity-Billing-Management-System
# C Day 103 - Electricity Billing Management System

## Description
A menu-driven electricity billing application developed in C. It calculates customer bills based on electricity consumption and stores billing records in a text file.

## Features
- Generate electricity bills
- Calculate charges using unit-based rates
- Add a fixed charge
- Display all customer bills
- Search bills using Customer ID
- Save records permanently

## Billing Rules
- First 100 units: Rs. 3 per unit
- Next 100 units: Rs. 5 per unit
- Above 200 units: Rs. 7 per unit
- Fixed charge: Rs. 50

## Files
- `electricity.c` - Main C program
- `bills.txt` - Sample billing records

## Requirements
- GCC compiler

## How to Compile
```bash
gcc electricity.c -o electricity
```

## How to Run
On Windows:
```bash
electricity.exe
```

Keep `bills.txt` in the same folder as the program.

## Concepts Used
- Structures
- Functions
- File handling
- Conditional statements
- Searching records

## Project Type
Intermediate C Project

## Author
Suyash Surve
