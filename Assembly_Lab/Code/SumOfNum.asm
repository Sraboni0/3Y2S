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
    
        
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN