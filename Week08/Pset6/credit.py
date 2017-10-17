def check_sum(n):
    sum = 0
    digits = 1
    while n:
        if digits % 2 == 1:
            sum += n % 10
        else:
            i = n % 10 * 2
            sum += (i % 10 + i // 10)
        n //= 10
        digits += 1

    if sum % 10 == 0:
        return True
    else:
        return False

def get_company(n):
    num = str(n)
    length = len(num)
    if (length == 13 or length == 16) and num[0] == '4':
        print("VISA")
    elif length == 15 and num[:2] in ['34', '37']:
        print("AMEX")
    elif length == 16 and num[:2] in ['52', '52', '53', '54', '55']:
        print("MASTERCARD")

# ask for user input
while True:
    try:
        number = int(input("Number: "))
        break
    except ValueError:
        pass

if check_sum(number):
    get_company(number)
else:
    print("INVALID")