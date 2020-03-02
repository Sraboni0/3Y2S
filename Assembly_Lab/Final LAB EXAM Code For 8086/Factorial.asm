INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    N DB ?
    sum DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "ENTER INPUT NUMBER: "
    
    MOV AH,1
    INT 21H
    CMP AL,0
    JE ZERO
    SUB AL,48
    INPUT:
        MOV N,AL
        DEC N
        FOR_LOOP:
            CMP N,0
            JE PRNT
            MUL N
            DEC N
            JMP FOR_LOOP
     
     ZERO:
        MOV AL,1
     PRNT:  
        PRINTN
        PRINTN "OUTPUT: "
        ADD AL,48
               
        MOV AH,2
        MOV DL,AL
        INT 21H  
           
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN