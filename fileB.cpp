enum Color {
    RED,
    BLACK
}

class Node {
    int data;
    Color color;
    Node left, right, parent;

    Node(int data) {
        this.data = data;
        this.color = Color.RED;
        this.left = null;
        this.right = null;
        this.parent = null;
    }
}

public class RedBlackTree {
    private Node root;
    private final Node NIL;

    public RedBlackTree() {
        NIL = new Node(0);
        NIL.color = Color.BLACK;
        root = NIL;
    }

    // 🔍 In-order traversal
    public void inOrder(Node node) {
        if (node != NIL) {
            inOrder(node.left);
            System.out.print(node.data + "(" + node.color + ") ");
            inOrder(node.right);
        }
    }

    public void display() {
        inOrder(root);
        System.out.println();
    }

    // 🔄 Left rotate
    private void leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;

        if (y.left != NIL) y.left.parent = x;
        y.parent = x.parent;

        if (x.parent == null) this.root = y;
        else if (x == x.parent.left) x.parent.left = y;
        else x.parent.right = y;

        y.left = x;
        x.parent = y;
    }

    // 🔁 Right rotate
    private void rightRotate(Node x) {
        Node y = x.left;
        x.left = y.right;

        if (y.right != NIL) y.right.parent = x;
        y.parent = x.parent;

        if (x.parent == null) this.root = y;
        else if (x == x.parent.right) x.parent.right = y;
        else x.parent.left = y;

        y.right = x;
        x.parent = y;
    }

    // ✅ Fix tree after insert
    private void fixInsert(Node k) {
        Node u;
        while (k.parent.color == Color.RED) {
            if (k.parent == k.parent.parent.right) {
                u = k.parent.parent.left;
                if (u.color == Color.RED) {
                    u.color = Color.BLACK;
                    k.parent.color = Color.BLACK;
                    k.parent.parent.color = Color.RED;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.left) {
                        k = k.parent;
                        rightRotate(k);
                    }
                    k.parent.color = Color.BLACK;
                    k.parent.parent.color = Color.RED;
                    leftRotate(k.parent.parent);
                }
            } else {
                u = k.parent.parent.right;

                if (u.color == Color.RED) {
                    u.color = Color.BLACK;
                    k.parent.color = Color.BLACK;
                    k.parent.parent.color = Color.RED;
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.right) {
                        k = k.parent;
                        leftRotate(k);
                    }
                    k.parent.color = Color.BLACK;
                    k.parent.parent.color = Color.RED;
                    rightRotate(k.parent.parent);
                }
            }
            if (k == root) break;
        }
        root.color = Color.BLACK;
    }

    // ➕ Insert node
    public void insert(int key) {
        Node node = new Node(key);
        node.parent = null;
        node.left = NIL;
        node.right = NIL;
        node.color = Color.RED;

        Node y = null;
        Node x = this.root;

        while (x != NIL) {
            y = x;
            if (node.data < x.data) x = x.left;
            else x = x.right;
        }

        node.parent = y;
        if (y == null) root = node;
        else if (node.data < y.data) y.left = node;
        else y.right = node;

        if (node.parent == null) {
            node.color = Color.BLACK;
            return;
        }

        if (node.parent.parent == null) return;

        fixInsert(node);
    }

    // 🔍 Search for a node
    public Node search(int key) {
        return searchTreeHelper(this.root, key);
    }

    private Node searchTreeHelper(Node node, int key) {
        if (node == NIL || key == node.data) return node;
        if (key < node.data) return searchTreeHelper(node.left, key);
        return searchTreeHelper(node.right, key);
    }

    // 🚮 Transplant helper
    private void transplant(Node u, Node v) {
        if (u.parent == null) root = v;
        else if (u == u.parent.left) u.parent.left = v;
        else u.parent.right = v;
        v.parent = u.parent;
    }

    // 🛠️ Fix tree after delete
    private void fixDelete(Node x) {
        Node s;
        while (x != root && x.color == Color.BLACK) {
            if (x == x.parent.left) {
                s = x.parent.right;
                if (s.color == Color.RED) {
                    s.color = Color.BLACK;
                    x.parent.color = Color.RED;
                    leftRotate(x.parent);
                    s = x.parent.right;
                }

                if (s.left.color == Color.BLACK && s.right.color == Color.BLACK) {
                    s.color = Color.RED;
                    x = x.parent;
                } else {
                    if (s.right.color == Color.BLACK) {
                        s.left.color = Color.BLACK;
                        s.color = Color.RED;
                        rightRotate(s);
                        s = x.parent.right;
                    }
                    s.color = x.parent.color;
                    x.parent.color = Color.BLACK;
                    s.right.color = Color.BLACK;
                    leftRotate(x.parent);
                    x = root;
                }
            } else {
                s = x.parent.left;
                if (s.color == Color.RED) {
                    s.color = Color.BLACK;
                    x.parent.color = Color.RED;
                    rightRotate(x.parent);
                    s = x.parent.left;
                }

                if (s.left.color == Color.BLACK && s.right.color == Color.BLACK) {
                    s.color = Color.RED;
                    x = x.parent;
                } else {
                    if (s.left.color == Color.BLACK) {
                        s.right.color = Color.BLACK;
                        s.color = Color.RED;
                        leftRotate(s);
                        s = x.parent.left;
                    }
                    s.color = x.parent.color;
                    x.parent.color = Color.BLACK;
                    s.left.color = Color.BLACK;
                    rightRotate(x.parent);
                    x = root;
                }
            }
        }
        x.color = Color.BLACK;
    }

    // ❌ Delete a node
    public void delete(int key) {
        deleteNodeHelper(this.root, key);
    }

    private void deleteNodeHelper(Node node, int key) {
        Node z = NIL, x, y;
        while (node != NIL) {
            if (node.data == key) z = node;
            if (node.data <= key) node = node.right;
            else node = node.left;
        }

        if (z == NIL) {
            System.out.println("Key not found!");
            return;
        }

        y = z;
        Color yOriginalColor = y.color;
        if (z.left == NIL) {
            x = z.right;
            transplant(z, z.right);
        } else if (z.right == NIL) {
            x = z.left;
            transplant(z, z.left);
        } else {
            y = minimum(z.right);
            yOriginalColor = y.color;
            x = y.right;

            if (y.parent == z) {
                x.parent = y;
            } else {
                transplant(y, y.right);
                y.right = z.right;
                y.right.parent = y;
            }

            transplant(z, y);
            y.left = z.left;
            y.left.parent = y;
            y.color = z.color;
        }

        if (yOriginalColor == Color.BLACK) {
            fixDelete(x);
        }
    }

    // 📉 Find minimum
    private Node minimum(Node node) {
        while (node.left != NIL) node = node.left;
        return node;
    }

    public static void main(String[] args) {
        RedBlackTree tree = new RedBlackTree();

        int[] nums = {20, 15, 25, 10, 5, 1, 30, 28, 40};
        for (int n : nums) tree.insert(n);

        System.out.println("Red-Black Tree In-order:");
        tree.display();

        System.out.println("Deleting 25 and 10...");
        tree.delete(25);
        tree.delete(10);
        tree.display();
    }
}
