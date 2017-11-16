

//////////////////////Just as in Lecture 4 slide 20/////////////////////

@i // i refers to some RAM location
M=1 // i=1
@sum // sum refers to some RAM location
M=0 // sum=0
(LOOP)
@i
D=M // D = i
@100
D=D-A // D = i - 100
@END
D 
@i
D=M // D = i
@sum
M=D+M // sum += i
@i
M=M+1 // i++
@LOOP
0 
(END)
@END
0 