def solution(new_id):
    available=['-','_','.']
    # 1단계
    new_id=list(new_id.lower())
    # 2단계
    for i, str in enumerate(new_id):
        if str.isdigit():
            continue
        elif str in available: #가능한 문자열
            continue
        elif str.isalpha():
            continue
        else:
            new_id[i]=''
    new_id=[x for x in new_id if x]
    # 3단계
    dot=False
    for i in range(len(new_id)):
        print(new_id[i],dot)
        if new_id[i]=='.' and dot==False:
            dot=True
        elif new_id[i]=='.' and dot==True:
            new_id[i]=''
        elif new_id[i]!='.':
            dot=False
            
    new_id=[x for x in new_id if x]
    print("3",new_id)
    # 4단계
    if new_id[0]=='.':
        new_id[0]=''
    if new_id[len(new_id)-1]=='.':
        new_id[len(new_id)-1]=''
    # 5단계
    new_id=[x for x in new_id if x]
    if len(new_id)==0:
        new_id=['a']
    # 6단계
    if len(new_id)>=16:
        new_id=new_id[0:15]
        if new_id[14]=='.':
            new_id=new_id[0:14]
    # 7단계
    if len(new_id)<=2:
        for _ in range(3-len(new_id)):
            new_id.append(new_id[-1])
            
    return ''.join(new_id)