;Read a string from user input and check if it is palindrome

;French
;Lire une chaîne à partir du clavier et tester si elle est un palindrome

ORG 100H

include "emu8086.inc"

.data
:

len db "000",0
str db "+++++++++++++++",0

msg0 db 0dh, 0ah, "Insert string length ( max 15 characters ): ",0
msg1 db 0dh, 0ah, "Insert string: ",0      
msgpal db 0dh, 0ah, "Palindrome ",0
msgnpal db 0dh, 0ah, "Not Palindrome ",0

msgstop DB 0dh, 0ah, "Stopping... ",0


.code

LEA SI, msg0
call print_string

call scan_num

LEA SI, msg1
call print_string

MOV DX, 16
LEA DI, str
call get_string

MOV SI, OFFSET str ; points to the first character of the string
MOV DI, OFFSET str ;same as SI for the moment

MOV AX, CX ; backs up the value of CX
DEC CX 
to_finish: ; parses DI until it reaches on the final element
    INC DI
    LOOP to_finish
    
SHR AX, 1 ; this is same as AX = AX / 2 (which is invalid in nasm)
MOV CX, AX ; CX holds half of the length of the string (only needs to parse the first half of the string)
           ; in order to verify if it is palindrome or not
compare:
    MOV AX, [SI] ;move the value of the element from the beginning to AX
    MOV DX, [DI] ; move the value of the element from the end to DX
    CMP DL, AL ; compares the "low" part of the DX and AX registeres, to check if the values match
    JNE not_palindrome ; if the values differ, the string is not 
                       ;palindrome -> jumps to not_palindrome           
    DEC DI
    INC SI
    LOOP compare
LEA SI, msgpal; if the program hasn't jumped to not_palindrome, it means that the string is palindrome
call print_string
JMP stop

not_palindrome:
    LEA SI, msgnpal
    call print_string
    JMP stop
stop:  
LEA SI, msgstop
call print_string

MOV AH, 0
INT 16h
RET
    
                              
DEFINE_GET_STRING          
DEFINE_PRINT_STRING
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_SCAN_NUM

END