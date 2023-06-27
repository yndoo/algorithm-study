import sys
input = sys.stdin.readline
n, w, L = map(int, input().split())
trucks = list(map(int,input().split()))
now_trucks=[]
now_times=[]

#First Step
now_trucks.append(trucks.pop(0))
now_times.append(1)
time = 1 #전체시간

#Second~Final
while trucks or now_trucks:
    now=0
    while now < len(now_times):
        if now_times and now_times[now]>=w:
            now_trucks.pop(now)
            now_times.pop(now)
        else:
            now_times[now]+=1
            now+=1
    if trucks and sum(now_trucks)+trucks[0]<=L and len(now_trucks)<w:
        now_trucks.append(trucks.pop(0))
        now_times.append(1)
    time+=1
print(time)