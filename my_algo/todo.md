# TODO

## 十大排序算法  

## 二叉树的递归遍历与非递归遍历  

## 差分数组  

差分数组的主要适用场景是**频繁**对原始数组的某个区间的元素进行**增减**  

## 前缀和数组  

前缀和数组的主要适用场景是**原始数组不会被修改**的情况下，**频繁查询**某个区间的**累加和**

## DFS

## BFS

## 并查集

## 动态规划

1. 背包

## 贪婪

## 滑动窗口

[labuladong](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247497171&idx=1&sn=faa317e8acf4d28859257794aaf933b7&scene=21#wechat_redirect)

```c++
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while(right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++；
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d]\n", left, right);

        // 判断左侧窗口是否要收缩
        while(window needs shrink) {
            // d 是将要移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```
