#!/usr/bin/env python
# coding=utf-8
def merge_sort(A, p, r):
    """implement merge_sort in A"""
    if p<r:
        q=(p+r)/2
        merge_sort(A, p, q)
        merge_sort(A, q+1, r)
        merge(A, p, q, r) #1_error

def exchange(A, i, j):
    """exchange"""
    temp = A[j]
    A[j] = A[i]
    A[i] = temp

def merge(A, p, q, r):
    """merge two divided part"""
    print('p='+str(p)+'q='+str(q)+'r='+str(r))
    n1=q-p+1
    n2=r-q
    L=A[p:q+1]
    R=A[q+1:r+1]
    print('len(L)')
    L.append(9999)
    R.append(9999)
    i=0
    j=0
    for k in range(p,r+1):
        #print('L['+str(i)+']='+str(L[i])+'R['+str(j)+']='+str(R[j]))
        if L[i] <= R[j]:
            A[k] = L[i]
            i=i+1
            print('L[i] <= R[j]')
            print(R[j])
        else:
            A[k] = R[j]
            j=j+1
            print('L[i] > R[j]')
            print(L[i])
    print(A)
    print('i='+str(i))
    print('j='+str(j))

def binary_search(A, x):
    """search x in A"""
    begin = 0
    end = len(A)
    mid = (begin+end)/2
    while end-begin>1:  #error3 不存在的停不下来
        if x>A[mid]:
            begin = mid
            mid = (mid+end)/2
        elif x<A[mid]:
            end = mid
            mid = (mid+begin)/2
        else:
            print('find x in A['+ str(mid) +']')
            break
    if x!=A[mid]:
        print('cannot find!')

A=[23,8,6,12,4,3,6,5,1,3,6,4,9,3,1,16,10]
merge_sort(A, 0, len(A)-1) #error2
print(A)
binary_search(A,24)

