.name "TEST_16"
.comment "Champion Test"

l2:		

		sti r1, %:l2, %:l2
		sti r1, %-92233, %:l2
		sti r1, %:l2, %12
		sti r2, 9223, r10
		sti r1, r2, r3
