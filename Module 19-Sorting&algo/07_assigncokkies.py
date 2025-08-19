g = [1, 2, 3]   # greed factors
s = [1, 1]      # cookie sizes

g.sort()
s.sort()

i = 0
j = 0
count = 0

while i < len(g) and j < len(s):
    if s[j] >= g[i]:
        count += 1
        i += 1
        j += 1
    else:
        j += 1

print("Number of content children:", count)
