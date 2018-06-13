;English
;Find the number of occurences of each element of the table

;French
;Trouvez le nombre d'occurrences de chaque élément appartenant à un tableau.

org 100h
include "emu8086.inc"
.data
:
arr dw 2,3,5,1,7,2,5,9,10,1        
; This will print
;2 2
;3 1
;5 2
;1 2
;7 1
;9 1
;10 1
; -> 2 appears 2 times
; -> 3 appears once etc...
msgstop db 0dh, 0ah, "Stopping...",0
.code

MOV CX, 10

;there will be a nested loop (also called loop in the loop) that will parse all elements
; beginning from a certain element

LEA SI, arr ;SI will point to the beginning of the table
parse_array:
    MOV AX, [SI] ;AX holds the current element of the table
    CMP AX, '7E' ;checks if AX has been replaces or not '7E' == '~'
    JE pass ; if it has been replaced, passes to the next element
    MOV [SI], '7E' ; replace current element (to mark that it has been counted)
    MOV DI, SI  ; DI will point to the current element 
    MOV BX, CX ; backs up the value of CX 
       
    ADD CX, 10 ; CX will be used to parse the rest of the elements 
    SUB CX, BX ; CX holds now the number of times SI has to increase by 2, in order
               ;  to reach the end of the table 
    MOV DX, 1  ; numbers of apparitions of a 
               ;certain element ( is set to 1 because one element has already been replaced on line 20 )    
    double_parse: ;the nested loop
        ADD DI,2 ;passes to the next element
        CMP AX, [DI]; checks if the element pointed by DI is equal to the already replaced element
        JE incr ; if it is equal, the number of apparitions increases
        continue_dp: ;else, the parse continues 
            LOOP double_parse
            
    call print_num ;prints the element whose apparitions have been counted
    MOV AX, DX ;moves the number of apparitions of the number to AX, in order to print it with print_num
    call print_num ;prints the number of apparitions
    PUTC 13
    PUTC 10
       
    MOV CX, BX ;recovers the value of CX
    pass:
        ADD SI, 2
        LOOP parse_array    
JMP stop          
incr:
    INC DX 
    MOV [DI], '7E'
    JMP continue_dp       
    
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