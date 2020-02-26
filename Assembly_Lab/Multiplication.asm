INCLUDE 'EMU8086.INC'

.MODEL SMALL
.STACK 100H

.DATA
.CODE
MAIN PROC
    MOV AL,9
    MOV BL,5
    MUL BL
    
    AAM  ;adjust ascii
            
    MOV CH,AH  ;upper part store in ch
    MOV CL,AL
    
    MOV DL,CH ;Move first part of mul to DL register
    ADD DL,48
    MOV AH,2
    INT 21H   
    
    MOV DL,CL
    ADD DL,48
    MOV AH,2
    INT 21H
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN