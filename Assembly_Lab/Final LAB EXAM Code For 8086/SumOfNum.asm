INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    N DB ?
    SUM DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "Enter a number from 1-9:"
    MOV AH,1
    INT 21H
    SUB AL,48
    
    CMP AL,0
    JE ZERO
        MOV N,AL
        DEC N
        FOR_LOOP:
            CMP N,0
            JE ZERO
            ADD AL,N
            DEC N
            JMP FOR_LOOP
        ZERO:
        
        PRINTN
        PRINTN "SUM OF NUMBER IS: "
        
        MOV SUM,AL        
        AAM
        MOV CH,AH
        MOV CL,AL
        
        ;1st part of sum print
        MOV DL,CH
        ADD DL,48
        MOV AH,2
        INT 21H
        ;2nd part of sum print
        MOV DL,CL
        ADD DL,48
        MOV AH,2
        INT 21H
        
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN