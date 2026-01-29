import re

S = "line: a70 and z72 will be replaced, aa24 and a872 won’t"
result = re.sub(r"\b[a-z][0-9]{2}\b", "***", S)

print(result)

