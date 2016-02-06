digit_count = 0
for char in str(2**1000):
	digit_count += int(char)

print digit_count