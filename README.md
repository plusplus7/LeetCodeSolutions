# My Solutions to LeetCode

### [Find Minimum in Rotated Sorted Array][-1]

二分，寻找轮换排序数组的最小元素

O(logn)的算法是对数组进行二分，如果中间值大于左值，则说明答案在[mid+1,r]；反之，则答案在[l,mid]

注意特殊处理只有一个元素的情况

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

### [Word Break II][13]

动态规划＋Trie树，和[LA 3942 Remember the Word][LA 3942 Remember the Word]一样差不多，只不过此题还要求所有的方案。

dp[i]表示以第i个字符开始的后缀字符串有多少种拼接方案
那么有动态转移方程：dp[i] = sum{ dp[i+len(x) | x 为字典中的字符串，并且x是i后缀的前缀] }

用Trie树来加速查找x的过程，不过我写得有点搓...感觉也没快多少...

### [Word Break][14]

动态规划＋Trie树，和[LA 3942 Remember the Word][LA 3942 Remember the Word]一样差不多，但是此题只需要求dp[0]是否不为0即可

解法同上

### [Copy List with Random Pointer][15]

单链表的深拷贝

空间复杂度O(n)的方法很容易想到，我用的是O(1)的方法

分三步，先把链表的每一个结点复制一个，插入到该结点的后面，复制结点的random指针先设为NULL
然后，遍历单链表，把根据原始结点的random指针来设置复制结点的random指针；因为每个原始结点的下一个就是该结点的复制结点，所以复制结点的random指针应该指向其原始结点的random指针所指向的结点的next指针所指向的结点

```
    new->random = raw->random->next;
```

最后，把原始元素和复制元素分开形成两个单链表，复制元素形成的单链表就是深拷贝的结果

### [Single Number II][16]

水题，给一个数组，查找出现次数少于三次的元素

统计一下每一位1的个数，因为只有一个元素出现少于三次，所以每一位1的个数模3就能知道该元素的那一位是否为1

这题好像是某个ACM比赛的签到题

### [Single Number I][17]

水题，给一个数组，查找出现次数少于两次的元素

答案是所有元素的异或和

### [Candy][18]

给定一数列，求一新数列，满足某元素在原数列中大于相邻元素，在新数列中也大于相邻元素，求新数列和最少是多少，新数列最小值是1

从左往右扫一遍，使原本是递增的区间在新数列中也递增；从右往左扫一遍，使递减的也递减

### [Gas Station][19]

给定一个环，给出环上路径的距离和汽油量。求从某点出发，能遍历所有结点，而在遍历的每一时刻，汽油量不为负。

把线路扩展成一个环，从起点出发开始遍历。当走到某点，发现汽油量为负，则能判定，在该点之前的所有点都不能为起点。

### [Clone Graph][20]

深拷贝一个无向图，有环

有空间复杂度为O(1)的解法，就和之前的单链表深拷贝一样，把新复制的结点加到原结点的边的最后面，然后遍历原结点的边，把所有原结点的边连着的结点的新复制结点和之前的新复制的结点连接起来，最后再pop掉原结点的边中最后面的元素，就ok

我用的是一个O(n)的解法，那就是直接DFS，用map记录所有遇到过的结点，把label作为key，新复制的结点作为value存起来。DFS时，如果遇到访问过的结点，就直接返回map中的value，否则新建结点，然后遍历所有边，递归地为新建结点建立边的关系

我之前写了一个[O(1)版本][WA_CLONE_GRAPH]不知道为什么会Wrong Answer，我在本机测试发现结果是正确的。看了下discuss，发现有人和我在同一组case遇到同样的问题

### [Palindrome Partitioning II][21]

将字符串分割为一个个回文串，求最少分多少次

可以先用O(n^2)的预处理，得到is_pal[i][j]表示i到j是否是回文串

再用O(n^2)的dp，求出dp[i]表示包含第i个字符能分割字符串的最小分割数

答案就是dp[n-1]

### [Palindrome Partitioning I][22]

将字符串分割为一个个回文串，求所有分法

可以先用O(n^2)的预处理，得到is_pal[i][j]表示i到j是否是回文串

然后DFS一下，就行了

### [Surrounded Regions][23]

把图中所有被X包围的O置为X，求最终图

从图四个边上所有的O开始DFS，所有遍历到的O在最终图中都不是X

处理完了之后，把所有没有遍历到的O置为X即可

### [Sum Root to Leaf Numbers][24]

DFS，求所有根到叶子结点所产生数之和

### [Longest Consecutive Sequence][25]

用给定数组组成一条最长连续数列，求长度为多少

要求使用O(n)的算法

照着O(n)的尿性，就知道应该使用hash

把所有数字放到一个 set (unordered_set) 中，然后遍历set中的元素

因为unordered_set使用的是hash，所以可以根据当前元素在平均O(1)的时间复杂度下知道是否存在相邻元素

把所有相邻元素都找一次，然后记录最长能达到多少，再把所有找过的元素从set中删掉就ok

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
[13]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/word_break_ii.cc
[14]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/word_break_i.cc
[15]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/copy_list_with_random_pointer.cc
[16]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/single_number_ii.cc
[17]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/single_number_i.cc
[18]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/candy.cc
[19]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/gas_station.cc
[-1]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/find_minimum_in_rotated_sorted_array.cc
[20]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/clone_graph.cc
[21]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/palindrome_partitioning_ii.cc
[22]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/palindrome_partitioning_i.cc
[23]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/surrounded_regions.cc
[24]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/sum_root_to_leaf_numbers.cc
[25]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/longest_consecutive_sequence.cc

[WA_CLONE_GRAPH]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/wa_clone_graph.cc
[WEIBO_BIAAIB]: http://weibo.com/biaaib
[LA 3942 Remember the Word]: http://blog.csdn.net/sssogs/article/details/8789386
