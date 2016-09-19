from urllib.request import Request, urlopen

sock = urlopen("http://python-data.dr-chuck.net/regex_sum_247608.txt")
content = sock.read()
sock.close()

# Extract all integers of the text and sum them up
import re

print(sum([int(num) for num in re.findall(r'([\d]+)', str(content))]))
