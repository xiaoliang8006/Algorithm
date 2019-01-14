# -*- coding: utf-8 -*-
# @Date    : 2016/10/11
# @Author  : hrwhisper

if __name__ == '__main__':
    N = int(input())
    nums=[N]
    #nums = [1, 3, 4, 2, 1, 6]
    for i in range(N):
        nums[i] = input().split(" ")
    print nums
