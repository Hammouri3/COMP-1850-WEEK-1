// FindMax.asm
// Computes the maximum of R0 and R1
// Stores max in R2
// Stores position in R3:
//   0 if R0 >= R1
//   1 if R1 > R0
// Does not modify R0 or R1

// D = R0 - R1
@R0
D=M
@R1
D=D-M

// If R0 - R1 >= 0, go to R0MAX
@R0MAX
D;JGE

// Otherwise, R1 is greater
@R1
D=M
@R2
M=D

@R3
M=1

@END
0;JMP

(R0MAX)
// R0 is greater than or equal to R1
@R0
D=M
@R2
M=D

@R3
M=0

(END)
@END
0;JMP