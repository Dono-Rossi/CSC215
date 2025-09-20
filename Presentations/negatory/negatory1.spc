# Negatory or Not Presentation
# By Donovan and Anupama
# Goes to register 81 if Not Negatory but 121 if it is Negatory

3A # Step 1: LDA
82 # Step 2: address where number is loaded from (first number)
00 # Step 3: High Adress
47 # Step 4: Move A to B
3A # Step 5: LDA 
81 # Step 6: address where number is loaded from (second number)
00 # Step 7: High address
90 # Step 8: subtract number in register B (first number above) from register A
F4 # Step 9: Call if plus
80 # Step 10: Address called if not negatory
00 # Step 11: High address
FC # Step 12: Call if Negative
C0 # Step 13: Address called if negatory
00 # Step 14: High address
===
82:03
81:04
80:76
C0:76


