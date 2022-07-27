## 滑动窗口框架
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

## 回溯算法框架
```python
def backtrack(路径，选择列表):
    if 满足结束条件：
        result.append(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径，选择列表)
        撤销选择
```

```
形式一、元素无重不可复选，即 nums 中的元素都是唯一的，每个元素最多只能被使用一次
形式二、元素可重不可复选
形式三、元素无重可复选
```