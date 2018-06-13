;English
;Read a string and print it changing the
;case of every letter

;French
;Lire une chaîne et l'afficher sur l'écran
;changeant la casse des lettres.

org 100h
include "emu8086.inc" 

.data
:
msg0 db 0dh, 0ah, "Insert string length (max 15)",0
msg1 db 0dh, 0ah, "Insert string ",0
msgstop db 0dh, 0ah, "Stopping...",0
str db "+++++++++++++++",0 
len db "+++",0 ;

.code

LEA SI, msg0 
call print_string

call scan_num 

LEA SI, msg1
call print_string

MOV DX, 16 
LEA DI, str 
call get_string
    
MOV SI, OFFSET str            
parse_string:
    CMP [SI], 5Bh ;checks if the character is larger than Z = 5Ah
    JL to_lower ; if it is less than [ = 5Bh -> it is uppercase 
    JG to_upper ; if it is greater than [ -> it is lowercase       
    continue: ; to_lower and to_upper jump (JMP) to continue 
        INC SI ; increases the address number held in SI, passing to the next character
        LOOP parse_string ;loops parse_string until CX gets to 0            

PUTC 13 
PUTC 10 

MOV SI,OFFSET str 
call print_string 

JMP stop
to_upper:
    SUB [SI],32 ; substracts 32 from the value pointed by SI, that is [SI] = [SI] - 32
    JMP continue; this turns the lowercase letter to uppercase letter

to_lower:
    ADD [SI],32 ; adds 32
    JMP continue

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




