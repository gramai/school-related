
;English
;Find the sum and the product of the elements of the two tables

;French
;Trouver la somme et le produit de deux tableaux.

org 100h
include "emu8086.inc"
.data
:
arr1 dw 1,3,5 ;first table
arr2 dw 2,4,6 ;second table
msgstop db 0dh, 0ah, "Stopping...",0
msgsum db 0dh, 0ah, "Sum is: ",0
msgprod db 0dh, 0ah, "Product is: ",0

.code

MOV CX, 3

LEA SI, arr1
LEA DI, arr2
   
MOV AX, 0   
sum:
    ADD AX, [SI]
    ADD AX, [DI]
    ADD SI, 2 ;passes to the next element
    ADD DI, 2 ;passes to the next element
    LOOP sum
    
LEA SI, msgsum
call print_string

call print_num




MOV CX, 3

LEA SI, arr1
LEA DI, arr2

MOV AX, 1   
prod:
    MUL [SI] ; multiply AX with the value pointed by SI
    MUL [DI] ; multiply AX with the value pointed by DI
    ADD SI, 2 ;passes to the next element
    ADD DI, 2 ;passes to the next element
    LOOP prod
    
LEA SI, msgprod
call print_string

call print_num
       





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