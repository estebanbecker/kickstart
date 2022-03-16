num_test=int(input())

for i in range(num_test):
    data=input()
    data=data.split()
    k=int(data[0])
    s=int(data[1])
    word=input().upper()

    score = 0

    for j in range(int(k/2)):
        if word[j] != word[k-j-1]:
            score += 1

    if k<2:
        score = 0
    dif=score-s
    if dif<0:
        dif=-dif   


    print("Case #{}: {}".format(i+1, dif))

