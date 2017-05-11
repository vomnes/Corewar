.name "TEST_17"
.comment "Champion Test"

l2:		

		sti r1, %:l2, %:l2
		sti r1, %-9223, %:l2
		sti r1, %:l2, %12
		sti r2, %-92233, r10
		sti r1, r2, r3
