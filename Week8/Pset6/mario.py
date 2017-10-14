def print_space(n):
    for i in range(n):
        print(" ", end="")

def print_hash(n):
    for i in range(n):
        print("#", end="")

while True:
    try:
        Height = int(input("Height: "))
        if Height > 0 and Height <= 23:
            break
    except ValueError:
        pass

for i in range(Height):
    print_space(Height - 1 - i)
    print_hash(i + 1)
    print_space(2)
    print_hash(i + 1)
    print()