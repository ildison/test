.name       "Batman"
.comment    "This city needs me"

loop:
        sti r1, %:live, %1
live:
        live %-1
        ld -1, r15
		zjmp %-1
		ld      %0, r2
