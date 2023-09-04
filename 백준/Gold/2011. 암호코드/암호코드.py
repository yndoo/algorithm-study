import sys
myinput = sys.stdin.readline
code = myinput().rstrip()
dp = [0] * (len(code)+1)
dp[0], dp[1] = 1, 1
if code[0] == '0':
    print(0)
else:
    for i in range(2, len(code)+1):
        if 0 < int(code[i-1]):
            dp[i] = dp[i-1]
        if 10 <= int(code[i-2]+code[i-1]) <=26:
            dp[i] += dp[i-2]
        elif code[i-2]+code[i-1] == '00':
            print(0)
            break
    else:
        print(dp[len(code)]%1000000)