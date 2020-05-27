


file = open('day1.txt')
value = file.readline()


freq1 = []
freq2 = []






while value != '':

    freq1.append(value)
    value = file.readline()


frequency = 0
iterations = 0
while frequency not in freq2:
    for i in range(len(freq1)):
        freq2.append(frequency)
        frequency = frequency + int(freq1[i])
        if frequency in freq2:
            print("first is ", frequency)
        
