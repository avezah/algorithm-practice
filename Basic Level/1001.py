if __name__ == "__main__":
    number = int(input())
    cnt = 0
    while number > 1:
        if number%2 == 0:
            number /= 2
        elif number%2 == 1:
            number = (3*number + 1)/2
        cnt = cnt + 1
    print (cnt)