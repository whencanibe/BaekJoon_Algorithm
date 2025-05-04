import sys
readline = sys.stdin.readline

N = int(readline().strip())
weights = {}

for i in range(N):
    word = readline().strip()
    power = 1

    for ch in reversed(word):
        weights[ch] = weights.get(ch, 0) + power
        power *= 10

letters = sorted(weights.items(), key=lambda x: -x[1])

digit = 9
assign_num = {}
for letter , _ in letters:
    assign_num[letter] = digit
    digit -= 1

result = sum(weights[ch] * assign_num[ch] for ch in weights)

print(result)