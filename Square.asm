// Square.asm
// R0 = x
// R1 = x*x
// Does not modify R0

// R3 = abs(R0)
@R0
D=M
@POSITIVE
D;JGE

@R0
D=M
D=-D
@R3
M=D
@START
0;JMP

(POSITIVE)
@R0
D=M
@R3
M=D

(START)
// R1 = 0
@R1
M=0

// R4 = counter = abs(x)
@R3
D=M
@R4
M=D

(LOOP)
@R4
D=M
@END
D;JLE

// R1 = R1 + abs(x)
@R3
D=M
@R1
M=D+M

// counter--
@R4
M=M-1

@LOOP
0;JMP

(END)
@END
0;JMP