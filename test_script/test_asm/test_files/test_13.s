.name "TEST_13"
.comment "Champion Test"

l2:
		lldi %:l2, %:l2, r1
		lldi r1, %:l2, r1
		lldi %:l2, r1, r1
		lldi %650, %:live, r4
		lldi 50, %60, r1
live:
