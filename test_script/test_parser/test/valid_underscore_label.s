.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:l_ive, %1
		and r1, %0, r1

l_ive:	live %1
		zjmp %:l_ive
