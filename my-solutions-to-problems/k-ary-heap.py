#!/usr/bin/python3
from typing import List

class MaxHeap:
    nodes: List[int]

    def __init__(self, nodes: List[int] = []):
        self.nodes = []

        for node in nodes:
            self.nodes.append(node)

        print(self.nodes)

    def __add__(self, node):
        print(node)

a = MaxHeap([1, 2, 3])
b = MaxHeap([1, 2, 3])

a + b
