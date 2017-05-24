.name "Xorian"
.comment "The ultimate xorian champion"

		xor r2, r3, r4
live:	st r1, 6
		live %1
		fork %500
		zjmp %:live
