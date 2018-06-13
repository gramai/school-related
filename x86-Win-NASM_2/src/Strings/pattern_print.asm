;English
;Using the LOOP instructions, find patterns and
;print the following string to the screen

;abcccbcccabcccbccc

;French
;En utilisant les instructions LOOP, trouver
;les motifs et afficher la chaîne suivante: 


org 100h
include "emu8086.inc"

.data
:
to_print db "++++++++++++++++++",0 ; the string will be constructed here

.code
MOV SI, OFFSET to_print ; SI will point to the first char of the string to_print
                        ; to be able to modify the contents of the string 
MOV CX,1 ; the pattern has to be repeated TWICE
         ; after running the loop ONCE, CX == 1, so the LOOP is repeated
         ; after the second run, CX == 0, so it exits the loop
double:
    MOV [SI],61h ; the current character will receive the value 61h = 'a'
    INC SI ; passes to the next character
    MOV [SI], 62h ; 62h = 'b'
    MOV AX, CX ; AX stores the value of CX as backup
    MOV CX, 3 ; the loop triple has to be run 3 times. 
    triple: ; replaces the next 3 characters of the string with the value 63h
        INC SI
        MOV [SI], 63h ; 63h = 'c'
        LOOP triple
    INC SI; passes to the next character
    MOV [SI], 62h 
    MOV CX, 3
    triple_2:
        INC SI
        MOV [SI], 63h
        LOOP triple_2
    INC SI
    MOV CX, AX; CX == 1 during the first run, 0 during the second 
    LOOP double

; print to_print
MOV [SI],0    
MOV SI, OFFSET to_print 
call print_string

stop:  
msgstop db 0dh, 0ah, "Stopping...",0
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






