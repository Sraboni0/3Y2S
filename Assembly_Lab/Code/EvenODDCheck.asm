INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    N DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    PRINTN "Enter a number from 1-9:"
    MOV AH,1
    INT 21H
    SUB AL,48
    MOV N,AL
    
    MOV BX,2 ;DIVISOR 2 FOR ODD/EVEN CHECK
    DIV BX ;HERE DX:AX=AX/BX -->DX= REMAINDER; AX=RESULT
    
    PRINTN
    CMP DX,0
    JE EVEN
        PRINTN "Given Number is ODD"
    JMP END_CMP
    EVEN:
        PRINTN "Given Number is EVEN"
    END_CMP:    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN