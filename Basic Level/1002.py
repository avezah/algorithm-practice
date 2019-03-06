if __name__ == "__main__":
    nums = input()
    add = 0
    for num in nums:
        add += int(num)
    add = str(add)

    dic = {'0':"ling",'1':"yi",'2':"er",'3':"san",'4':"si",'5':"wu",'6':"liu",'7':"qi",'8':"ba",'9':"jiu"}
    res = []
    for each in add:
        res.append(dic[each])
    print (" ".join(res))
