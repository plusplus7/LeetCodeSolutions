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
### [Reverse Words in a String][2]

字符串处理，简单题

### [Evaluate Reverse Polish Notation][3]

简单题，用stack模拟一下就好了

### [Max Points on a Line][4]

几何题，枚举两个点组成一条直线，遍历其他点，统计在线上点的数量，就好

Trick: 两个点在同一位置需要特殊处理

### [Sort List][5]

单链表排序，要求时间复杂度O(nlogn)，空间复杂度O(1)

用归并排序就ok，后来[biaaib][WEIBO_BIAAIB]告诉我，用快速排序也可以在空间复杂度O(1)的情况下实现

### [Insertion Sort List][6]

单链表排序，要求使用插入排序

### [LRU Cache][7]

LRU调度算法，实现一个基于LRU算法的Cache

用STL的map和list可以很快地实现一个

吐槽：搞不懂为什么这题难度是hard...

### [Binary Tree Postorder Traversal][8]

二叉树的后根序遍历，递归简单实现

### [Binary Tree Preorder Traversal][9]

二叉树的先根序遍历，递归简单实现

### [Reorder List][10]

单链表的重排列

把链表从中间截断，把后半段反序，然后把挨着把后半段的元素，每隔一个插入到前半段中

### [Linked List Cycle II][11]

单链表判环，要求定位到环的起点，要求不使用额外空间，我对此的理解是要求空间复杂度O(1)

使用快慢指针，当两个指针重合时，令一个新的指针从head开始往下遍历，同时快慢指针中的任意一个和新指针一起往下遍历，当和新指针重合时，那么重合的结点便是环的起点。

### [Linked List Cycle][12]

单链表判环，用快慢指针即可。

[1]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/maximum_product_subarray.cc
[2]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/reverse_words_in_a_string.cc
[3]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/evaluate_reverse_polish_notation.cc
[4]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/max_points_on_a_line.cc
[5]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/sort_list.cc
[6]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/insertion_sort_list.cc
[7]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/lru_cache.cc
[8]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_postorder_traversal.cc
[9]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_preorder_traversal.cc
[10]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/reorder_list.cc
[11]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/linked_list_cycle_ii.cc
[12]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/linked_list_cycle_i.cc

[WEIBO_BIAAIB]: http://weibo.com/biaaib
