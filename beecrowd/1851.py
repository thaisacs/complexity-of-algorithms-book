#!/usr/bin/python3

import math

class Dragon:
    def __init__(self, i, j, time):
        self.i = i
        self.j = j
        self.p = i/j
        self.start = time

    def __str__(self):
        return f"{self.i},{self.j} => {self.p}"

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def extract(self):
        value = self.elements[0]

        index = len(self.elements) - 1
        self.elements[0] = self.elements[index]
        self.elements.pop()
        self.maxheapfy(0)

        return value

    def maxheapfy(self, index):
        right = (index + 1) * 2 - 1
        left = (index + 1) * 2
        minv = index
        if(left < len(self.elements) and self.elements[left].p < self.elements[minv].p):
            minv = left 
        if(right < len(self.elements) and self.elements[right].p < self.elements[minv].p):
            minv = right 
        if(minv != index):
            buff = self.elements[index]
            self.elements[index] = self.elements[minv]
            self.elements[minv] = buff
            self.maxheapfy(minv)

    def increase(self, index, value):
        self.elements[index] = value
        i = math.floor((index+1)/2) - 1
        while(i >= 0 and self.elements[i].p > self.elements[index].p):
            buff = self.elements[i]
            self.elements[i] = self.elements[index]
            self.elements[index] = buff
            index = i
            i = math.floor((index+1)/2) - 1


    def insert(self, element):
        self.elements.append(element)
        index = len(self.elements) - 1
        self.increase(index, element)

    def empty(self):
        if(len(self.elements)):
            return False
        return True

def main():
    pq = PriorityQueue()
    
    index = 0
    charged = 0
    days = 0
    pay = 0

    while(True):

        try:
            i, j = input().split()
            i = int(i)
            j = int(j)
            d = Dragon(i, j, index);
        except EOFError:
            d = None

        if(index == 0):
            days = d.i
        elif(index > 0 and d != None):
            pq.insert(d)

        if(index > 0 and days == 0):
            d = pq.extract()
            charged = charged + (index-d.start) * d.j
            days = d.i

        days = days - 1
        index = index + 1

        if(days <= 0 and pq.empty()):
            break

    print(charged)

if __name__ == "__main__":
    main()

