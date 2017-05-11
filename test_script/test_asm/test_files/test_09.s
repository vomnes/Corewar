.name "TEST_9"
.comment "Champion Test"

l2:

		ldi %:l2, %:l2, r1
		ldi r1, %:l2, r1
		ldi %:l2, r1, r1

		ldi 40, r14, r1
		ldi 40, %:l2, r2
