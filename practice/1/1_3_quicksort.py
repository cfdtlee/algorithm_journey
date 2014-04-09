#!/usr/bin/env python
# coding=utf-8

t_of_c = 0

def exchange(A, i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp


def partition(A, p, r):
    global t_of_c
    x = A[r]
    i = p-1
    for j in range(p, r+1):
        if A[j] < x:
            t_of_c = t_of_c+1
            i = i+1
            exchange(A, i, j)
    exchange(A, r, i+1)
    return i+1


def quicksort(A, p, r):
    global t_of_c
    if r > p:
        t_of_c = t_of_c+1
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)  #first time: maximum recursion depth exceeded

#A = [3, 9, 7, 12, 10, 7, 2, 6]
A = [1]*10
A = [1,2,3,4,5,6,7,8,9,10]
quicksort(A, 0, len(A)-1)
print(A)
print(t_of_c)