3A # load
81 # load low byte (first number)
00 # high byte
47 # Move A to B
3A # load
80 # load (second number)
00 # high byte
90 # subtract number in b (first number) from a
32 # store
82 # low byte
00 # high byte
76 # halt
===
81:04
80:03
