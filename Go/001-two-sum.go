func twoSum(nums []int, target int) []int {
    var res = []int {-1, -1}
    //以<数字, 下标>形式存储
    numMap := make(map[int] int)
    
    for key, value := range nums {
        another, ok := numMap[target - value]
        if(ok) {
            res[0], res[1] = key, another
        } else {
            numMap[value] = key
        }
    }
    return res
}