#!/usr/bin/python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def merge(list1, list2):
    buff = []

    while(list1 != None and list2 != None):
        if(list1.val < list2.val):
            buff.append(list1.val)
            list1 = list1.next
        else:
            buff.append(list2.val)
            list2 = list2.next

    while(list1 != None):
        buff.append(list1.val)
        list1 = list1.next

    while(list2 != None):
        buff.append(list2.val)
        list2 = list2.next

    result = None
    for i in range(len(buff)-1, 0, -1):
        result = ListNode(buff[i], result)
        
    print(buff)
    return result


def main():
    list_one = [4, 2, 1]
    list_two = [4, 3, 1]
    list1 = None
    list2 = None

    for i in list_one:
        list1 = ListNode(i, list1)

    for i in list_two:
        list2 = ListNode(i, list2)
        
    #while(list1 != None):
    #    print(list1.val)
    #    list1 = list1.next

    #while(list2 != None):
    #    print(list2.val)
    #    list2 = list2.next

    result = merge(list1, list2)

if __name__ == "__main__":
    main()

