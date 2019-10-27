strings = input("enter some strings:").strip()
z = " "
count = 0
x = [m for m in strings if m not in z]
y = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
for f in x:
    if f in y:
        count += 1

print(count)