#!/usr/bin/env python
# coding=utf-8
heap_end = 0

def parent(i):
    return (i-1)/2

def LEFT(i):
    return i*2+1

def RIGHT(i):
    return i*2+2

def exchange(A, i, j):
	"""exchange"""
	temp = A[j]
	A[j] = A[i]
	A[i] = temp

def max_heapify(A, i, size):#heapfy 到end
    l = LEFT(i)
    r = RIGHT(i)
    if l < size and A[l] > A[i]:
    	largest = l
    else:
    	largest = i
    if r < size and A[r] > A[largest]:  #error
    	largest = r
    if largest != i:
    	exchange(A, i, largest)
    	max_heapify(A, largest, size)

def build_max_heap(A):
	#global heap_end = len(A)-1  #error
	for i in range(parent(len(A) - 1), -1, -1):#error
		max_heapify(A, i, len(A)-1)
	print("after heapfy A=")
	print(A)

def heapsort(A):
	build_max_heap(A)
	heap_end = len(A)-1
	for i in range(len(A)-1, 0, -1): #error
	    exchange(A, heap_end, 0)
	    #print("exchange"+str(A[heap_end])+"with"+str(A[0]))
	    #print(str(0)+"in heap is:"+str(A[0]))
	    heap_end = heap_end-1
	    max_heapify(A, 0, heap_end)
	    #print(A)
	    
def max_in_heap(A):
    return A[0]

def pop_max(A):
    if len(A) < 1:
    	print "heap is empty\n"
    else:
    	max = A[0]
    	A[0] = A[len(A)-1]
    	A.pop()
    	max_heapify(A, 0, len(A)-1)
    	return max

def increase_key(A, x, k):
	if A[x] > k:
		print "new key is smaller than current key"
	else:
		A[x] = k
		while A[x] > A[parent(x)] and x > 0:
			exchange(A, x, parent(x))
			x = parent(x)

def insert(A, x):
    A.append(-999)
    increase_key(A, len(A)-1, x)

A = [3,9,3,4,10,2,5,7,3]
print(A)
#heapsort(A)
build_max_heap(A)
pop_max(A)
print(A)
insert(A, 11)
print(A)