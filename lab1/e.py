import queue

borisCards= queue.Queue()
nurikCards= queue.Queue()

for i in range(0, 10):
    card = int(input())
    if i< 5:
        borisCards.put(card)
    else:
        nurikCards.put(card)

cnt = 0

while not borisCards.empty() and not nurikCards.empty():
    cnt += 1
    if cnt == 1000000:
       print("blin nichya")
       break

    if borisCards.front()== 0 and nurikCards.front()== 9:
        borisCards.put(borisCards.front())
        borisCards.put(nurikCards.front())
        borisCards.pop()
        nurikCards.pop()

    elif borisCards.front()== 9 and nurikCards.front()== 0:
        nurikCards.put(borisCards.front())
        nurikCards.put(nurikCards.front())
        borisCards.pop()
        nurikCards.pop()
    elif borisCards.front()> nurikCards.front():
        borisCards.put(borisCards.front())
        borisCards.put(nurikCards.front())
        borisCards.pop()
        nurikCards.pop()
    elif borisCards.front()< nurikCards.front():
        nurikCards.put(borisCards.front())
        nurikCards.put(nurikCards.front())
        borisCards.pop()
        nurikCards.pop()

    if nurikCards.empty():
        print("Boris ")
    else:
        print("Nursik ")