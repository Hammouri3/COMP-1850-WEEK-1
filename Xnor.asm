// Xnor.asm
// Computes R2 = R0 XNOR R1
// Does not modify R0 or R1

// R3 = R0 & R1
@R0
D=M
@R1
D=D&M
@R3
M=D

// R4 = !R0
@R0
D=M
D=!D
@R4
M=D

// R4 = !R0 & !R1
@R1
D=M
D=!D
@R4
M=D&M

// R2 = R3 | R4
@R3
D=M
@R4
D=D|M
@R2
M=D

(END)
@END
0;JMP