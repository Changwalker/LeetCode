//labuladong 回溯算法
class Solution {
    List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        backTrack(nums, track);
        return res;
    }
    public void backTrack(int[] nums, LinkedList<Integer> track){
        // 终止条件
        if(track.size() == nums.length){
            //注意传入res一个track的拷贝对象（当前数组的快照），而不能直接传入res，res之后会不断变化的
            res.add(new LinkedList(track));
            return ;
        }

        for(int i = 0; i < nums.length; i++){
            if(track.contains(nums[i]))
                continue;
            track.add(nums[i]);
            backTrack(nums, track);
            track.removeLast();
        }
    }
}