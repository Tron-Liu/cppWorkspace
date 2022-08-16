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

## 回溯

[一文秒杀排列组合问题的 9 种题型 labuladong](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247496080&idx=1&sn=a2ae8c8ebf13c7ea704ffb6b16018f08&scene=21#wechat_redirect)

1. 排列 (如果次序重要就叫排列)

    * 元素无重不可复选，数组 (nums) 中的元素都是唯一的，每个元素最多只能被使用一次

    ```java



    ```

    * 元素可重不可复选，nums 中的元素可以存在重复，每个元素最多只能被使用一次

    ```java
    

    ```

    * 元素无重可复选，nums 中的元素都是唯一的，每个元素可以被使用若干次

    ```java
    

    ```

2. 组合 (如果次序不重要就叫组合)

## 滑动窗口

[我写了首诗，把滑动窗口算法变成了默写题 labuladong](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247497171&idx=1&sn=faa317e8acf4d28859257794aaf933b7&scene=21#wechat_redirect)

1. 算法思路
    * 初始化 `left = right = 0`，把索引左闭右开区间 `[left, right)` 称为一个窗口
    * 先不断地增加 `right` 指针扩大窗口 `[left, right)` ，直到窗口中的字符串符合要求

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
