INCLUDE 'EMU8086.INC'
.MODEL SMALL
.DATA
    EVEN DB 10 DUP (?)
    ODD DB 10 DUP (?)
    EVEN_SIZE DB ?
    ODD_SIZE DB ?
    POS DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV SI,0
    MOV BX,0
    MOV POS,48
READ:
    MOV AH,1
    INT 21H
    CMP AL,13
    JE WRITE
    
    INC POS  

    SUB AL,'0'
    AND AL,1
    CMP AL,1
    JE ODD_NUMBER          
        MOV AL,POS  
        MOV EVEN[SI],AL 
        INC SI      
        INC EVEN_SIZE
        JMP READ
    ODD_NUMBER:
        MOV AL,POS
        MOV ODD[BX],AL 
        INC BX   
        INC ODD_SIZE
        JMP READ

WRITE:     
    CALL NEWLINE
     
    MOV ODD[BX],'$'
    MOV EVEN[SI],'$'
    PRINT 'EVEN NUMBER POSITION : '
    CMP  EVEN_SIZE,0
    JE EVEN_ZERO
    
    LEA DX,EVEN
    MOV AH,9
    INT 21H
    JMP ODD_CHECK
EVEN_ZERO:
    PRINT "Not Found"
    
ODD_CHECK:   
    CALL NEWLINE
    PRINT "ODD NUMBER POSITION : "
    CMP ODD_SIZE,0
    JE ODD_ZERO
                    
    LEA DX,ODD
    MOV AH,9
    INT 21H    
    JMP LAST          
ODD_ZERO:
     PRINT "Not Found"
LAST:
    MOV AX,4CH
    INT 21H
MAIN ENDP
NEWLINE PROC
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    RET
NEWLINE ENDP
END MAIN