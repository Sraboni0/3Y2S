INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    MSG DB "Enter a string: $"
    STR DB 80 DUP (?)
    COUNT DB 122 DUP(0)
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,MSG
    INT 21H
    
    MOV SI,0 ;COUNTER
    
    MOV AH,1
    INPUT:
        INT 21H
        CMP AL,0DH
        JZ NEXT
        MOV STR[SI],AL
        MOV BX,SI
        
        MOV DL,STR[SI]
        MOV DH,0
        MOV SI,DX
        
        INC COUNT[SI]
        MOV SI,BX
        INC SI
        JMP INPUT
    NEXT:
        PRINTN
        
        MOV BX,0
        MOV AH,2 
        
        PRINTN "OUTPUT STRING: "
        OUTPUT:
             MOV SI,BX
             MOV CL,COUNT[SI]
             REPEAT:
                 CMP CL,0
                 JZ NR
                 MOV DX,BX
                 INT 21H
                 DEC CL
                 JMP REPEAT
            NR:
                CMP BX,126 ;CHECK IF BX IS 127
                JZ EXIT
                INC BX
                JMP OUTPUT        
    EXIT:
       
        MOV AH , 2              ; SINGLE CHARACTER OUTPUT FUNCTION
        MOV DL , 0DH            ; CARRIAGE RETURN
        INT 21H                                  
        MOV DL, 0AH             ; LINE FEED
        INT 21H  
        ;OUTPUT DECENDING ORDER
        
        PRINT "DECENDING ORDER: "
        MOV BX,122
        MOV AH,2
        OUT2:
            MOV SI,BX
            MOV CL,COUNT[SI]
            REPT:
                CMP CL,0
                JZ NL
                MOV DL,BX
                INT 21H
                DEC CL
                JMP REPT
           NL:
            CMP BX,0
            JZ EXIT1
            DEC BX
            JMP OUT2
       EXIT1:
        PRINTN  
        
       MOV AH,41H
       INT 21H
    MAIN ENDP
END MAIN
