# CS 210 Project: Corner Grocer
**Author:** John Distel  
**Course:** CS 210 - Programming Languages  

## Project Summary
This project reads a grocery list from a text file, counts how often each item appears, and displays that data in multiple ways. It helps users quickly identify purchase frequency, showcasing file input/output and map-based data structures in C++.

------------------------------------------------------------
Build and Run
------------------------------------------------------------
1. Unzip to your preferred location.
2. Open the Visual Studio solution (CornerGrocer.sln).
3. Ensure the following files are included in the project: CornerGrocer.cpp (main.cpp) and CS210_Project_Three_Input_File.txt
4. Build the project (Build → Rebuild Solution).
5. Run the program (Debug → Start Without Debugging).
6. Verify that "frequency.dat" is created in the project folder.


## How to Use
- Choose from the menu options:
     1. Search for the frequency of a specific item
     2. Print all items and their frequencies
     3. Print a histogram of all item frequencies
     4. Exit the program
- When prompted for an item name, type the name and press Enter.
- To view all data or the histogram, select options 2 or 3.
- To quit, select option 4 from the main menu.
- Review the "frequency.dat" file, which stores the same frequency data in text format for backup purposes.

## Notes
- The input file must be located in the same directory as the program.
- The program is case-insensitive for item lookup.
- Input validation prevents invalid menu selections.
- Exception handling is included for file reading and writing errors.
- The program was written using ISO C++17 standards.

## Reflection
- **What I did well:** I implemented efficient use of `std::map` and file I/O while keeping the program readable and modular. - **Enhancements:** I’d add input validation and case-insensitive searches for better usability.  
- **Challenges:** Getting the file writing logic to behave consistently required testing and careful stream management.  
- **Transferable skills:** Improved understanding of classes, I/O operations, and data structures.  
- **Maintainability:** Structured code into logical functions with clear comments to ensure readability and adaptability.
