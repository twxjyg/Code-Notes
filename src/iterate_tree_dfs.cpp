#include <memory>
#include <vector>
#include <deque>
#include <iostream>

template <class T>
struct Node
{
    Node(T data) : data{data} {}
    T data;
    std::vector<std::shared_ptr<Node<T>>> childs;
};

std::shared_ptr<Node<int>> BuildANode(int data)
{
    return std::make_shared<Node<int>>(data);
}
std::shared_ptr<Node<int>> BuildATree()
{
    std::shared_ptr<Node<int>> root = BuildANode(0);
    root->childs.push_back(BuildANode(1));
    root->childs.push_back(BuildANode(2));
    root->childs.push_back(BuildANode(3));

    root->childs[2]->childs.push_back(BuildANode(11));
    root->childs[2]->childs.push_back(BuildANode(12));

    root->childs[1]->childs.push_back(BuildANode(121));
    root->childs[1]->childs.push_back(BuildANode(122));

    root->childs[1]->childs[1]->childs.push_back(BuildANode(22));
    root->childs[1]->childs[1]->childs.push_back(BuildANode(21));
    root->childs[1]->childs[1]->childs.push_back(BuildANode(22));
    return root;
}
int main(int argc, char *argv[])
{
    auto tree = BuildATree();
    std::vector<std::shared_ptr<Node<int>>> left;
    std::vector<std::shared_ptr<Node<int>>> curr_path;
    auto iter = tree;
    curr_path.push_back(iter);
    while (true)
    {
        if (!iter->childs.empty())
        {
            curr_path.push_back(iter->childs.front());
            if (iter->childs.size() > 1)
            {
                left.insert(left.end(), iter->childs.begin() + 1, iter->childs.end());
            }
            iter = iter->childs.front();
        }
        else
        {
            // std::cout << "current path:" << std::endl;
            for (auto point : curr_path)
            {
                std::cout << point->data << "->";
            }
            std::cout << "*" << std::endl;
            std::cout << std::endl;
            // std::cout << "current left:" << std::endl;
            // for (auto point : left)
            // {
            //     std::cout << point->data << ",";
            // }
            // std::cout << std::endl;
            bool has = false;
            while (!has)
            {
                curr_path.pop_back();
                if (!curr_path.empty())
                {
                    for (auto point : curr_path.back()->childs)
                    {
                        if (!left.empty() && point == left.back())
                        {
                            curr_path.push_back(left.back());
                            iter = left.back();
                            left.pop_back();
                            has = true;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (left.empty() && curr_path.empty())
        {
            break;
        }
    }
    return 0;
}