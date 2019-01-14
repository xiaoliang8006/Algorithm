# -*- coding: utf-8 -*-
# @Date    : 2016/10/11
# @Author  : hrwhisper


def longest_increasing_subsequence(nums):
    if not nums: return 0
    n = len(nums)
    dp = [1] * n
    update_from = [-1] * n

    lis_len = 1
    index = 0
    for i in range(1, n):
        for j in range(i - 1, -1, -1):
            if nums[j] < nums[i] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                update_from[i] = j
        if dp[i] > lis_len:
            lis_len, index = dp[i], i

    ans = []
    while index != -1:
        ans.append(nums[index])
        index = update_from[index]
    return lis_len, ans[::-1]


if __name__ == '__main__':

    nums = [1, 2, 3, 1]
    print(longest_increasing_subsequence(nums))
 
