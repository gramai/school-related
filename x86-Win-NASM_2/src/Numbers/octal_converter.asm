;English
;Read an octal number and convert it in binary, decimal and hexadecimal

;French
;Lisez un nombre octal et vous devez le convertir en décimal, binaire et hexadécimal.

;Similar to bin_converter (find explanation there)


ORG 100h
include "emu8086.inc"

.data
:
l db "00",0
s1 db "0000",0
s2 db "00",0  
s_binary db "000000000",0     
s_octal db "GGGGGGGG", 0
msg0 DB 0dh, 0ah, "Insert octal length (min 1, max 3) : ", 0
msg1 DB 0dh, 0ah, "Insert octal : ", 0
msg2 DB 0dh, 0ah, "1=to binary, 2=to decimal, 3=to hexadecimal ", 0
     
msgbin DB 0dh, 0ah, "Binary= ", 0   
msgdec DB 0dh, 0ah, "Decimal= ",0   
msghex DB 0dh, 0ah, "Hexadecimal= ",0
msgtest DB 0dh, 0ah, "Testing... ",0
msgstop DB 0dh, 0ah, "Stopping... ",0      


.code
LEA SI, msg0
call print_string
 
MOV DX, 2
LEA DI, l
call get_string
               
LEA SI, msg1
call print_string
               
MOV DX, 4
LEA DI, s1
call get_string
                 
LEA SI, msg2
call print_string
               
MOV DX, 2
LEA DI, s2
call get_string
        
MOV DI, OFFSET s2
MOV AX, [DI]
SUB AX, 30h
CMP AX, 2
JL binary
JE decimal
JG hexa

binary:
    MOV SI, OFFSET s_binary
    MOV DI, OFFSET l
    SUB [DI], 30H
    CMP [DI], 1
    JE inc_inc
    CMP [DI], 2
    JE inc_inc_2
    continue_binary:        
        MOV DI, OFFSET s1  
        DEC DI ; I do this to be able to loop INC DI
        MOV AX, 0
        complete_DI:
            INC DI
            INC AX  
            CMP AX, 3
            JG print_binary  
            
            CMP [DI], 30h
            JE zero
            
            CMP [DI], 31h
            JE one
            
            CMP [DI], 32h
            JE two
            
            CMP [DI], 33h
            JE three
            
            CMP [DI], 34h
            JE four
            
            CMP [DI], 35h
            JE five
            
            CMP [DI], 36h
            JE six
            
            CMP [DI], 37h
            JE seven
            
            JMP print_binary           

inc_inc:
    INC SI
    INC SI
    INC SI
    INC SI
    INC SI
    INC SI
    JMP continue_binary 
    
inc_inc_2:
    INC SI
    INC SI
    INC SI
    JMP continue_binary                
 zero:
    INC SI
    INC SI
    INC SI
    JMP complete_DI    
                
 one:
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI   
    JMP complete_DI     
                
 two:
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
        
    JMP complete_DI     
                
 three:   
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    JMP complete_DI    
   
 four:
    MOV [SI], 31H
    INC SI
    INC SI
    INC SI
    JMP complete_DI    
                    
 five:
    MOV [SI], 31H
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    JMP complete_DI    
            
 six:
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    JMP complete_DI                    

 seven:
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    JMP complete_DI    
                 
print_binary:        
    CMP DH, 1
    JE continue_decimal
    JG continue_hexa_0
    
    LEA SI, msgbin
    call print_string

    
    MOV SI, OFFSET s_binary
    call print_string    
    
    JMP stop  
    
decimal:
    MOV DH, 1 
    JMP binary
    continue_decimal:
    MOV AX, 0
    MOV CX, 8
    MOV BX, 1
    pow_8:
        SHL BX, 1
        LOOP pow_8
    MOV CX, 9
    MOV SI, OFFSET s_binary
    
    PUTC 13
    PUTC 10
    CALL print_string
    PUTC 13
    PUTC 10
    
    get_dec:
        CMP [SI], 31H
        JE go_add
        continue_get_dec:
            INC SI
            SHR BX,1
            LOOP get_dec
    JMP print_decimal
go_add:
    ADD AX, BX
    JMP continue_get_dec
                     
print_decimal:        
    LEA SI, msgdec
    call print_string
    
    call print_num
    
    JMP stop      
    
    
           
hexa:
    MOV DH, 2 
    JMP binary
    continue_hexa_0:
    
    
    MOV SI, OFFSET s_binary
          
    PUTC 13
    PUTC 10
    call print_string
    PUTC 13
    putc 10         
          
    MOV CX,8
    incr_hexa:
        INC SI
        LOOP incr_hexa
    
    MOV BL, 1
    MOV AX, 0
    MOV CX, 9
        
    parser_hexa:       
        JCXZ stop_hexa
        CMP [SI], 31h
        JL ok0_hexa
        JE ok1_hexa   
                     
                  
    
ok0_hexa:
    SHL BL, 1 
    DEC SI
    DEC CX    
        
    CMP BL, 16
    JGE redo_hexa
    JMP parser_hexa    
    
ok1_hexa: 
    ADD AL, BL     
    
    SHL BL, 1
    DEC SI
    DEC CX   
    
    CMP BL, 16
    JGE redo_hexa
    JMP parser_hexa 

redo_hexa:
        MOV BL,1      
        
        MOV DI, SI
        MOV SI, OFFSET s_octal       
        looper_hexa:
            CMP [SI], 47h
            JE replace_hexa      
            JL cont_redo_hexa
        continue_hexa:
            MOV BH, 0
            MOV BL, CH
            MOV CX, BX 
            MOV BL, 1                       
            MOV SI, DI
            MOV AX, 0 
            JMP parser_hexa
        
        continue_hexa_not_special:           
            MOV BL, 1                       
            MOV SI, DI
            MOV AX, 0
            JMP parser_hexa
        
replace_hexa:
    CMP AX, 9
    JG greater
    JLE rh_continue            ;check if number > 9           
rh_continue:
    ADD AX, 30h
    MOV [SI], AX
    JMP continue_hexa_not_special   

greater:  
    MOV BX, CX
    MOV CH, BL
    MOV BX, AX
    MOV AX, 0
    MOV CL, 0
    search_hex: 
        INC CL 
        DEC BX
        CMP BX, 9
        JG search_hex
        JLE done_search_hex

done_search_hex:
;for CX, 1 -> A, 2 -> B, 3->C, 4-> D, 5-> E, 6-> F
    CMP CL, 1
    JE A_found
    JG B_check
    
A_found:          
    MOV AX, 'A'
    MOV [SI], AX
    JMP continue_hexa
B_check:
    CMP CL, 2
    JE B_found
    JG C_check
    
B_found:        
    MOV AX, 'B'
    MOV [SI], AX
    JMP continue_hexa
C_check:
    CMP CL, 3
    JE C_found
    JG D_check
    
C_found:        
    MOV AX, 'C'
    MOV [SI], AX
    JMP continue_hexa
D_check:
    CMP CL, 4
    JE D_found
    JG E_check
        
D_found:        
    MOV AX, 'D'
    MOV [SI], AX
    JMP continue_hexa
E_check:
    CMP CL, 5
    JE E_found
    JG F_check
        
E_found:        
    MOV AX, 'E'
    MOV [SI], AX
    JMP continue_hexa
F_check:
    CMP CL, 6
    JE F_found

F_found:    
    MOV AX, 'F'
    MOV [SI], AX
    JMP continue_hexa
    
     
cont_redo_hexa:
    INC SI 
    JMP looper_hexa
    
stop_hexa:  
    LEA SI, msghex
    call print_string         
    MOV CX, 8
    MOV SI, OFFSET s_octal
    switcher_hexa:
        CMP [SI], 47H
        JNE go_go_hexa
        JE stop_stop_hexa
        cont_hexa:
            LOOP switcher_hexa
    MOV CX, 8
    printer_hexa:
        JCXZ continue_gtp_hexa
        CMP [SI], 47H
        JL gtp_hexa
    continue_gtp_hexa:          
        LEA SI, msgstop
        call print_string         
                         
        PUTC 10
        PUTC 13     
                      
        MOV AH, 0
        INT 16h
        RET

gtp_hexa:                     
    CALL print_string
    DEC SI
    DEC CX
    JMP printer_hexa
go_go_hexa:
    INC SI  
    JMP cont_hexa
stop_stop_hexa:
    DEC SI
    JMP printer_hexa
clean_up_hexa:
    CALL print_num     
    MOV AX, 0
    JMP gtp_hexa



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