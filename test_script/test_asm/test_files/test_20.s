.name "TEST_20"
.comment "Champion Test"

l2:		
		live %1
		ld %:l2, r2
		st r2, r8
		add r1, r2, r3
		sub r1, r2, r3
		and %:l2, %:l2, r1
		or %:l2, %:l2, r1
		or r1, %:l2, r1
		or %:l2, r1, r1
		xor %:l2, %:l2, r1
		xor r1, %:l2, r1
		xor %:l2, r1, r1
		zjmp %:live
		ldi %:l2, %:l2, r1
		ldi r1, %:l2, r1
		ldi %:l2, r1, r1
		sti r1, %:l2, %:l2
		sti r1, %12, %:l2
		sti r1, %:l2, %12
		fork %:l2
		lld %:l2, r1
		lldi %:l2, %:l2, r1
		lldi r1, %:l2, r1
		lldi %:l2, r1, r1
		lfork %:l2
		aff r10

live:	live %1
		zjmp %:live
		zjmp %:live
		zjmp %:live
