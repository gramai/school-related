;English
;Find the number of increasing sequences of a table and print them.

;French
;Trouvez le nombre de séquences croissantes à partir d'un tableau et imprimez-les.


org 100h
include "emu8086.inc"
.data
:
arr dw 2,3,5,1,7,2,5,9,10,1        
; Will print:
;2,3,5
;1,7
;2,5,9,10
;1

msgss db 0dh, 0ah, "Increasing seq. stop ", 0 ; marks the end of an increasing sequence
msgstop db 0dh, 0ah, "Stopping...",0
.code

MOV CX, 10 ; length of the table

LEA SI, arr ; first element of the table
parse_array:
    MOV AX, [SI] ;saves the value of the current element to AX
                 ;the value of the next element will be saved in BX   
    ADD SI,2
    MOV BX, [SI] 
    CMP AX, BX ;compare the current element with the last element
    JLE print ;if the last element is less or equal to the current element, it is an increasing sequence
              ; and the last element will be printed
    JG not_print
    continue:
        loop parse_array
JMP stop        
print:
    call print_num ;prints the last number               
    MOV AX, BX; the current number will be saved in AX
    JMP continue                
        
not_print:
    call print_num ; prints the last number                    
    MOV DI, SI ; backs up the address of the current element
    
    LEA SI, msgss ;prints the increasing sequence stop message
    call print_string
                      
    PUTC 10
    PUTC 13
                      
    MOV SI, DI
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