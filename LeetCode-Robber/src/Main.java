import java.lang.reflect.Array;
import java.util.Arrays;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        int[] nums = {1,2,3,1};
        System.out.println(rob(nums));
    }


    public static int rob(int[] nums) {
        int[] arr = new int[nums.length * 2];
        Arrays.fill(arr, -1);
        boolean[] islastrobbed = {false};
        return rob(nums, islastrobbed, 0, arr);
    }

    public static int rob(int[] nums, boolean[] islastrobbed, int i, int[] arr){
        if (i == nums.length)
            return 0;
        int key = 2 * i + (islastrobbed[0] ? 1 : 0);
        if (arr[key] != -1)
            return arr[key];
        int result;
        int ni = i + 1;
        if (islastrobbed[0]) {
            islastrobbed[0] = false;
            result = rob(nums, islastrobbed, ni, arr);
        }
        else {
            islastrobbed[0] = false;
            int x1 = rob(nums, islastrobbed, ni, arr);
            islastrobbed[0] = true;
            int x2 = nums[i] + rob(nums, islastrobbed, ni, arr);
            result = Math.max(x1, x2);
        }
        arr[key] = result;
        return result;
    }
}