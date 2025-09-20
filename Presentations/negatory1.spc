3A # load
82 # load low byte (first number)
00 # high byte
47 # Move A to B
3A # load
81 # load (second number)
00 # high byte
90 # subtract number in b (first number) from a
F4 # Call if plus
80 # Low address
00 # high addres
FC # Call if Negative
C0 # Low adress
00 # High Adress
76 # halt
===
82:03
81:04
80:76
C0:76


