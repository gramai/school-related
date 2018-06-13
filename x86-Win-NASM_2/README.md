# x86-Win-NASM
This is a repository containing some of the projects I have worked on during the 
second semester of my first year at the university. All code is 100% written by me.

This code runs with an Assembly x86 emulator. I have used emu8086 for this. You can find and download the 
40 day trial [here](http://www.emu8086.com/)

### Disclaimer  
**This projects and tips are written by me, according to my own understanding. Some of the information found here may be inaccurate and better solutions most likely exist!**

## Projects


| #   | Name                                  | Category        | Link                                             |
| --- | ------------------------------------- | --------------- | ------------------------------------------------ |
| 1   | Sum of two integers (read from UI)    | Numbers         | [Github](./src/Numbers/int_sum.asm)              |
| 2   | Increasing sequence                   | Numbers, Tables | [Github](./src/Numbers/increasing_sequence.asm)  |
| 3   | Number of apparitions                 | Numbers, Tables | [Github](./src/Numbers/number_of_apparitions.asm)|       
| 4   | Binary converter (dec, hex, oct)      | Numbers, Tables | [Github](./src/Numbers/bin_converter.asm)        |
| 5   | Decimal converter (bin, oct, hex)     | Numbers, Tables | [Github](./src/Numbers/dec_converter.asm)        |
| 6   | Hexadecimal converter (bin, dec, oct) | Numbers, Tables | [Github](./src/Numbers/hex_converter.asm)        |
| 7   | Octal converter (bin, dec, hex)       | Numbers, Tables | [Github](./src/Numbers/octal_converter.asm)      |
| 8   | Max Table Element                     | Numbers, Tables | [Github](./src/Tables/max_elem_table.asm)        |
| 9   | Elements on pair positions            | Tables          | [Github](./src/Tables/pair_positions.asm)       |
| 10  | Sum and Product (2 tables)            | Numbers, Tables | [Github](./src/Tables/two_tables.asm)           |
| 11  | Change the case                       | Strings         | [Github](./src/Strings/case_change.asm)          |
| 12  | Print the pattern!                    | Numbers, Tables | [Github](./src/Strings/pattern_print.asm)        |
| 13  | Palindrome                            | Numbers, Tables | [Github](./src/Strings/palindrome.asm)           |
    

# Tips and tricks
Some of the things that I find very useful.

## General tips
- **AX, BX, DX, CX** are _16-bits_ registers and are formed by two parts (each part of _8 bits_): 
  - the "low" part = **AL, BL, DL, CL**
  - the "high" part = **AH, BH, DH, CH**
  - valid operations can be made only using registeres of the **same size!!!** (e.g. AX, BX are compatible but AX, BH are not)
- include "emu8086.inc" at the beginning of every file and use its functions (e.g. print_string, print_num, get_string, scan_num)
- Don't forget to define all functions used at the bottom of every program (e.g if i use print_string, at the bottom of the program should be DEFINE_PRINT_STRING)
- Use AX and DX for number manipulation
- Use CX as counter (it is implicitely used in the LOOPs)
- Use SI, DI for string manipulation or operations involving lists

# Read from user input (console)

### Read a number (integer) from user input
```
call scan_num
```
1. **call scan_num**
- **scan_num** reads the input from user and stores it in **CX**
- you can afterwards use it as you wish (e.g. MOV AX, CX assigns the value of CX to AX)

### Read a string from user input
```
str db "+++++++++++++++",0
MOV DX, 16
LEA DI, str
call get_string
```
1. **str db "+++++++++++++++",0**
- creates the str variable and assigns to it the value "+++++++++++++++". The value is chosen arbitrary, according to what the problem requests. For example, if the problem is about letters (uppercase, lowercase, specific letters etc.), the value of str should be of non-letter type.
2. **MOV DX, 16**
- move to DX the max length of the string that will be read
3. **LEA DI, str** 
- assign to "DI" the address of "str" ( of its first character ) = point "DI" to the first character of "str"
4. **call get_string** 
- the string will be saved beginning with the address pointed by "DI" (in our case, first char of "str"). In this manner, the first char of "str" will have the first char read from input, the second char of "str" will have the second char read from input and so on...


# Print to user output (console)

### Print a number to console:
```
mov AX, 5
call print_num
```
1. **mov AX, 5**
- moves an integer value to the AX register (integer value chosen arbitrary, any other value can be moved, as long as it is 16bits

2. **call print_num**
- **print_num** is an already written function from the "emu8086.inc" library that prints the value of **AX** to the console

### Print a message to console:
```
msg0 db 0dh, 0ah, "Some message",0
LEA SI, msg0
call print_string
```
1. **msg0 db 0dh, 0ah, "Some message",0**
- defines the message and assigns it to a variable
- **msg0** = name of variable where the message will be stored (chosen arbitrary)
- **"db"** = define byte, reserves a byte of memory for the needed variable
- **0dh, 0ah** are the coordinates where the first char of the message will be printed = position (0,0) after what has been already printed (no paddings)
- **",0"**  (at the end of the string) means that the string ENDS there. 

2. **LEA SI, msg0** 
- points SI to msg0 (to the first char of msg0)
- **LEA** = Load Effective Address 

3. **call print_string**
- **"print_string"** is an already written function from the "emu8086.inc" library that prints what is pointed by **SI**

### Print an empty line
```
PUTC 13
PUTC 10
```
# Operations with numbers (integers)

### Add two integers
```
ADD AX, CX
```
1. **ADD AX, CX**
- adds the value of CX to AX, the result is saved in AX
- **ADD CX, AX** is similar, the result will be saved in CX

## Substract two integers
```
SUB AX, CX
```
1. **SUB AX, CX**
- Substracts the value of CX from AX and saves the result to AX
- **SUB CX, AX** substracts the value of AX from CX and saves the result to CX

### Compare two integers (stored in registeres of SAME size!!!)
```
MOV AX, 5
MOV BX, 10
CMP AX, BX
JL add_to_ax
JGE add_to_bx

add_to_ax:
  ADD AX, BX

add_to_bx:
  ADD BX, AX

```
Let's compare two arbitrary integers (e.g. 5 and 10) and add the second integer to the first if the first is smaller and the first integer to the second, if the first is bigger of equal to the second. 
1. **MOV AX, 5;** saves the integer 5 to the register AX
2. **MOV BX, 10;** saves the integer 10 to the register BX
3. **CMP AX,BX;** compares AX to BX
4. **JL add_to_ax;**  **JL** = JUMP IF LESS = jump to add_to_ax if AX is less than BX
5. **JGE add_to_bx;** **JGE** = JUMP IF GREATER OR EQUAL = jump to add_to_bx if AX is greater than BX

- **add_to_ax:**
  - **ADD AX, BX**
  
- **add_to_bx:**
  - **ADD BX, AX**
  
  # Loops
  ### Parse the characters of a string 
  SI points to the first character of the string, string length is stored in CX. (see [example](./src/uppercase_count.asm) ). 
  ```
  str db "abcde",0
  MOV CX, 5
  
  MOV SI, OFFSET str
  
  parse_string:
    ;do something with the characters in here
    INC SI 
    LOOP parse_string
  ```
1. **str db "abcde",0** defines the string "str" as a byte
2. **MOV CX, 5** gives CX the integer value 5
3. **MOV SI, OFFSET str** moves the offset (address) of str (first character) to SI 
4. **parse_string** is the name given by us to the loop, it is set arbitrary.
5. **INC SI** == ADD SI, 1 (INC - increase by one, DEC - decrease by one); 
This is used so that SI will point to the next character
6. **LOOP parse_string** is the end part of the loop, and does the following **two** operations:
- JUMPS to parse_string if CX is greater than 0
- Decreases CX by one

### Parse the elements of a table
```
  arr dw 1,2,3,4,5
  MOV CX, 5

  MOV SI, OFFSET arr 
  parse_table:
    ;do something with the elements here
    ADD SI, 2
    LOOP parse_table
```

1. **arr dw 1,2,3,4,5** defines the table "arr" as a word
2. **MOV CX, 5** gives CX the integer value 5
3. **MOV SI, OFFSET arr** points SI to the first element of arr
4. **parse_table:** name of the loop, choosen arbitrary
5. **ADD SI, 2** this is done so that SI will point to the next element; 2 needs to be added because arr is a **word**
6. **LOOP parse_table** is the end part of the loop, and does the following **two** operations:
- JUMPS to parse_string if CX is greater than 0
- Decreases CX by one
