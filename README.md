# My Solutions to LeetCode

当前进度：94/153

### [Find Minimum in Rotated Sorted Array II][-2]

二分，寻找轮换排序数组的最小元素，可能有相同元素

还是对数组进行二分，当左值等于右值时，可以把二分的范围两边同时减1

这样做的话，算法时间复杂度是O(n)，不过OJ还是会给Accepted...

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

### [Word Ladder II][26]

搜索题，从某个单词转换到另一个单词的条件是两个单词最多只有1个字符不同。给出一个字典，从起始单词最少转换几次到目标单词，求所有最少转换的路径

先BFS按层数搜索，搜到目标单词那一层时，停止。纪录所有单词的前驱单词。

根据记录单词的前驱单词，从目标单词开始反向DFS，同时记录答案即可

### [Word Ladder][27]

搜索题，从某个单词转换到另一个单词的条件是两个单词最多只有1个字符不同。给出一个字典，求从起始单词最少转换几次到目标单词

BFS一下就好了

### [Valid Palindrome][28]

除掉特殊字符外的字符串，判断是否是回文串

扫一遍就好了

### [Binary Tree Maximum Path Sum][29]

树形动态规划，求二叉树上两节点之间路径和

其实只是有点树形dp的味道。DFS一下，dp[i]表示以节点i为终点，以节点i的某个儿子节点为起点的最大路径和，dp[i] = max(dp[i->right]+val[i], dp[i->left]+val[i])

实际在求的时候，可以利用递归把dp数组省掉，答案ans = max(dp[i->left]+dp[i->right]+val[i], dp[i->left]+val[i], dp[i->right]+val[i])

### [Best Time to Buy and Sell Stock III][30]

动态规划，给出某股票的n日的价格，能买进卖出最多两次，求最多能赚多少

dp_left[i]表示从0到i，买卖1次最多能赚多少
dp_right[i]表示从i到n，买卖1次最多能赚多少

答案就是dp_left[i-1]+dp_right[i]

### [Best Time to Buy and Sell Stock II][31]

贪心，扫一遍，求出所有峰值和谷值，把差累加起来就好

需要注意判断谷值时的，>=和<的符号使用问题

### [Best Time to Buy and Sell Stock I][32]

简单题，扫一遍，求出最大和最小，答案是差值

### [Triangle][33]

动态规划入门题

dp[i][j] = min(dp[i-1][j]+val[i][j], dp[i-1][j-1]+val[i][j])

### [Pascal's Triangle II][34]

数论，求杨辉三角的第k行

利用递推求组合数的公式可以直接算出答案

公式的推导见《算法竞赛入门经典》第183页

### [Pascal's Triangle][35]

数论，求杨辉三角的第k行

利用递推求组合数的公式可以直接算出答案

公式的推导见《算法竞赛入门经典》第183页

### [Populating Next Right Pointers in Each Node II][36]

指针处理，把任意二叉树上节点和右边离它最近的节点连接起来

从最高层往下处理，每层的儿子可以借助其父亲的next节点找到右边离它最近的节点

递归往下即可

### [Populating Next Right Pointers in Each Node][37]

指针处理，把完全二叉树上节点和右边离它最近的节点连接起来

从最高层往下处理，每层的右儿子的next指向其父亲的next的left节点

递归往下即可

### [Distinct Subsequences][38]

动态规划，求S的子序列中有多少是T

dp[i][j]表示S[0...i]的子序列有多少是T[0...j]

那么dp[i][j] = dp[i-1][j]+dp[i-1][j-1], 当S[i] == T[j]
    dp[i][j] = dp[i-1][j]               当S[i] != T[j]

### [Flatten Binary Tree to Linked List][39]

指针处理，把二叉树变成单链表

flatten把每棵子树变成链，递归一下

当左儿子存在时，把左边最下面的节点找到，把它和右儿子接起来就ok

### [Path Sum II][40]

搜索，DFS一下，记录路径就好了

### [Path Sum I][41]

搜索，DFS一下，判断一下就好了

### [Minimum Depth of Binary Tree][42]

搜索，DFS一下，记录最小值就好了

### [Balanced Binary Tree][43]

递归，判断某二叉树是否平衡

纪录左子树和右子树的高度，比较差值

递归往下即可

### [Convert Sorted List to Binary Search Tree][44]

递归，把有序链表转化为二叉树

类似于中序遍历，从左子树开始建树

增加l和r记录递归的范围，便于控制

### [Convert Sorted Array to Binary Search Tree][45]

递归，把有序数组转化为二叉树

类似于中序遍历，从左子树开始建树

增加l和r记录递归的范围，便于控制

### [Binary Tree Level Order Traversal II][46]

二叉树的层次遍历，按层数倒序输出

DFS的时候，记录层数，把值放到相应的vector中，利用reverse函数可以直接反转vector

### [Construct Binary Tree from Inorder and Postorder Traversal][47]

根据中根序和后根序重建二叉树

递归的进行，对两个数组都增加l和r值，便于操作，先建左子树再建右子树

### [Construct Binary Tree from Preorder and Inorder Traversal][48]

根据中根序和先根序重建二叉树

递归的进行，对两个数组都增加l和r值，便于操作，先建左子树再建右子树

### [Maximum Depth of Binary Tree][49]

求二叉树最大层数

DFS一下，记录层数就好

### [Binary Tree Zigzag Level Order Traversal][50]

二叉树的层次遍历，把每隔一层的元素反转后输出

DFS的时候，记录层数，把值放到相应的vector中，利用reverse函数可以直接反转奇数层的vector

### [Binary Tree Level Order Traversal][51]

二叉树的层次遍历，把每隔一层的元素反转后输出

DFS的时候，记录层数，把值放到相应的vector中

### [Symmetric Tree][52]

判断二叉树是否对称

从root的左右儿子分开，一起往下递归即可

### [Same Tree][53]

判断二叉树是否相同

一起从root开始往下递归即可

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
[26]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/word_ladder_ii.cc
[27]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/word_ladder_i.cc
[28]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/valid_palindrome.cc
[29]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_maximum_path_sum.cc
[30]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/best_time_to_buy_and_sell_stock_iii.cc
[31]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/best_time_to_buy_and_sell_stock_ii.cc
[32]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/best_time_to_buy_and_sell_stock_i.cc
[33]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/triangle.cc
[34]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/pascals_triangle_ii.cc
[35]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/pascals_triangle_i.cc
[36]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/populating_next_right_pointers_in_each_node_ii.cc
[37]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/populating_next_right_pointers_in_each_node_i.cc
[38]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/distinct_subsequences.cc
[39]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/flatten_binary_tree_to_linked_list.cc
[40]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/path_sum_ii.cc
[41]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/path_sum_i.cc
[42]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/minimum_depth_of_binary_tree.cc
[-2]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/find_minimum_in_rotated_sorted_array_ii.cc
[43]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/balaced_binary_tree.cc
[44]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/convert_sorted_list_to_binary_search_tree.cc
[45]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/convert_sorted_array_to_binary_search_tree.cc
[46]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_level_order_traversal_ii.cc
[47]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/construct_binary_tree_from_inorder_and_postorder_traversal.cc
[48]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/construct_binary_tree_from_preorder_and_inorder_traversal.cc
[49]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/maximum_depth_of_binary_tree.cc
[50]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_zigzag_level_order_traversal.cc
[51]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/binary_tree_level_order_traversal.cc
[52]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/symmetric_tree.cc
[53]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/same_tree.cc


[WA_CLONE_GRAPH]: https://github.com/plusplus7/LeetCodeSolutions/blob/master/src/wa_clone_graph.cc
[WEIBO_BIAAIB]: http://weibo.com/biaaib
[LA 3942 Remember the Word]: http://blog.csdn.net/sssogs/article/details/8789386
