
 public class TreeNode {
      public int val;
      public TreeNode left;
      public TreeNode right;
      public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
 }

public class TreeNodeObject {
    public int depth;
    public TreeNode node;
    public TreeNodeObject(TreeNode node, int depth)
    {
        this.node = node;
        this.depth = depth;
    }
}

public class Solution
{
    public IList<IList<int>> LevelOrder(TreeNode root)
    {
        IList<IList<int>> list = new List<IList<int>>();
        if (root == null)
            return list;
        Queue<TreeNodeObject> queue = new Queue<TreeNodeObject>();
        int depth = 0;
        queue.Enqueue(new TreeNodeObject(root, depth));
        while (queue.Count > 0)
        {
            TreeNodeObject current = queue.Dequeue();
            if (current.node.left != null)
                queue.Enqueue(new TreeNodeObject(current.node.left, current.depth + 1));
            if (current.node.right != null)
                queue.Enqueue(new TreeNodeObject(current.node.right, current.depth + 1));
            if (list.Count <= current.depth)
            {
                list.Add(new List<int>());
            }
            list[current.depth].Add(current.node.val);
        }
        return list;
    }
}