//altering from the 1 to 100 addition
// by assuming counter minus second integer
// if less than 0 means the loop of first integer adding itself goes on
//while more than 0 means stop the loop 

		@R2 
		M=0
		@counter
		M=1		 
	
			 

(LOOP)
		@counter
		D=M		//D=counter set
		
		@R0
		D=D-M		// counter = counter - r0
		@END
		D;JGT //setting condition jump to END
		
		@R1
		D=M
		
		@R2
		M=M+D //adding itself
		
		@counter //incremental
		M=M+1
		@LOOP //loop jump
		0;JMP
(END)
		@END   
		0;JMP
		
