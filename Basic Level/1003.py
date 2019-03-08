if __name__ == "__main__":
    n = int(input())
    strings = []
    for _ in range(n):
        strings.append(input())
    
    res = []
    for string in strings:
        length = len(string)
        if 'P' in string and 'T' in string and string.count('A') == length - 2:
            p = string.index('P')
            t = string.index('T')
            n = t - p - 1
            if n == 0:
                res.append("NO")
            elif n*string[0:p] == string[t + 1:length]:
                res.append("YES")
            else:
                res.append("NO")
        else:
            res.append("NO")
    
    for judge in res:
        print (judge)

# 这题卡了有点久，主要是因为没有好好读题，最早一直是觉得只要字符里有PAT或者PAAT就可以成立
# 然后才注意到P和T中间的A的数目就是字符串T之后重复P之前的倍数
