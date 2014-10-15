# My Solutions to LeetCode

### [Maximum Product Subarray][1]

一维递推，空间复杂度可以优化为O(1)

dp_max[i]维护包含第i元素的最大值

dp_min[i]维护包含第i元素的最小值

动态转移方程：

```
    dp_max[i]=max(dp_max[i-1]\*A[i], A[i], dp_min[i-1]\*A[i])
    dp_min[i]=max(dp_min[i-1]\*A[i], A[i], dp_max[i-1]\*A[i])
```

[1]:https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/maximum_product_subarray.cc
