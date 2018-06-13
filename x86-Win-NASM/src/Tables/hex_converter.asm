;English
;Read a hexadecimal number and convert it in binary, decimal and octal

;French
;Lisez un nombre hexadécimal et vous devez le convertir en binaire, décimal et octal.

;Similar to bin_converter (find explanation there)

ORG 100h
include "emu8086.inc"

.data
:
l db "00",0
s1 db "000",0
s2 db "00",0  
s_binary db "00000000",0     
s_octal db "GGGGGGGG", 0
msg0 DB 0dh, 0ah, "Insert hexadecimal length (min 1, max 2) : ", 0
msg1 DB 0dh, 0ah, "Insert hexadecimal : ", 0
msg2 DB 0dh, 0ah, "1=b, 2=d, 3=o ", 0


msgbin DB 0dh, 0ah, "Binary= ", 0   
msgdec DB 0dh, 0ah, "Decimal= ",0   
msgoct DB 0dh, 0ah, "Octal= ",0
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
               
MOV DX, 3
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
JG octal
                     
binary:
    MOV SI, OFFSET s_binary
    MOV DI, OFFSET l
    SUB [DI], 30H
    CMP [DI], 1
    JE inc_inc
    continue_binary:        
        MOV DI, OFFSET s1  
        DEC DI ; I do this to be able to loop INC DI
        MOV AX, 0
        complete_DI:
            INC DI
            INC AX  
            CMP AX, 2
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
            
            CMP [DI], 38h
            JE eight
            
            CMP [DI], 39h
            JE nine
            
            CMP [DI], 41h
            JE A
            
            CMP [DI], 42h
            JE B
            
            CMP [DI], 43h
            JE C
            
            CMP [DI], 44h
            JE D
            
            CMP [DI], 45h
            JE E
            
            CMP [DI], 46h
            JE F 
            JMP print_binary           

inc_inc:
    INC SI
    INC SI
    INC SI
    INC SI
    JMP continue_binary            
 zero:
    INC SI
    INC SI
    INC SI
    INC SI
    JMP complete_DI    
                
 one:
    INC SI
    INC SI
    INC SI       
    MOV [SI], 31H
    INC SI   
    JMP complete_DI     
                
 two:
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
        
    JMP complete_DI     
                
 three:   
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    JMP complete_DI    
   
 four:
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    INC SI
    JMP complete_DI    
                    
 five:
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    JMP complete_DI    
            
 six:
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    JMP complete_DI                    

 seven:
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    JMP complete_DI    
                
 eight:
    MOV [SI], 31H   
    INC SI
    INC SI
    INC SI
    INC SI 
    JMP complete_DI    
                
 nine:
    MOV [SI], 31H   
    INC SI
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI 
    JMP complete_DI    
                
 A:
    MOV [SI], 31H   
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI 
    JMP complete_DI    
                
 B:
    MOV [SI], 31H   
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI 
    JMP complete_DI    
                
 C:
    MOV [SI], 31H   
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    INC SI 
    JMP complete_DI    
                
 D:
    MOV [SI], 31H   
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI
    MOV [SI], 31H
    INC SI 
    JMP complete_DI    
                
 E:
    MOV [SI], 31H   
    INC SI
    MOV [SI], 31H
    INC SI
    MOV [SI], 31H
    INC SI
    INC SI 
    JMP complete_DI    
                
 F:
    MOV [SI], 31H   
    INC SI
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
    JG continue_octal
    
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
    MOV CX, 7
    MOV BX, 1
    pow_8:
        SHL BX, 1
        LOOP pow_8
    MOV CX, 8
    MOV SI, OFFSET s_binary
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
    
  
    
octal:
    MOV DH, 2
    JMP binary
    continue_octal: 
        MOV AX, 0
        MOV SI, OFFSET s_binary
        MOV CX, 8
        out_0:
            CMP [SI], 30H
            JE zero_freeze 
            JG stop_freeze
            continue_out_0:
                LOOP out_0
        stop_freeze:  
            DEC CX
            incr_octal:
                INC SI
                LOOP incr_octal
            
            MOV BL, 1
            MOV AX, 0
            MOV CX, 8
                
            parser_octal:       
                JCXZ stop_octal            
                CMP [SI], 31h
                JL ok0_octal
                JE ok1_octal 
                      

zero_freeze:
    INC SI
    JMP continue_out_0
        
ok0_octal:
    SHL BL, 1 
    DEC SI
    DEC CX    
        
    CMP BL, 8
    JGE redo
    JMP parser_octal    
    
ok1_octal: 
    ADD AL, BL     
    
    SHL BL, 1
    DEC SI
    DEC CX   
    
    CMP BL, 8
    JGE redo
    JMP parser_octal 

redo:
        MOV BL,1      
        
        MOV DI, SI
        MOV SI, OFFSET s_octal       
        looper:
            CMP [SI], 47h
            JE replace      
            JL cont_redo
        continue:                        
            MOV SI, DI
            MOV AX, 0
            
            JMP parser_octal                
        
replace:           
    ADD AX, 30h
    MOV [SI], AX
    JMP continue   
cont_redo:
    INC SI 
    JMP looper
    
stop_octal:     
    LEA SI, msgoct
    call print_string         
    MOV CX, 8
    MOV SI, OFFSET s_octal
    switcher:
        CMP [SI], 47H
        JNE go_go
        JE stop_stop
        cont:
            LOOP switcher
    MOV CX, 8
    printer:
        JCXZ continue_gtp
        CMP [SI], 47h
        JMP gtp
    continue_gtp:          
        LEA SI, msgstop
        call print_string         
                         
        PUTC 10
        PUTC 13     
              
        MOV AH, 0
        INT 16h
        RET

gtp:                     
    CMP AX, 0
    JG clean_up
    CALL print_string
    DEC SI
    DEC CX
    JMP printer
go_go:
    INC SI  
    JMP cont
stop_stop:
    DEC SI
    JMP printer
clean_up:
    CALL print_num     
    MOV AX, 0
    JMP gtp       
       
       
       
       
       
       
        
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