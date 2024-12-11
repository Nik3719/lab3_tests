#include "Tree.h"

Tree::Tree() : root(nullptr)
{
}
Tree::~Tree()
{
    Allocation(root);
}

void Tree::Allocation(TreeNode *node)
{
    if (node != nullptr)
    {
        Allocation(node->left);
        Allocation(node->right);
        delete node;
        node = nullptr;
    }
}

TreeNode *Tree::downTree(TreeNode *node, int value)
{
    if (node == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < node->data)
    {
        node->left = downTree(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = downTree(node->right, value);
    }
    return node;
}

void Tree::TINSERT(int elem)
{
    root = downTree(root, elem);
}

bool Tree::TSEARCH(int elem)
{
    return RightOrLeft(root, elem) != nullptr;
}

TreeNode *Tree::RightOrLeft(TreeNode *node, int &value)
{
    if (node == nullptr || node->data == value)
    {
        return node;
    }
    if (value < node->data)
    {
        return RightOrLeft(node->left, value);
    }
    else
    {
        return RightOrLeft(node->right, value);
    }
}

bool Tree::isComplete(TreeNode *node, int index, int numberNodes)
{
    if (node == nullptr)
    {
        return true;
    }
    if (index >= numberNodes)
    {
        return false;
    }
    return isComplete(node->left, 2 * index + 1, numberNodes) && isComplete(node->right, 2 * index + 2, numberNodes);
    // ����� �������� ����                                         ������ �������� ����
}
int Tree::countNodes(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}
bool Tree::TISCOMPLETE()
{
    int nodeCount = countNodes(root);
    return isComplete(root, 0, nodeCount);
}

int Tree::unsafeHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftHeight = unsafeHeight(node->left);
    int rightHeight = unsafeHeight(node->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

void Tree::unsafePrint(TreeNode *root, int space)
{
    if (!root)
    {
        return;
    }
    space += 2;
    unsafePrint(root->right, space);
    for (int i = 2; i < space; ++i)
        cout << "  ";
    cout << root->data << endl;
    unsafePrint(root->left, space);
}

DL<DL<int>> Tree::getLevels()
{
    DL<DL<int>> levels;
    int h = unsafeHeight(root);
    for (int i = 1; i <= h; i++)
    {
        DL<int> levelValues;
        LoadLevel(root, i, levelValues);
        levels.LDPUSHT(levelValues);
    }
    return levels;
}

void Tree::LoadLevel(TreeNode *node, int level, DL<int> &levelValues)
{
    if (node == nullptr)
    {
        return;
    }
    if (level == 1)
    {
        levelValues.LDPUSHT(node->data);
    }
    else if (level > 1)
    {
        LoadLevel(node->left, level - 1, levelValues);
        LoadLevel(node->right, level - 1, levelValues);
    }
}

void Tree::serialize(const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        function<void(TreeNode *)> serializeNode = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                int nullFlag = -1; // Отметка о пустом узле
                out.write(reinterpret_cast<const char *>(&nullFlag), sizeof(int));
                return;
            }
            out.write(reinterpret_cast<const char *>(&node->data), sizeof(int)); // Записываем данные узла
            serializeNode(node->left);                                           // Рекурсивно записываем левое поддерево
            serializeNode(node->right);                                          // Рекурсивно записываем правое поддерево
        };
        serializeNode(root); // Начинаем с корня дерева
        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации дерева
void Tree::deserialize(const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        function<TreeNode *(void)> deserializeNode = [&]()
        {
            int value;
            in.read(reinterpret_cast<char *>(&value), sizeof(int));
            if (value == -1)
                return static_cast<TreeNode *>(nullptr); // Если встретили отметку пустого узла
            TreeNode *node = new TreeNode(value);
            node->left = deserializeNode();  // Рекурсивно восстанавливаем левое поддерево
            node->right = deserializeNode(); // Рекурсивно восстанавливаем правое поддерево
            return node;
        };
        root = deserializeNode(); // Восстанавливаем дерево, начиная с корня
        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}